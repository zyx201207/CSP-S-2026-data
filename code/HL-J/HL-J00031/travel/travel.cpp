#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	long long c1,c2,s3=0,s4=0;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) cout<<1;
	else
	{
		cout<<0<<0<<0<<0;
		return 0;
	}
	if(s1[1]==s2[1]&&s1[0]==s2[0])
	{
		cout<<1;
	}
	else
	{
		cout<<0<<0<<0;
		return 0;
	}
	if(s1[3]=='D'&&s2[3]=='C')
	{
		cout<<0<<0;
		return 0;
	}
	else if(s1[3]=='C'&&s2[3]=='D')
	{
		cout<<0<<0;
		return 0;
	}
	else
	{
		cout<<1;
	}
	
	if(abs(s1[2]-s2[2])==1)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	
	return 0;
}
