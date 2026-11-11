#include<bits/stdc++.h>
#define int long long
using namespace std;
string x, s, y, t, ans;
signed main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> x >> s >> y >> t;
	ans="0000";
	if (x==y)
	{
		ans[0]='1';
		if (s[0]==t[0] && s[1]==t[1])
		{
			ans[1]='1';
			if ((('A'<=s[2] && s[2]<='C') && ('A'<=t[2] && t[2]<='C')) || (('D'<=s[2] && s[2]<='F') && ('D'<=t[2] && t[2]<='F')))
			{
				ans[2]='1';
				if ((s[2]=='A' && t[2]=='B') || (s[2]=='B' && t[2]=='A') || (s[2]=='B' && t[2]=='C') || (s[2]=='C' && t[2]=='B') || (s[2]=='D' && t[2]=='F') || (s[2]=='F' && t[2]=='D'))
				{
					ans[3]='1';
				}
			}
		}
	}
	cout << ans;
	return 0;
}
