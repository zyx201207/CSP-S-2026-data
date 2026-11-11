#include<bits/stdc++.h>
using namespace std;
int e[205];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;
	string c,d;
	cin>>a>>c>>b>>d;
	e['A']=1;
	e['B']=1;
	e['C']=1;
	e['D']=2;
	e['F']=2;
	if(a==b)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	if(a==b&&c[0]==d[0]&&c[1]==d[1])
	{
		cout<<1;
	}
	else cout<<0;
	if(a==b&&c[0]==d[0]&&c[1]==d[1]&&e[int(c[2])]==e[int(d[2])])
	{
		cout<<1;
	}
	else cout<<0;
	if(a==b&&c[0]==d[0]&&c[1]==d[1])
	{
		if(e[int(c[2])]==2&&e[int(d[2])]==2)
		{
			cout<<1;
		}
		else
		{
			if(c[2]=='A'&&d[2]=='B') cout<<1;
			else if(c[2]=='B'&&d[2]=='A') cout<<1;
			else if(c[2]=='B'&&d[2]=='C') cout<<1;
			else if(c[2]=='C'&&d[2]=='B') cout<<1;
			else cout<<0;
		}
	}
	else cout<<0;
}
