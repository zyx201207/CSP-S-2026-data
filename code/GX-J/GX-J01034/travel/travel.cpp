#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
using namespace std;
string s1,s2;
int a1,a2,pd1,pd2,pd3;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>s1>>a2>>s2;
	if(a1==a2)
	{
		cout<<"1";
		pd1=1;
	}
	else
		cout<<"0";
	if(pd1==1)
	{
		if(s1[0]==s2[0] && s1[1]==s2[1])
		{
			cout<<"1";
			pd2=1;
		}
		else
			cout<<"0";
	}
	else
		cout<<"0";
	if(pd2==1)
	{
		if(s1[2]<='C' && s2[2]<='C')
		{
			cout<<"1";
			pd3=1;
		}
		if(s1[2]>='D' && s2[2]>='D')
		{
			cout<<"1";
			pd3=1;
		}
		if(pd3==0)
			cout<<"0";
	}
	else
		cout<<"0";
	if(pd3==1)
	{
		if(s1[2]-s2[2]==1 || s2[2]-s1[2]==1)
			cout<<"1";
		else
			cout<<"0";
	}
	else
		cout<<"0";
	return 0;
}
