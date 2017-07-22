#include<GL/glut.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<unistd.h>
int a=0,b=0,c=0;
int i,j,first;
int mov=0;
GLfloat a1=0,b1=0,c1=0,d1=0,e1=0;
int flag=0,manFlag=0,checkFlag=0,opFlag=0,showFlag=0;
int mnx[5],mny[5];
int k,k1,kh,kx,ky;
void fall_star();
void drawText( float x, float y, int r, int g, int b, const char *string );
void options();
void generateMan();
void plane();
void check()
{
	if(640+ky<115)
		{if(360+kh+c>(140+a) && 360+kh+c<(230+a))
			{opFlag=1;
			checkFlag=1;}
		else
		{	opFlag=2;
			checkFlag=1;}
		}

}

void reshape(int w,int h)
{
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0,w,0,h,1,-1);
	glMatrixMode(GL_MODELVIEW);

}
void
keyboard(unsigned char key, int x, int y)
{


	if(key=='w'||key=='W')
		fall_star();
	if(key=='t' || key=='T')
		{
		if(flag==0)
		flag=1;
		else
		flag=0;
		glutPostRedisplay();
		}
	if(key=='s' || key=='S')
	{
		if(!showFlag)
		showFlag=1;
		else
		showFlag=0;
		glutPostRedisplay();
	}
	if(key=='4')
	{
	if(!manFlag)
	{c-=50;
	plane();
	glutPostRedisplay();}
}
	if(key=='6')
	{
	if(!manFlag)
	{c+=50;
	plane();
	glutPostRedisplay();}
	}
	if(key=='2')
	{


    if(manFlag==0)
		{
			plane();
		
		generateMan();
	  }
        manFlag=1;
	 ky-=5;
	glutPostRedisplay();



	}
	if(key=='1')
	{

		kh-=8;
		ky-=5;
	glutPostRedisplay();

	}
	if(key=='3')
	{
		 ky-=5;
		kh+=8;

	glutPostRedisplay();

	}
	if(key=='5')
	{
	glutPostRedisplay();
	}


    switch (key) {
    case 'q': exit(0);
    }
}



void lines()
{
glColor3f(0.0,1.0,1.0);
glBegin(GL_LINES);

	glVertex2f(30.0,100.0);//1st line
	glVertex2f(210.0,100.0);

	glVertex2f(500.0,100.0);
	glVertex2f(700.0,100.0);

	glVertex2f(270.0,100.0);
	glVertex2f(430.0,100.0);

	glVertex2f(800.0,100.0);
	glVertex2f(1100.0,100.0);

	glVertex2f(170.0,75.0);//2nd line
	glVertex2f(300.0,75.0);

	glVertex2f(375.0,75.0);
	glVertex2f(520.0,75.0);

	glVertex2f(590.0,75.0);
	glVertex2f(800.0,75.0);

	glVertex2f(170.0,75.0);
	glVertex2f(300.0,75.0);

	glVertex2f(850.0,75.0);
	glVertex2f(1050.0,75.0);

	glVertex2f(875.0,75.0);
	glVertex2f(1050.0,75.0);



	glVertex2f(75.0,50.0);//3rd line
	glVertex2f(200.0,50.0);

	glVertex2f(300.0,50.0);
	glVertex2f(415.0,50.0);

	glVertex2f(500.0,50.0);
	glVertex2f(650.0,50.0);

	glVertex2f(975.0,50.0);
	glVertex2f(1200.0,50.0);

	glVertex2f(700.0,50.0);
	glVertex2f(900.0,50.0);




	glVertex2f(15.0,25.0);//4th line
	glVertex2f(115.0,25.0);

	glVertex2f(190.0,25.0);
	glVertex2f(320.0,25.0);

	glVertex2f(405.0,25.0);
	glVertex2f(520.0,25.0);

	glVertex2f(650.0,25.0);
	glVertex2f(730.0,25.0);

	glVertex2f(775.0,25.0);
	glVertex2f(835.0,25.0);

	glVertex2f(870.0,25.0);
	glVertex2f(1000.0,25.0);



	glEnd();
}

