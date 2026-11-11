#include<bits/stdc++.h>
using namespace std;
long long a,b;
string as,bs;
long long x,y;
long long z=0;
long long q=0;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>as>>b>>bs;
	if(a==b)
	{
		cout<<1;
	}
	else
	{
		for(int i=1;i<=4;i++)
		{
			cout<<0;
		}
		return 0;
	}
	if(as[0]==bs[0]&&as[1]==bs[1])
	{
		cout<<1;
		z=1;
	}
	else
	{
		cout<<0;
	}
	if(z==1)
	{
		if(as[2]<'D'&&bs[2]<'D')
		{
			cout<<1;
			q=1;
		}
		else if(as[2]>'C'&&bs[2]>'C')
		{
			cout<<1;
			q=1;
		}
		else
		{
			cout<<0;
		}
	}
	else
	{
		cout<<0;
	}
	if(q==1)
	{
		if(as[0]==bs[0]&&as[1]==bs[1]-1)
		{
			cout<<1;
		}
		else if(as[0]==bs[0]&&as[1]==bs[1]+1)
		{
			cout<<1;
		}
		else if(as[0]==bs[0]-1&&as[1]==bs[1]+9)
		{
			cout<<1;
		}
		else if(as[0]-1==bs[0]&&as[1]+9==bs[1]+1)
		{
			cout<<1;
		}
		else if(as[2]==bs[2]+1)
		{
			cout<<1;
		}
		else if(as[2]==bs[2]-1)
		{
			cout<<1;
		}
		else
		{
			cout<<0;
		}
	}
	else
	{
		cout<<0;
	}
	return 0;
}
