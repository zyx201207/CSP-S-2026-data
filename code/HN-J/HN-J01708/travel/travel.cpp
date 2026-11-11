#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
string s1,s2,s3,s4,ans = ""; 
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> s1 >> s2 >> s3 >> s4;
	if(s1 == s3)
	{
		ans = ans + "1";
		if(s2[0] == s4[0] && s2[1] == s4[1])
		{
			ans = ans + "1";
			if(s2[2] >= 'D' && s2[2] <= 'F' && s4[2] >= 'D' && s4[2] <= 'F' || s2[2] >= 'A' && s2[2] <= 'C' && s4[2] >= 'A' && s4[2] <= 'C')
			{
				ans = ans + "1";
				if(abs(s2[2] - s4[2]) == 1)
				{
					if(s2[2] == 'C' && s4[2] == 'D' || s4[2] == 'C' && s2[2] == 'D') ans = ans + "0";
					else ans = ans  + "1";
				}
				else ans = ans + "0";
			}
			else ans = ans + "00";
		}
		else ans = ans + "000";
	}
	else ans = "0000";
	cout << ans;
	return 0;
}
