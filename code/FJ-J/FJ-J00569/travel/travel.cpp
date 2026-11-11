#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
		if(c1==c2)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
		cout<<0;
		cout<<0;
		cout<<0;
		return 0;
	}
	int a1=s1.size();
	int b1=s2.size();
	string a="",b="",c="",d="";
	for(int i=0;i<=a1-2;i++)
	{
		a+=s1[i];
	}
	for(int j=0;j<=b1-2;j++)
	{
		b+=s2[j];
	}
	if(a==b)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
		cout<<0;
		cout<<0;
		return 0;
	}
	c+=s1[a1-1];
	d+=s2[b1-1];
	string e=c+d;
	if(e=="AB"||e=="BA"||e=="BC"||e=="CB"||e=="DF"||e=="FD"||e=="AC"||e=="CA")
	{
		cout<<1;
	}
	else
	{
		cout<<0;
		cout<<0;
		return 0;
	}
	if(e=="AB"||e=="BA"||e=="BC"||e=="CB"||e=="DF"||e=="FD")
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	return 0;
}