void star()
{
  glPushMatrix();
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);//star1

	glVertex2i(495,660);
	glVertex2i(500,650);
	glVertex2i(505,660);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2i(495,655);
	glVertex2i(505,655);
	glVertex2i(500,665);
	glEnd();

	glBegin(GL_POLYGON);//star2
	glVertex2i(75,460);
	glVertex2i(80,450);
	glVertex2i(85,460);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2i(75,455);
	glVertex2i(85,455);
	glVertex2i(80,465);
	glEnd();


	glBegin(GL_POLYGON);//star3

	glVertex2i(615,630);
	glVertex2i(620,620);
	glVertex2i(625,630);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2i(615,625);
	glVertex2i(625,625);
	glVertex2i(620,635);
	glEnd();
	glBegin(GL_POLYGON);



	glVertex2i(245,660);//star4
	glVertex2i(250,650);
	glVertex2i(255,660);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2i(245,655);
	glVertex2i(255,655);
	glVertex2i(250,665);
	glEnd();
	glBegin(GL_POLYGON);//star5

	glVertex2i(945,590+b);
	glVertex2i(950,580+b);
	glVertex2i(955,590+b);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2i(945,585+b);
	glVertex2i(955,585+b);
	glVertex2i(950,595+b);
	glEnd();

	glBegin(GL_POLYGON);//star6

	glVertex2i(1195,490);
	glVertex2i(1200,480);
	glVertex2i(1205,490);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2i(1195,485);
	glVertex2i(1205,485);
	glVertex2i(1200,495);
	glEnd();

	glBegin(GL_POLYGON);//star7
	glVertex2i(675,660);
	glVertex2i(680,650);
	glVertex2i(685,660);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2i(675,655);
	glVertex2i(685,655);
	glVertex2i(680,665);
	glEnd();
	glPopMatrix();


}

void display1(void)
{

glClearColor(0.5,0.02,0.9,0.9);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

	drawText(550,600,1,1,1,"PROJECT TITLE:");
	drawText(525,560,1,1,0,"\"PARACHUTE JUMP\"");
	drawText(570,520,1,1,1,"Developed By:");
	drawText(340,480,0,1,0,"SRIRAM.A.D");
	drawText(335,440,1,1,1,"(1BY14CS075)");
	drawText(800,480,0,1,0," TUSHAR SINHA ");
	drawText(825,440,1,1,1,"(1BY14CS083)");
	drawText(490.0,400.0,1,1,1,"UNDER THE GUIDANCE OF");
	drawText(450.0,360.0,0,1,1,"Dr.ANIL GN                		 MR.ANAND R");
	drawText(425.0,320.0,0,1,1,"Associate professor            Assistant professor");
	drawText(580.0,280.0,1,1,0,"Dept. of CSE");
	drawText(585.0,240,1,1,0,"BMSIT&M");
	drawText(1030,120,0,1,0,"Press C to continue  ");
	glFlush();
}

void keyboard1(unsigned char key,int x,int y)
{
if(key=='c'||key=='C')
{
	glutDestroyWindow(first);

	options();
}

}

void drawCircle(float x1,float y1,double radius,float r,float g,float b)
	{
	float x2,y2;
	float angle;
 	glColor3f(r,g,b);

	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(x1,y1);

	for (angle=1.0f;angle<361.0f;angle+=0.2)
	{
    	x2 = x1+sin(angle)*radius;
    	y2 = y1+cos(angle)*radius;
    	glVertex2f(x2,y2);

	}
	glEnd();
 }
