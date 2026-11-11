#include<bits/stdc++.h>
using namespace std;
string b,d; 
int a,c;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>a>>b>>c>>d;
	if(a!=c){cout<<"0000";return 0;}
	if(a==c)cout<<1;
	else cout<<0;
	if(b[0]==d[0]&&b[1]==d[1])cout<<1;
	else cout<<0;
	if((b[0]==d[0]&&b[1]==d[1])&&((b[2]=='A'||b[2]=='B'||b[2]=='C')&&(d[2]=='A'||d[2]=='B'||d[2]=='C'))||(b[2]=='D'||b[2]=='F')&&(d[2]=='D'||d[2]=='F'))cout<<1;
	else cout<<0;
	if((b[0]==d[0]&&b[1]==d[1])&&((b[2]=='A'||b[2]=='B'||b[2]=='C')&&(d[2]=='A'||d[2]=='B'||d[2]=='C'))||(b[2]=='D'||b[2]=='F')&&(d[2]=='D'||d[2]=='F')&&abs(int(b[2])-int(d[2]))==1)cout<<1;
	else cout<<0;
	return 0;
} 
/*
游记？ 
关注Hamster_Emperor谢谢喵
签到题 
*/ 

