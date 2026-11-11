#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<map>
using namespace std;
string s1,s2;
int a,b;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>s1>>b>>s2;
	if(a!=b)
	{
		cout<<0000;
		return 0;
	}
	else
	{
		cout<<1;
		if(s1[0]==s2[0]&&s1[1]==s2[1])
			cout<<1;
		else cout<<0;
		int f=0;
		if(s1[2]>='A'&&s1[2]<='C')
		{
			if(s2[2]=='D'||s2[2]=='F')
			{
				cout<<0;
				f=1;
			}
		}
		else
		{
			if(s2[2]>='A'&&s2[2]<='C')
			{
				if(s1[2]=='D'||s1[2]=='F')
				{
					cout<<0;
					f=1;
				}
			}
		}
		int g=s1[2],k=s2[2];
		if(f==0)
		{
			cout<<1;
			if(g+1==k||g-1==k)
			{
				cout<<1;
				return 0;
			}
			else
			{
				cout<<0;
				return 0;
			}
		}
		else cout<<0;
	}
	return 0;
}
