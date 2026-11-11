#include <bits/stdc++.h>
#define int long long
using namespace std;
int g[505][505], w[500005], k[505];
vector<int> a[505], t[505];
void read(int& e)
{
	e = 0;
	char c = getchar_unlocked();
	while (!isdigit(c) && c != '-') c = getchar_unlocked();
	bool f = 0;
	if (c == '-') f = 1, c = getchar_unlocked();
	while (isdigit(c)) e = (e << 3) + (e << 1) + (c - '0'), c = getchar();
	if (f) e = -e;
}
vector<pair<int, int>> x[500005];
signed main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	memset(g, 0x3f, sizeof(g));
	int c, m, n, d, q; read(c), read(n), read(m), read(d), read(q);
	for (int i = 1; i <= m; ++i) read(w[i]);
	for (int i = 1; i <= n; ++i)
	{
		g[i][i] = 0;
		read(k[i]);
		a[i].resize(k[i] + 1);
		t[i].resize(k[i] + 1);
		for (int j = 1; j <= k[i]; ++j)
		{
			read(a[i][j]); read(t[i][j]);
			x[a[i][j]].push_back({i, t[i][j]});
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= k[i]; ++j)
		{
			for (auto& e : x[a[i][j]])
				if (e.first != i)
					g[e.first][i] = g[i][e.first] = min(g[i][e.first], t[i][j] + e.second);
		}
	}
	for (int k = 1; k <= n; ++k)
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
	cout.tie(0)->sync_with_stdio(0);
	while (q--)
	{
		int x, y; read(x), read(y);
		long long ans = LLONG_MAX;
		for (auto& e : ::x[x])
			for (auto& f : ::x[y])
			{
				ans = min(ans, g[e.first][f.first] + e.second + f.second);
			}
		cout << ans + w[x] + w[y] << "\n";
	}
	return 0;
}
