#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	string c1,s1,c2,s2;
	string ans;
	cin>>c1>>s1>>c2>>s2;
	if (c1==c2)
	{
		ans+="1";
		string a,b;
		a+=s1[0];
		a+=s1[1];
		b+=s2[0];
		b+=s2[1];
		if (a==b)
		{
			ans+="1";
			string a,b;
			a+=s1[2];
			b+=s2[2];
			if ((a=="A" || a=="B" || a=="C") && (b=="D" || b=="F"))
			{
				ans+="00";
			}
			else
			{
				ans+="1";
				if ((s1[2]+1==s2[2]) || (s1[2]=='D'&&s2[2]=='F') || (s1[2]=='F' && s2[2]=='D') || (s2[2]+1==s1[2]))
				{
					ans+="1";
				}
				else
				{
					ans+="0";
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
