//travel.cpp
#include <bits/stdc++.h>
using namespace std;
string c1;
string c2;
string c3;
string c4;
bool s0=false;
bool s1=false;
bool s2=false;
bool s3=false;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>c1>>c2>>c3>>c4;
	s0=(c1==c3?true:false);
	cout<<(s0?"1":"0");
	s1=(c2[0]==c4[0]&&c2[1]==c4[1]);
	cout<<(s0&&s1?"1":"0");
	if(c2[2]<='C') s2=(c4[2]<='C'?true:false);
	else s2=(c4[2]>'C'?true:false);
	cout<<(s0&&s1&&s2?"1":"0");
	if(c2[2]=='A') s3=(c4[2]=='B'?true:false);
	else if(c2[2]=='B') s3=(c4[2]=='A'||c4[2]=='B'?true:false);
	else if(c2[2]=='C') s3=(c4[2]=='B'?true:false);
	else if(c2[2]=='D') s3=(c4[2]=='F'?true:false);
	else s3=(c4[2]=='D'?true:false);
	cout<<(s0&&s1&&s2&&s3?"1":"0");
	cout<<endl;
	return 0;
} 
