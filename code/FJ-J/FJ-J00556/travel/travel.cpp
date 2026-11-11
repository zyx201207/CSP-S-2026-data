#include<bits/stdc++.h>
using namespace std;
string s1,c1,c2,s2;
int a,b,c,d;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	for(int i=0;i<=1;i++)
	{
		a*=10;
		a+=(c1[i]-'0');
	}
	for(int i=0;i<=1;i++)
	{
		b*=10;
		b+=(c2[i]-'0');
	}
	if(a!=b)
	{
		cout<<"0000";
		return 0;
	}
	cout<<"1";
	for(int i=0;i<=1;i++)
	{
		c*=10;
		c+=(s1[i]-'0');
	}
	for(int i=0;i<=1;i++)
	{
		d*=10;
		d+=(s2[i]-'0');
	}
	if(d==c)
	{
		cout<<"1";
		if('D'<=s1[2]&&'F'>=s1[2]&&'D'<=s2[2]&&'F'>=s2[2])
		{
			cout<<"1";
		}
		else if('A'<=s1[2]&&'C'>=s1[2]&&'A'<=s2[2]&&'C'>=s2[2])
		{
			cout<<"1";
		}
		else
		{
			cout<<"00";
			return 0;
		}
	}
	else
	{
		cout<<"000";
		return 0;
}
		int e=s1[2],f=s2[2];
		if(abs(e-f)==1&&c==d)
		{
			cout<<"1";
		}
		
		else
		{
			cout<<"0";
		}
	
	return 0;
}
