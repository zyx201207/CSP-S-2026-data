#include<bits/stdc++.h>
using namespace std;
char r[5];
char r1[5];
char x[5];
char x1[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>r>>r1>>x>>x1;
	if(r[0]==x[0] && r[1]==x[1])
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	if(x1[0]==r1[0] && x1[1]==r1[1])
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	if(r1[2]=='B')
	{
		if(x1[2]=='A' || x1[2]=='C')
		{
			cout<<1;
		}
		else
		{
			cout<<0;
		}
	}
	if(r1[2]=='C')
	{
		if(x1[2]=='A' || x1[2]=='B')
		{
			cout<<1;
		}
		else
		{
			cout<<0;
		}
	}
	if(r1[2]=='E')
	{
		if(x1[2]=='F')
		{
			cout<<1;
		}
		else
		{
			cout<<0;
		}
	}
	if(r1[2]=='F')
	{
		if(x1[2]=='E')
		{
			cout<<1;
		}
		else
		{
			cout<<0;
		}
	}
	if(r1[2]=='A')
	{
		if(x1[2]=='B' || x1[2]=='C')
		{
			cout<<1;
		}
		else
		{
			cout<<0;
		}
	}
	if(r1[2]=='A')
	{
		if(x1[2]=='B')
		{
			cout<<1;
		}
		else
		{
			cout<<0;
		}
	}
	if(r1[2]=='B')
	{
		if(x1[2]=='A' || x1[2]=='C')
		{
			cout<<1;
		}
		else
		{
			cout<<0;
		}
	}
	if(r1[2]=='C')
	{
		if(x1[2]=='B')
		{
			cout<<1;
		}
		else
		{
			cout<<0;
		}
	}
	if(r1[2]=='E')
	{
		if(x1[2]=='F')
		{
			cout<<1;
		}
		else
		{
			cout<<0;
		}
	}
	if(r1[2]=='F')
	{
		if(x1[2]=='E')
		{
			cout<<1;
		}
		else
		{
			cout<<0;
		}
	}
	return 0;
}
