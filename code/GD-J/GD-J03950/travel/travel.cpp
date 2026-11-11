#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string ans;
	string c1,c2,s1,s2;
	cin>>c1>>s1>>c2>>s2;
	for(int i=0;i<2;i++)
	{
		if(c2[i]!=c1[i])
		{
			ans[0]='0';
			break;
		}
		ans[0]='1';
	}
	if(ans[0]=='1')
	{
		for(int i=0;i<2;i++)
		{
		if(s1[i]!=s2[i])
			{
				ans[1]='0';
				break;
			}
			ans[1]='1';
		}
		if(ans[1]=='1')
		{
		if((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='A')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='B')||(s1[2]=='C'&&s2[2]=='A')||(s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D'))
			ans[2]='1';
		else
			ans[2]='0';
		if(ans[2]=='1')
		{
		if((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='D'&&s2[2]=='F')||(s1[2]=='B'&&s2[2]=='A')||(s1[2]=='C'&&s2[2]=='B')||(s1[2]=='F'&&s2[2]=='D'))
			ans[3]='1';
		else
			ans[3]='0';
		if(ans[3]=='1')
		{
		cout<<ans[0]<<ans[1]<<ans[2]<<ans[3];
		}
		else
		cout<<"1110";
		}
		else
		cout<<"1100";
		}
		else
		cout<<"1000";
	}
	else
	cout<<"0000";
	return 0;
 } 
