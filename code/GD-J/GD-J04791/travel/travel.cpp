#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int a=0,b=0,c=0,d=0;
	char x,y;
	string c1,c2,s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		a=1;
	}
	else
	{
		a=0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1])
	{
		b=1;
	}
	else
	{
		b=0;
	}
	
	if(s1[0]==s2[0]&&s1[1]==s2[1])
	{
		if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C')
		{
			if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')
			{
				c=1;
			}
		}
		else if(s1[2]=='D'||s1[2]=='F')
		{
			if(s2[2]=='D'||s2[2]=='F')
			{
				c=1;
			}
		}
	}
	else
	{
		c=0;
	}
	
	if(a==1&&b==1&&c==1)
	{
		x=s1[2];
		y=s2[2];
		if(x=='A'&&y=='B')
		{
			d=1;
		}
		else if(x=='B'&&y=='A')
		{
			d=1;
		}
		else if(x=='B'&&y=='C')
		{
			d=1;
		}
		else if(x=='C'&&y=='B')
		{
			d=1;
		}
		else if(x=='D'&&y=='F')
		{
			d=1;
		}
		else if(x=='F'&&y=='D')
		{
			d=1;
		}
	}
	else
	{
		d=0;
	}
	cout<<a<<b<<c<<d<<'\n';
	
	return 0;
}