void plane(void)
{
glPushMatrix();
glTranslatef(c,0,0);
glColor3f(1.0,1.0,1.0);
glBegin(GL_POLYGON);//rectangular body
glVertex2f(300.0,630.0);
glVertex2f(300.0,655.0);
glVertex2f(435.0,655.0);
glVertex2f(435.0,630.0);
if(manFlag==0)
mnx[k]=360; mny[k]=640;//man initial position

glColor3f(1.0,1.0,1.0);
glBegin(GL_POLYGON);//upper triangle construction plane
glVertex2f(435.0,655.0);
glVertex2f(450.0,650.0);
glVertex2f(455.0,645.0);
glVertex2f(460.0,640.0);
glVertex2f(435.0,640.0);
glEnd();

glColor3f(0.0,0.0,0.0);
glBegin(GL_LINE_LOOP);//outline of upper triangle plane
glVertex2f(435.0,655.0);
glVertex2f(450.0,650.0);
glVertex2f(455.0,645.0);
glVertex2f(460.0,640.0);
glVertex2f(435.0,640.0);
glEnd();

glColor3f(1.0,0.0,0.0);
glBegin(GL_POLYGON);//lower triangle
glVertex2f(435.0,640.0);
glVertex2f(460.0,640.0);
glVertex2f(460.0,637.0);
glVertex2f(445.0,630.0);
glVertex2f(435.0,630.0);
glEnd();

glColor3f(1.0,0.0,0.0);
glBegin(GL_POLYGON);//back wing
glVertex2f(300.0,655.0);
glVertex2f(300.0,680.0);
glVertex2f(310.0,680.0);
glVertex2f(340.0,655.0);
glEnd();

glColor3f(1.0,0.0,0.0);
glBegin(GL_POLYGON);//left side wing
glVertex2f(365.0,655.0);
glVertex2f(350.0,670.0);
glVertex2f(375.0,670.0);
glVertex2f(390.0,655.0);
glEnd();

glColor3f(1.0,0.0,0.0);
glBegin(GL_POLYGON);//rightside wing
glVertex2f(370.0,640.0);
glVertex2f(400.0,640.0);
glVertex2f(380.0,615.0);
glVertex2f(350.0,615.0);
glEnd();



if(manFlag==1)
{
generateMan();
}
glPopMatrix();

}
void trees()
	{
	glPushMatrix();
	for(int i=0;i<=1500;i=i+100)
	{
	glBegin(GL_POLYGON);
	if(flag==1)
	glColor3f(0.72,0.52,0.04);
	else
	glColor3f(0.54,0.27,0.07);

	glVertex2i(30+i,115);
	glVertex2i(30+i,150);
	glVertex2i(40+i,150);
	glVertex2i(40+i,115);
	glEnd();

	glBegin(GL_POLYGON);
	if(flag==1)
	glColor3f(0.5,1,0);
	else
	glColor3f(0,0.39,0.0);

	glVertex2i(20+i,140);
	glVertex2i(12.5+i,175);
	glVertex2i(37.5+i,200);
	glVertex2i(62.5+i,175);
	glVertex2i(55+i,140);
	glEnd();
	}
	glPopMatrix();
	}

	void hill()
	{
	glPushMatrix();
	for(j=-600;j<1300;j=j+650)
	{
	glBegin(GL_POLYGON);//Hill
	if(flag==1)
	glColor3f(0.8,0.6,0.11);
	else
	glColor3f(0.71,0.52,0.04);

	glVertex2i(0+j,115);
	glVertex2i(400+j,375);
	glVertex2i(600+j,375);
	glVertex2i(1000+j,115);
	glEnd();
	if(flag==1)
	drawCircle(500+j,282,136,0.8,0.6,0.11);
	else
	drawCircle(500+j,282,136,0.71,0.52,0.04);

	}
	glPopMatrix();
	}
