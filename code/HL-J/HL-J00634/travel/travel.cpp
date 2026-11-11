#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;
	string s,d;
	cin>>a>>s>>b>>d;
	bool flag1=0,flag2=0,flag3=0,flag4=0;
	if(a<=17&&a>=2&&a!=16&&b<=17&&b>=2&&b!=16&&s!=d)
	{
	if(a==b)
	{
		flag1=1;
		if(s[0]==d[0]&&s[1]==d[1])
		{
			flag2=1;
			if(s[2]=='A'||s[2]=='B'||s[2]=='C')
			{
				if(d[2]=='A'||d[2]=='B'||d[2]=='C')
				{
					flag3=1;
				}
			}
			if(s[2]=='D'||s[2]=='F')
			{
				if(d[2]=='D'||d[2]=='F')
				{
					flag3=1;
				}
			}
			if(s[2]=='D'&&d[2]=='F')
			{
				flag4=1;
			}
			if(s[2]=='F'&&d[2]=='D')
			{
				flag4=1;
			}
			if(s[2]=='A'&&d[2]=='B')
			{
				flag4=1;
			}
			if(s[2]=='B'&&d[2]=='C')
			{
				flag4=1;
			}
			if(s[2]=='B'&&d[2]=='A')
			{
				flag4=1;
			}
			if(s[2]=='C'&&d[2]=='B')
			{
				flag4=1;
			}
		}
		
	}}
	cout<<flag1<<flag2<<flag3<<flag4;
	return 0;
} 
