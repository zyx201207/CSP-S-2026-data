#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
bool fg=0;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	for(int i=0;i<a.size();i++)
	{
		if(a[i]!=c[i])
		{
			fg=1;
			break;
		}
	}
	if(fg==1)
	{
		cout<<0;
		cout<<0;
		cout<<0;
		cout<<0;
		return 0;
	}
	for(int i=0;i<b.size()-1;i++)
	{
		if(b[i]!=d[i])
		{
			fg=1;
			break;
		}
	}
	if(fg==1)
	{
		cout<<1000;
		return 0;
	}
	if(b[2]=='D'&&d[2]=='F')
	{
		cout<<1111;
		return 0;
	}
	if(b[2]=='F'&&d[2]=='D')
	{
		cout<<1111;
		return 0;
	}
	if(b[2]-'A'<=2&&d[2]-'A'<=2)
	{
		if(b[2]=='A'&&d[2]=='B')
		{
			cout<<1111;
			return 0;
		}
		else if(b[2]=='B'&&d[2]=='C')
		{
			cout<<1111;
			return 0;
		}
		else if(d[2]=='A'&&b[2]=='B') 
		{
			cout<<1111;
			return 0;
		}
		else if(d[2]=='B'&&b[2]=='C')
		{
			cout<<1111;
			return 0;
		}
		else 
		{
			cout<<1110;
			return 0;
		}
	}
	cout<<1100;
	return 0;
}
