#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	int x=0;
	cin>>a>>b>>c>>d;
	if(a==c)
	{
	  cout<<1;
	}
	else cout<<0;
	if(b[0]==d[0]&&b[1]==d[1]&&b[2]!=d[2])
	{
		cout<<1;
		x=1;
		}
	else cout<<0;
	if(x==1)
	{
		if(b[2]<='C'&&d[2]<='C'&&b[2]!=d[2]) cout<<1;
		else if(b[2]>'C'&&d[2]>'C'&&b[2]!=d[2]) cout<<1;
		else cout<<0;
	}
	else cout<<0;
	if(x==1)
	{
		if(b[2]=='A'&&d[2]=='B') cout<<1;
	else if(b[2]=='B'&&d[2]=='C') cout<<1;
	else if(b[2]=='C'&&d[2]=='B') cout<<1;
	else if(b[2]=='B'&&d[2]=='A') cout<<1;
	else if(b[2]=='D'&&d[2]=='E') cout<<1;
	else if(b[2]=='E'&&d[2]=='D') cout<<1;
	else cout<<0;
	}
	cout<<0;
}

                                              
