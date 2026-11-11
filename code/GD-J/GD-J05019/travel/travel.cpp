#include <bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int cnt1,cnt2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if (c1==c2)
	{
		cout<<"1";
	}
	else
	{
		cout<<"0"; 
	}
	if (s1[0]==s2[0] && s1[1]==s2[1] && c1==c2)
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
	if (s1[2]<='C')
	{
		cnt1=0;
	}
	else
	{
		cnt1=1;
	}
	if (s2[2]<='C')
	{
		cnt2=0;
	}
	else
	{
		cnt2=1;
	}
	if (cnt1==cnt2 && s1[0]==s2[0] && s1[1]==s2[1] && c1==c2)
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
	if (cnt1==cnt2 && s1[0]==s2[0] && s1[1]==s2[1] && c1==c2 && abs(s1[2]-s2[2])==1)
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
	return 0;
} 
