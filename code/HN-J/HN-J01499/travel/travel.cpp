#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char ans[6]={};
	string c1,c2,s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		ans[0]='1';
		if((s1[0]==s2[0])&&(s1[1]==s2[1]))
		{
			ans[1]='1';
			if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>'C'&&s2[2]>'C'))
			{
				ans[2]='1';
				if(s1[2]+1==s2[2]||s1[2]-1==s2[2])
				{
					ans[3]='1';
				}
				else
				{
					ans[3]='0';
				}
			}
			else
			{
			ans[2]='0';
			ans[3]='0';
			}
		}
		else
		{
			ans[1]='0';
			ans[2]='0';
			ans[3]='0';
		}
	}
	else
	{
		ans[0]='0';
		ans[1]='0';
		ans[2]='0';
		ans[3]='0';
	}
	cout<<ans;
	return 0;
}
