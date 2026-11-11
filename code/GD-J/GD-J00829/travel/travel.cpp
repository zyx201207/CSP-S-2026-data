#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int s,ss,bb,dd;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c) cout<<"1";
	else
	{
		cout<<"0000";
		return 0;
	}
	if(b[0]==d[0]&&b[1]==d[1]) cout<<"1";
	else
	{
		cout<<"000";
		return 0;
	}
	if(b[2]=='A'||b[2]=='B'||b[2]=='C') s=1;
	if(d[2]=='A'||d[2]=='B'||d[2]=='C') ss=1;
	if(s==ss) cout<<"1";
	else
	{
		cout<<"00";
		return 0;
	}
	if(b[2]=='A') bb=1;
	if(b[2]=='B') bb=2;
	if(b[2]=='C') bb=3;
	if(b[2]=='D') bb=4;
	if(b[2]=='E') bb=5;
	if(d[2]=='A') dd=1;
	if(d[2]=='B') dd=2;
	if(d[2]=='C') dd=3;
	if(d[2]=='D') dd=4;
	if(d[2]=='E') dd=5;
	if(abs(bb-dd)==1) cout<<"1";
	else cout<<"0";
	return 0;
}
