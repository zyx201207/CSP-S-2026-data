#include<bits/stdc++.h>
using namespace std;
string rc,xc,rz,xz;//c ³µÏá z ×ùÎ»
bool bj1=1,bj2=1,bj3=1,bj4=1; 
int shu1=0,shu2=0;//1 r 2 c
char t,y;
bool f(char a,char b){
	if((a=='A'&&b=='B')||(b=='A'&&a=='B')) return 1;
	if((a=='B'&&b=='C')||(b=='B'&&a=='C')) return 1;
	if((a=='D'&&b=='F')||(b=='F'&&a=='D')) return 1;
	return 0;
}
bool g(char c,char d){
	if((c>='A'&&c<='C')&&(d>='A'&&d<='C')) return 1;
	if((c>='D'&&c<='F')&&(d>='D'&&d<='F')) return 1;
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>rc>>rz>>xc>>xz;
	shu1=(rz[0]-'0')*10+(rz[1]-'0');
	shu2=(xz[0]-'0')*10+(xz[1]-'0');
	t=rz[2];y=xz[2];
	if(rc!=xc) bj1=0;
	if(!((shu1==shu2)&&bj1)) bj2=0;
	if(!(g(t,y)&&bj2)) bj3=0;
	if(!(f(t,y)&&bj3)) bj4=0;
	cout<<bj1<<bj2<<bj3<<bj4;
	return 0; 
} 
