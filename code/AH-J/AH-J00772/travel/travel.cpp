#include<bits/stdc++.h>
using namespace std;
string Rc,Xc,Rz,Xz;
bool b,c,d;
int main( ){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>Rc>>Rz>>Xc>>Xz;
	if(Rc==Xc){cout<<1;b=1;}
	else {cout<<0;b=0;}
	if(b==1&&Rz[0]==Xz[0]&&Rz[1]==Xz[1]){cout<<1;d=1;}
	else {cout<<0;d=0;}
	if((d==1&&Rz[2]>='A'&&Rz[2]<='C'&&Xz[2]>='A'&&Xz[2]<='C')||(d==1&&Rz[2]>='D'&&Rz[2]<='F'&&Rz[2]>='D'&&Rz[2]<='F')){cout<<1;c=1;}
	else {cout<<0;c=0;}
	if(abs(Rz[2]-Xz[2])==1&&c==1)cout<<1;
	else cout<<0;
return 0;
}
