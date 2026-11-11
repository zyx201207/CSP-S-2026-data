#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
string ans="0000";
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if (c1==c2)
		ans[0]='1';
	else
	{
		cout<<ans;
		return 0;
	}
	if (s1[0]==s2[0] && s1[1]==s2[1])
		ans[1]='1';
	else
	{
		cout<<ans;
		return 0;
	}
	if (s1[2]=='A' && s2[2]=='B' || s1[2]=='B' && s2[2]=='A' || s1[2]=='B' && s2[2]=='C' || s1[2]=='C' && s2[2]=='B' || s1[2]=='D' && s2[2]=='F' || s1[2]=='F' && s2[2]=='D')
	{
		ans[2]='1';
		ans[3]='1';
		cout<<ans;
		return 0;
	}
	else if(s1[2]=='A' && s2[2]=='C' || s1[2]=='C' && s2[2]=='A')
	{
		ans[2]='1';
		ans[3]='0';
		cout<<ans;
		return 0;
	}
	else
	{
		ans[2]='0';
		ans[3]='0';
		cout<<ans;
		return 0;
	}
	return 0;
} 
