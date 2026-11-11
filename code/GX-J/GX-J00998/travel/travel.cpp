#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<map>
#include<string>
#include<cstring>
using namespace std;
string s1,s2,s3,s4;
int len,flag,a,b;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>s3>>s4;
	
	if(s1[1]==s3[1]&&s1[0]==s3[0])
	{
		cout<<1;
		flag=1;
	}
	else
	{
		cout<<0;
		flag=0;
	}
	
	if(s2[0]==s4[0]&&s2[1]==s4[1]&&flag==1)	
		cout<<1;
	else
	{
		cout<<0;
		flag=0;
	}

	if(s2[2]<='C'&&s4[2]<='C'&&flag==1&&s2[2]>='A'&&s4[2]>='A')
	{
		cout<<1;
		a=1;
	}
	else
		if(s2[2]<='F'&&s4[2]<='F'&&flag==1&&s2[2]>='D'&&s4[2]>='D')
		{
			cout<<1;
			b=1;
		}
		else
		{
			cout<<0;
			flag=0;
		}
	//cout<<" "<<a<<" "<<b<<" ";
	if(a==0&&b==0)
	{
			cout<<0;
			return 0;
	}
	if(flag==0)
	{
		cout<<0;
		return 0;
	}
	if(flag==1&&a==1)
	{
		int a1=s2[2]-'0';
		int a2=s4[2]-'0';
		if(a1-a2==1)
		{
			cout<<1;
			return 0;
		}	
		else
			if(a2-a1==1)
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
	if(flag==1&&b==1)
	{
			cout<<1;
			return 0;
	}
	
	return 0;
}
