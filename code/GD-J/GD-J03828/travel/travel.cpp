#include<bits/stdc++.h>
using namespace std;
string cy,cx,sy,sx;
int x,y,a,b,c;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cx>>sx>>cy>>sy;
	if(cx==cy){
		a=1;
		cout<<"1";
	}else{
		cout<<"0";
	}
	if(a==1&&sx[0]==sy[0]&&sx[1]==sy[1]){
		b=1;
		cout<<"1";
	}else{
		cout<<"0";
	}
	if(sx[2]<='C')x=1;
	if(sy[2]<='C')y=1;
	if(x==y&&a==1&&b==1){
		c=1;
		cout<<"1";
	}else{
		cout<<"0";
	}
	if((int(sx[2])-int(sy[2])==1||int(sy[2])-int(sx[2])==1)&&a==1&&b==1&&c==1){
		cout<<"1";
	}else{
		cout<<"0";
	}
	return 0;
}
