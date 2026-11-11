#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,s3,s4;
	cin>>s1>>s2>>s3>>s4;
	string ans = "1111";
	if(s1 == s3)
	{
		if(s2[0] == s4[0] && s2[1] == s4[1])
		{
			if(s2[2] <= 'C' &&  s4[2] <= 'C')
			{
				if(s2[2] == 'B'|| s4[2] == 'B')
				{
					ans = "1111";
				}
				else
				{
					ans = "1110";
				}
			}
			else if( s2[2] <='E' && s2[2] >= 'D' &&  s4[2] <= 'E' && s4[2] >= 'D')
			{
				ans = "1111";
			}
			else
			{
				ans = "1100";
			}
		}
		else
		{
			ans = "1000";
		}
	}
	else
	{
		ans = "0000";
	}
	cout<<ans;
	return 0;
}
