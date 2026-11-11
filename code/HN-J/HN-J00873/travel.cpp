#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a=0,b=0,c=0,d=0; 
	int x1,x2;
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		a=1; 
		if((s1[0]==s2[0])||(s1[1]==s2[1]))
		{
			b=1;
		}
	}
	if(b==1)
	{
		if(s1[2]=='A')
		{
			if(s2[2]=='B')
			{
				d=1;
				c=1;
			}
			if(s2[2]=='C')
			{
				d=1;
			}
		}
		if(s1[2]=='B')
		{
			if(s2[2]=='A')
			{
				d=1;
				c=1;
			}
			if(s2[2]=='C')
			{
				d=1;
				c=1;
			}
		}
		if(s1[2]=='C')
		{
			if(s2[2]=='B')
			{
				d=1;
				c=1;
			}
			if(s2[2]=='A')
			{
				d=1;
			}
		}	
		if(s1[2]=='D')
		{
			if(s2[2]=='F')
			{
				d=1;
				c=1;
			}
		}
		if(s1[2]=='F')
		{
			if(s2[2]=='D')
			{
				d=1;
				c=1;
			}
		}
	}
	cout<<a<<b<<d<<c;
	return 0;
}
