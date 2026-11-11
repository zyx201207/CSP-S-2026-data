#include<bits/stdc++.h>
using namespace std;
string x,xx,y,yy;
bool p,pd,ppd;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>x>>xx>>y>>yy;
	if(x==y)cout<<1;
	else {cout<<"0000";return 0;}
	string a="",b="";
	for(int i=0;i<=1;i++)a+=xx[i],b+=yy[i];
	if(a==b)cout<<1;
	else {cout<<"000";return 0;}
	if((xx[2]=='A'||xx[2]=='B'||xx[2]=='C')&&(yy[2]=='A'||yy[2]=='B'||yy[2]=='C')||(xx[2]=='D'||xx[2]=='F')&&(yy[2]=='D'||yy[2]=='F'))cout<<1;
	else {cout<<"00";return 0;}
	if(xx[2]=='A'&&yy[2]=='B'||xx[2]=='B'&&yy[2]=='C'||xx[2]=='D'&&yy[2]=='F'||yy[2]=='A'&&xx[2]=='B'||yy[2]=='B'&&xx[2]=='C'||yy[2]=='D'&&xx[2]=='F')cout<<1;
	else cout<<0;
	return 0;
}

