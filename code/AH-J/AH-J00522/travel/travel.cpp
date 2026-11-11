#include<bits/stdc++.h>
using namespace std;
int l1,l2,s1,s2,i,j;
char r1,r2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>l1>>s1>>r1>>l2>>s2>>r2;
	i=r1,j=r2;
	if(l1==l2)	
		cout<<1;
	else
	{
		cout<<"0000";
		return 0;
	}
	if(s1==s2)	
		cout<<1;
	else
	{
		cout<<"000";
		return 0;
	}
	if((i>=65&&i<=67&&j>=65&&j<=67) || (i>=68&&i<=70&&j>=67&&j<=70))
	{
		cout<<1;
	}
	else
	{
		cout<<"00";
		return 0;
	}
	if(abs(i-j)==1)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	return 0;
}
