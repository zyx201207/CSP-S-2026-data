#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	for(int i=0;i<2;i++)
	{
		if(c1[i]!=c2[i])
		{
			cout<<0<<0<<0<<0;
			return 0;
		}
	}
	cout<<1;
	for(int i=0;i<2;i++)
	{
		if(s1[i]!=s2[i])
		{
			cout<<0<<0<<0;
			return 0;
		}
	}
	cout<<1;
	if(s1[2]-'0'<=19&&s2[2]-'0'<=19)
	{
		cout<<1;
	}
	else if(s1[2]-'0'>19&&s2[2]-'0'>19)
	{
		cout<<1;
	}
	else
	{
		cout<<0<<0;
		return 0;
	}
	if(s1[2]-'0'<=19)
	{
		if(s1[2]-'0'-1==s2[2]-'0'||s1[2]-'0'+1==s2[2]-'0'||s1[2]-'0'==s2[2]-'0'-1||s1[2]-'0'==s2[2]-'0'+1)
		{
			cout<<1;
		}
		else
		{
			cout<<0;
		}
	}
	else if(s1[2]-'0'>19)
	{
		if(s1[2]-'0'-2==s2[2]-'0'||s1[2]-'0'+2==s2[2]-'0'||s1[2]-'0'==s2[2]-'0'-2||s1[2]-'0'==s2[2]-'0'+2)
		{
			cout<<1;
		}
		else
		{
			cout<<0;
		}
	}
	return 0;
}
