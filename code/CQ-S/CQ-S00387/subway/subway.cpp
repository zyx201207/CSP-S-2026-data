#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<pair<int, int> > a[500005];
int c, n, m, d, q, x, y, z, s, w[500005], f[505][505];
signed main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			f[i][j] = 1e18;
		}
		f[i][i] = 0;
	}
	for (int i = 1; i <= m; i++)
	{
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> x;
		for (int j = 1; j <= x; j++)
		{
			cin >> y >> z;
			a[y].push_back({i, z});
		}
	}
	for (int i = 1; i <= m; i++)
	{
		for (int j = 0; j < (int)a[i].size(); j++)
		{
			int x = a[i][j].first, z = a[i][j].second;
			for (int k = j + 1; k < (int)a[i].size(); k++)
			{
				int xx = a[i][k].first, zz = a[i][k].second;
				f[x][xx] = min(f[x][xx], z + zz);
				f[xx][x] = min(f[xx][x], z + zz);
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			for (int k = 1; k <= n; k++)
			{
				f[i][k] = min(f[i][k], f[i][j] + f[j][k]);
			}
		}
	}
	while (q--)
	{
		cin >> x >> y;
		s = LONG_LONG_MAX;
		for (int i = 0; i < (int)a[x].size(); i++)
		{
			for (int j = 0; j < (int)a[y].size(); j++)
			{
				s = min(s, f[a[x][i].first][a[y][j].first] + a[x][i].second + a[y][j].second);
			}
		}
		cout << s + w[x] + w[y] << "\n";
	}
	return 0;
}
