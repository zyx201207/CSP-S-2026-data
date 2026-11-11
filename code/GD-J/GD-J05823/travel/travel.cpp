#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,s3,s4;
	cin>>s1>>s2>>s3>>s4;
	if(s1==s3)
	{
		cout<<1;
	}
	else
	{
		cout<<"0000";
		return 0;
	}
	string a,b;
	a=s2.substr(0,2);
	b=s4.substr(0,2);
	if(a==b)
	{
		cout<<1;
	}
	else
	{
		cout<<"000";
		return 0;
	}
	char c,d;
	c=s2[2];
	d=s4[2];
	if(c>='A'&&c<='C'&&d>='A'&&d<='C'||c>='D'&&c<='F'&&d>='D'&&d<='F')
	{
		cout<<1;
	}
	else
	{
		cout<<"00";
		return 0;
	}
	if(abs(c-d)==1)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	return 0;
}

