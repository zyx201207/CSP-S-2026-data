#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 5e5 + 505;

int c, n, m, d, q, w[N], k[N], f[505][505], x, y;
vector<int> a[N], t[N];
vector<pair<int, int> > g[N];

signed main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios :: sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++) cin >> w[i];
	for(int i = 1; i <= n; i++)
	{
		cin >> k[i];
		a[i].resize(k[i] + 1);
		t[i].resize(k[i] + 1);
//		if(i == 3) cout << k[i] << '.';
		for(int j = 1; j <= k[i]; j++)
		{
			cin >> a[i][j] >> t[i][j];
			g[a[i][j]].push_back({i, t[i][j]}); // a[i][j] 这个站台在 i 这条线的管辖范围内 
		}
	}
	for(int i = 1; i <= n; i++)
	for(int j = i + 1; j <= n; j++)
		f[i][j] = f[j][i] = 2e18;
	for(int i = 1; i <= n; i++) f[i][i] = 0;

//	for(int i = 1; i <= m; i++, cout << '\n')
//	for(int j = 0; j < g[i].size(); j++) cout << g[i][j].first << ' ';
//	cout << '\n';
	
	for(int i = 1; i <= m; i++)
	{
		for(int j = 0; j < g[i].size(); j++)
		for(int k = 0; k < j; k++)
		{
			int x = g[i][j].first;
			int xw = g[i][j].second;
			int y = g[i][k].first;
			int yw = g[i][k].second;
//			if(x == 1 && y == 2)
			f[x][y] = min(f[x][y], xw + yw);
			f[y][x] = min(f[y][x], xw + yw);
		}
	}
	for(int k = 1; k <= n; k++)
	for(int i = 1; i <= n; i++)
	for(int j = 1; j <= n; j++)
		f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
//	cout<<f[1][2];
	while(q--)
	{
		cin >> x >> y;
		int ans = 2e18;
		for(auto p : g[x])
		for(auto q : g[y])
			ans = min(ans, w[x] + w[y] + p.second + q.second + f[p.first][q.first]);
		cout << ans << '\n';
	}
	return 0;
}

