#include <iostream>
#include <cstring>
using namespace std;
string rc,rz,xc,xz,rp,xp;
char rh,xh;
int rx,xx;
bool gd(char a,char b){
	if(a=='D'||a=='F'){
		return b=='D'||b=='F';
	}
	return b=='A'||b=='B'||b=='C';
}
bool xl(int a,char x,int b,char y){
	if(y==x||y==x+1||y==x-1){
		if(a==b||a==b+1||a==b-1){
			return true;
		}
	}
	return false;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>rc>>rz>>xc>>xz;
	if(rc!=xc){
		cout<<"0000";
		return 0;
	}
	cout<<"1";
	rh=rz[2];
	xh=xz[2];
	rp=rz.substr(0,2);
	xp=xz.substr(0,2);
	if(rp!=xp){
		cout<<"000";
		return 0;
	}
	cout<<"1";
	if(!gd(rh,xh)){
		cout<<"00";
		return 0;
	}
	cout<<"1";
	rx=(rp[0]-'0')*10+(rp[1]-'0');
	xx=(xp[0]-'0')*10+(xp[1]-'0');
	if(xl(rx,rh,xx,xh)){
		cout<<"1";
		return 0;
	}
	cout<<"0";
	return 0;
} 
