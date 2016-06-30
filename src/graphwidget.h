// Copyright (c) 2005-2016 Gzp
// Distributed under MIT License.

#ifndef GRAPHWIDGET_H
#define GRAPHWIDGET_H

#include <QGraphicsView>

class SceneManager;
class QTimer;
class QPixmap;

class GraphWidget : public QGraphicsView
{
    Q_OBJECT

public:
    enum {
        BackBlack,
        BackWhite,
        BackGlobe,
        BackGradient,

        BackInvalid,
    };

    GraphWidget(QWidget *parent = 0);
    virtual ~GraphWidget();

    void    setSceneManager( SceneManager* aSceneManager );

public slots:
    void setHighQuality( bool aEnable );
    void setBackground( int aType );
    void clear();
    void zoomIn();
    void zoomOut();
    void zoomFit();
    void setAutoFit( bool aFit );
    void updateCommands();

signals:
    void onAutoFitChanged( bool aFit );
    void onBackgroundChanged( int aValue );
    void onHighQualityChanged( bool aEnable );

protected:
    void keyPressEvent(QKeyEvent* aEvent) Q_DECL_OVERRIDE;
#ifndef QT_NO_WHEELEVENT
    void wheelEvent(QWheelEvent* aEvent) Q_DECL_OVERRIDE;
#endif    
    void mousePressEvent(QMouseEvent* aEvent) Q_DECL_OVERRIDE;
    void drawBackground( QPainter* aPainter, const QRectF& aRect ) Q_DECL_OVERRIDE;


    void zoom(qreal scaleFactor);
    void releaseBackground();

private:
    SceneManager*   mSceneManager;
    QTimer*         mTimer;

    QPixmap*        mBackground;
    int             mBackgroundType;
    QColor          mBackgroundBorder;
    QColor          mBackgroundColor;    

    bool            mAutoFit;
    bool            mHighQuality;
};

#endif // GRAPHWIDGET_H
