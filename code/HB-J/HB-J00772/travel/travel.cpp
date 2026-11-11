#include <bits/stdc++.h>
#define int long long
using namespace std;

string c1,c2,s1,s2;
string ans;

signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		ans+="1";
		if(s1.size()==s2.size())
		{
			for(int i=0;i<s1.size();++i)
			{
				if(isdigit(s1[i])||(isdigit(s2[i])))
				{
					if(s1[i]!=s2[i])
					{
						ans+="000";
						break;
					}
				}
				else
				{
					ans+="1";
					if((s1[i]<='C'&&s2[i]<='C')||(s1[i]>='D'&&s2[i]>='D'))
					{
						ans+="1";
						if((abs(s1[i]-s2[i])==1)&&(!((s1[i]=='C'&&s2[i]=='D')||(s1[i]=='D'&&s2[i]=='C'))))
						{
							ans+="1";
						}
						else ans+="0";
					}
					else
					{
						ans+="00";
					}
					break;
				}
			}
		}
		else
		{
			ans+="000";
		}
	}
	else
	{
		ans+="0000";
	}
	cout<<ans;
	return 0;
}