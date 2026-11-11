#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
string rx,rz,xx,xz;
cin>>rx>>rz>>xx>>xz;
bool b1=0,b2=0,b3=0,b4=0;
if(rx==xx)b1=1;
if(b1&&rz[0]==xz[0]&&rz[1]==xz[1])b2=1;
char a=rz[2],b=xz[2];
if(b2){
if((a=='A'||a=='B'||a=='C')&&(b=='A'||b=='B'||b=='C'))b3=1;
if((b=='D'||b=='F')&&(a=='D'||a=='F'))b3=1;
}
if(b3){
	if(a=='D'||a=='F')b4=1;
	else{
		if(!((a=='C'&&b=='A')||(a=='A'&&b=='C')))b4=1;
	}
}
cout<<b1<<b2<<b3<<b4;
return 0;
}
