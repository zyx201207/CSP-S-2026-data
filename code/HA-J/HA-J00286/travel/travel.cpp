#include<bits/stdc++.h>
using namespace std;
int gd(int a,int b){
	bool ff=0,ff1=0;
	if(a<=3) ff=1;
	if(b<=3) ff1=1;
	if(ff=ff1) return 1;
	else return 0; 
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string cx1,cx2,zc1,zc2;
	cin>>cx1>>zc1>>cx2>>zc2;
	bool f1=0,f2=0,f3=0,f4=0;
	int x1,x2,y1,y2,z1,z2;
	x1=(cx1[0]-'0')*10+(cx1[1]-'0');
	x2=(cx2[0]-'0')*10+(cx2[1]-'0');
	y1=(zc1[0]-'0')*10+(zc1[1]-'0');
	y2=(zc2[0]-'0')*10+(zc2[1]-'0');
	z1=(zc1[2]-'A'+1);
	z2=(zc2[2]-'A'+1);
	if(x1==x2) f1=1;
	if(x1==x2&&y1==y2) f2=1;
	if(x1==x2&&y1==y2&&gd(z1,z2)==1) f3=1;
	if(x1==x2&&y1==y2&&gd(z1,z2)==1){
		if((z1+1)==z2||(z1-1)==z2||(z2-1)==z1||(z2+1)==z1) f4=1;
	}
	cout<<f1<<f2<<f3<<f4; 
	return 0;
}
