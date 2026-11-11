//GZ-J00333-·ëºÆÎÄÇÕ 
#include<cstdio>
#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,s,d,f;
	cin>>a>>s>>d>>f;
		if(a!=d)
		{
			cout<<"0000";
			return 0;
		}
		int r=0,t=0;
		cout<<1;
		int y=0,u=0;
		for(int i=0;i<3;i++)
		{
			if(s[i]>='0'&&s[i]<='9')
			{
				y=y*10+(s[i]-'0');
			}
		}
		for(int i=0;i<3;i++)
		{
			if(f[i]>='0'&&f[i]<='9')
			{
				u=u*10+(f[i]-'0');
			}
		}
		for(int i=0;i<3;i++)
		{
			if(s[2]>='A'&&s[2]<='C'&&f[2]>='A'&&f[2]<='C'&&i==2)
			{
				r=1;
				if(s[2]=='B'||f[2]=='B')
				{
					t=1;
				}
			}
			else if(s[2]>='D'&&s[2]<='E'&&f[2]>='D'&&f[2]<='E'&&i==2)
			{
				r=1;
				t=1;
			}
		} 
		if(y==u)
		{
			cout<<1;
			cout<<r<<t;
		}
		else if(y!=u)
		{
			cout<<0;
			cout<<0;
			cout<<0;
		}
	return 0;
} 
