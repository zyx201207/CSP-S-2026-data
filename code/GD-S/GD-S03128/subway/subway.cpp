#include <bits/stdc++.h>
#define int long long
using namespace std;

int TESTID, n, m, d, q;

map<int, int> g;

map<int, map<int, int>> s, l, a; 

signed main()
{
#ifndef DEBUG
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> TESTID >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
		cin >> g[i];
	for (int i = 1; i <= n; i++)
	{
		int k;
		cin >> k;
		for (int j = 1; j <= k; j++)
		{
			int a, t;
			cin >> a >> t;
			l[i][a] = s[a][i] = t;
		}
	}
	for (int i = 1; i < n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			for (auto p : l[i])
			{
				if (s[p.first][j])
				{
					if (a[i][j])
						a[i][j] = a[j][i] = min(a[i][j], p.second + s[p.first][j]);
					else
						a[i][j] = a[j][i] = p.second + s[p.first][j];
				}
			}
		}
	}
	while (q--)
	{
		int x, y, ans = LLONG_MAX;
		map<int, int> mp;
		for (int i = 1; i <= n; i++)
			mp[i] = LLONG_MAX;
		cin >> x >> y;
		queue<pair<int, int>> q;
		for (auto p : s[x])
		{
			if (p.second)
			{
				q.push({p.first, g[x] + g[y] + p.second});
				mp[p.first] = 0;
			}
		}
		while (!q.empty())
		{
			auto c = q.front();
			q.pop();
			if (l[c.first][y])
				ans = min(ans, c.second + l[c.first][y]);
			for (auto p : a[c.first])
			{
				if (c.second + p.second < mp[p.first])
				{
					mp[p.first] = c.second + p.second;
					q.push({p.first, mp[p.first]});
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
