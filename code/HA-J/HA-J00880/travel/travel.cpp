#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
char a,b,c,d;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		a='1';
	}
	else
	{
		cout<<"0000";
		return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1])
	{
		b='1';
	}
	else
	{
		b='0';
		cout<<"1000";
		return 0;
	}
	if((((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s1[2]=='C')||(s1[2]=='A'&&s2[2]=='C'))||((s1[2]=='B'&&s2[2]=='A')||(s1[2]=='C'&&s1[2]=='B')||(s1[2]=='C'&&s2[2]=='A')))||((s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s1[2]=='D')))
	{
		c='1';
	}
	else
	{
		cout<<"1100";
		c='0';
		return 0;
	}
	if(abs(s1[2]-s2[2])==1&&c=='1')
	{
		d='1';
	}
	else
	{
		d='0';
	}
	cout<<a<<b<<c<<d;
	return 0;
}
