#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
struct stu{
	int ax;//³µÏáºÅ
	int bx;//ÅÅºÅ
	char ch;//×ùÎ»ºÅ
	int cc;//²à   ABC---1       DF---2
}a,b;
string ax1,bx1;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a.ax>>ax1>>b.ax>>bx1;
	a.bx=(ax1[0]-'0')*10+(ax1[1]-'0');
	b.bx=(bx1[0]-'0')*10+(bx1[1]-'0');
	a.ch=ax1[2];
	b.ch=bx1[2];
//--------------------------------------------------
	if(a.ax==b.ax){
		cout<<"1";
	}else{
		cout<<"0000";
		return 0;
	}
//--------------------------------------------------
	if(a.bx==b.bx){
		cout<<"1";
	}else{
		cout<<"000";
		return 0;
	}
//--------------------------------------------------
	if((a.ch=='A')||(a.ch=='B')||(a.ch=='C')){
		a.cc=1;
	}else{
		a.cc=2;
	}
	if((b.ch=='A')||(b.ch=='B')||(b.ch=='C')){
		b.cc=1;
	}else{
		b.cc=2;
	}
//--------------------------------------------------
	if(a.cc==b.cc){
		cout<<"1";
	}else{
		cout<<"00";
		return 0;
	}
//--------------------------------------------------
	if((a.ch=='D'&&b.ch=='F')||(a.ch=='F'&&b.ch=='D')||(a.ch=='A'&&b.ch=='B')||(a.ch=='B'&&b.ch=='A')||(a.ch=='B'&&b.ch=='C')||(a.ch=='C'&&b.ch=='B')){
		cout<<"1";
	}else{
		cout<<"0";
	}
//--------------------------------------------------
	return 0;
} 