void drawText( float x, float y, int r, int g, int b, const char *string )
{
	int j = strlen( string );

	glColor3f( r, g, b );
	glRasterPos2f( x, y );
	for( int i = 0; i < j; i++ ) {
		glutBitmapCharacter( GLUT_BITMAP_TIMES_ROMAN_24, string[i] );
	}
}
void boat()
	{
	glPushMatrix();
	glTranslatef(a,0,0);
	glBegin(GL_POLYGON);//base of boat
	glColor3f(0.4,0.2,0.2);
	glVertex2i(150,100);//Base of boat
	glVertex2i(300,100);
	glVertex2i(350,160);//up line
	glVertex2i(100,160);
	glEnd();
	glBegin(GL_POLYGON);//catcher base
	glColor3f(1.0,0.0,0.0);
	glVertex2i(140,160);
	glVertex2i(140,170);
	glVertex2i(230,170);
	glVertex2i(230,160);
	glEnd();

	glBegin(GL_POLYGON);//w1
	glColor3f(0.95,0.95,0.95);
	glVertex2i(150,125);
	glVertex2i(150,150);
	glVertex2i(175,150);
	glVertex2i(175,125);
	glEnd();

	glBegin(GL_POLYGON);//w2
	glColor3f(0.95,0.95,0.95);
	glVertex2i(200,125);
	glVertex2i(200,150);
	glVertex2i(225,150);
	glVertex2i(225,125);
	glEnd();

	glBegin(GL_POLYGON);//w3
	glColor3f(0.95,0.95,0.95);
	glVertex2i(250,125);
	glVertex2i(250,150);
	glVertex2i(275,150);
	glVertex2i(275,125);
	glEnd();

	glBegin(GL_POLYGON);//catcherL
	glColor3f(1,0.84,0.0);
	glVertex2i(140,170);
	glVertex2i(140,190);
	glVertex2i(185,170);

	glEnd();
	glBegin(GL_POLYGON);//catcherR
	glColor3f(1,0.84,0);
	glVertex2i(185,170);
	glVertex2i(230,190);
	glVertex2i(230,170);
	glEnd();


	glBegin(GL_POLYGON);//chimneyDown
	glColor3f(1,0.18,0.18);
	glVertex2i(275,160);
	glVertex2i(275,200);
	glVertex2i(335,200);
	glVertex2i(335,160);
	glEnd();

	glBegin(GL_POLYGON);//chimneyUP
	glColor3f(0,0,0);
	glVertex2i(285,200);
	glVertex2i(285,235);
	glVertex2i(325,235);
	glVertex2i(325,200);
	glEnd();

	glPopMatrix();

	}
void display(void)
{

	if(flag==0)
	glClearColor(0.09,0.09,0.43,0);
	else
	glClearColor(0,0.74,1,0);
	glClear(GL_COLOR_BUFFER_BIT);



	if(flag==1)
	{
	glPushMatrix();
	glBegin(GL_POLYGON);//bird1
	glColor3f(0,0.0,0.0);
	glVertex2i(770,500);
	glVertex2i(767.5,525);
	glVertex2i(750,550);
	glVertex2i(775,515);
	glVertex2i(812.5,535);
	glVertex2i(787.5,525);
	glVertex2i(770,500);
	glEnd();
	glPopMatrix();
	glPushMatrix();
	glBegin(GL_POLYGON);//bird2
	glColor3f(0,0.0,0.0);
	glVertex2i(870,550);
	glVertex2i(867.5,575);
	glVertex2i(850,600);
	glVertex2i(875,565);
	glVertex2i(900,587.5);
	glVertex2i(912.5,585);
	glVertex2i(887.5,575);
	glVertex2i(870,550);
	glEnd();
	glPopMatrix();
	}
	hill();
	trees();
	if(flag==0)
	star();
	if(flag==0)
	drawCircle(1000,500,50,1,1,0.6);//moon
	else
	drawCircle(700,600,50,1,0.49,0);//sun
	
	glPushMatrix();	
	glTranslated(mov*0.05,0.0,0.0);
	drawCircle(370,550,40,0.96,0.96,0.96);//cloud1
	drawCircle(430,550,50,0.96,0.96,0.96);
	drawCircle(490,550,40,0.96,0.96,0.96);
	mov++;glutPostRedisplay();
	glPopMatrix();
	if(flag==0){
	glPushMatrix();
	glTranslated(0.04*mov,0.0,0.0);
	drawCircle(830,500,40,0.96,0.96,0.96);//cloud21
	drawCircle(890,500,50,0.96,0.96,0.96);
	drawCircle(950,500,40,0.96,0.96,0.96);
	glutPostRedisplay();
	glPopMatrix();
	glPushMatrix();
	glTranslated(-0.13*mov,0.0,0.0);
	drawCircle(1030,600,40,0.96,0.96,0.96);//cloud3
	drawCircle(1090,600,50,0.96,0.96,0.96);
	drawCircle(1140,600,40,0.96,0.96,0.96);
	glutPostRedisplay();
	glPopMatrix();
	}
	if(flag==1)
	plane();//plane

	glBegin(GL_POLYGON);// Water
        if(flag==0)
        glColor3f(0.52,0.8,0.92);
	else
	glColor3f(0.38,0.71,1);
	glVertex2i(0,0);
	glVertex2i(1600,0);
	glVertex2i(1600,115);
	glVertex2i(0,115);
	glEnd();

	boat();
	if(!flag && !showFlag){
	drawText(50,700,1.0,0.0,0.0,"Airplane -> Left-4  Right-6 ");
	drawText(50,650,1.0,0.0,0.0,"Jump - 2 ");
	drawText(50,600,1.0,0.0,0.0,"1 & 3 for Wind");
	drawText(50,550,1.0,0.0,0.0,"Boat Left  -LMB");
	drawText(50,500,1.0,0.0,0.0,"Boat Right -RMB");
	drawText(50,450,1.0,0.0,0.0,"Press T to play");
}
	if(!checkFlag)
	check();

	glColor3f(1.0,1.0,1.0);
	if(opFlag!=0 && flag==1)
	{
	glBegin(GL_POLYGON);
	glVertex2i(1300,460);
	glVertex2i(1300,560);
	glVertex2i(1000,560);
	glVertex2i(1000,460);
	glEnd();
	if(opFlag==1)
	drawText(1050,500,1.0,0.0,0.0,"Perfect Landing!");
	else
	drawText(1050,500,1.0,0.0,0.0,"Shaky Landing!");



}


	lines();

	glFlush();
}

