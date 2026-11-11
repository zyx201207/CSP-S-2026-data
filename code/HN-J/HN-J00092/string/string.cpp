#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int n, x;
int u = 1, ans, m;
char c;
string s;
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	s = '#' + s;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> x >> c;
		for (int j = 1; j <= x; j++)
		{
			s[u] = c;
			u++;
		}
	}
	m = u - 1;
	for (int i = 1; i <= m / 2; i++)
	{
		if ( s[i] != s[m + 1 - i] )
		{
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}
