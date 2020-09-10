#pragma once

#include <QWidget>
#include <QTimer>
#include <QGuiApplication>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QStackedLayout>

#include "qt/qt_sound.hpp"
#include "ui/ui.hpp"

class MainWindow : public QWidget
{
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = 0);

private:
  QStackedLayout *main_layout;

public slots:
  void openSettings();
  void closeSettings();

};


class GLWindow : public QOpenGLWidget, protected QOpenGLFunctions
{
  Q_OBJECT

public:
  using QOpenGLWidget::QOpenGLWidget;
  explicit GLWindow(QWidget *parent = 0);
  ~GLWindow();

protected:
  void mousePressEvent(QMouseEvent *e) override;
  void initializeGL() override;
  void resizeGL(int w, int h) override;
  void paintGL() override;


private:
  QTimer * timer;
  UIState * ui_state;
  QtSound sound;
  float brightness_b = 0;
  float brightness_m = 0;
  float smooth_brightness = 0;

public slots:
  void timerUpdate();

signals:
  void openSettings();
};