void fall_star()
{
 b-=2;
 glutPostRedisplay();
}

void generateMan()
{
	//glPushMatrix();
       
	glPushMatrix();
	if(manFlag==0)
		{glTranslatef(c,ky,0);
		}
	else
	{

	glTranslatef(kh,ky,0);
 	}
	glBegin(GL_LINES);//parachuteLine
	glColor3f(0,0,1);
	glLineWidth(4);
	glVertex2i(mnx[k],mny[k]);
	glVertex2i(mnx[k],mny[k]+40);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(1,0,0);
	glVertex2i(mnx[k],mny[k]);//spine
	glVertex2i(mnx[k],mny[k]-30);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(1,0,0);
	glVertex2i(mnx[k],mny[k]-10);//leftHand
	glVertex2i(mnx[k]-5,mny[k]-15);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(1,0,0);
	glVertex2i(mnx[k],mny[k]-10);//RightHand
	glVertex2i(mnx[k]+5,mny[k]-15);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(1,0,0);
	glVertex2i(mnx[k],mny[k]-30);//LeftLeg
	glVertex2i(mnx[k]-5,mny[k]-38);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(1,0,0);
	glVertex2i(mnx[k],mny[k]-30);//RightLeg
	glVertex2i(mnx[k]+5,mny[k]-38);
	glEnd();

	drawCircle(mnx[k],mny[k],8,1,0,0);
	drawCircle(mnx[k],mny[k]+40,18,1,1,0);
	drawCircle(mnx[k],mny[k]+40,12,1,1,1);

	glBegin(GL_POLYGON);//parachute
	glVertex2f(mnx[k]-8,mny[k]+40);
	glVertex2f(mnx[k]+8,mny[k]+40);
	glVertex2f(mnx[k],mny[k]+40-30);
	glEnd();


	glPopMatrix();
}
void mymouse(int btn,int state,int x,int y)
{
	if(btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN){if(a>=0)
		a-=50;
		boat();
		glutPostRedisplay();
		}
	if(btn==GLUT_MIDDLE_BUTTON && state==GLUT_DOWN)
     glutIdleFunc(fall_star);
	if(btn==GLUT_RIGHT_BUTTON && state==GLUT_DOWN){if(a<=800)
		a+=50;
		boat();
		glutPostRedisplay();
		}
	glutPostRedisplay();
}
void options()
{

	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(1200,500);
	glutInitWindowPosition(0,0);
	glutCreateWindow("MY BOAT");
	glutFullScreen();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMouseFunc(mymouse);
  glutKeyboardFunc(keyboard);
  glutMainLoop();

}



int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(1250,500);
	glutInitWindowPosition(0,0);
	first=glutCreateWindow("MY INTRO");
	glutFullScreen();
	glutDisplayFunc(display1);
	glutReshapeFunc(reshape);
	glutMouseFunc(mymouse);
  	glutKeyboardFunc(keyboard1);
  	glutMainLoop();
	return 0;
}
