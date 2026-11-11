#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 1e18, N = 5e5 + 5;
int a[505], t[505], b[505][505], w[N], ans, c, n, m, d, q, vis[505], anss;
vector<int> g[N], ch[N];
void dfs(int x, int y, int l)
{
	if (x == y)
	{
		ans = min(ans, l);
		return;
	}
	for (int i = 1; i <= m; i++)
	{
		if (vis[i] == false && l + b[x][i] < ans)
		{
			vis[i] = true;
			dfs(i, y, l + b[x][i]);
			vis[i] = false;
		}
	}
}
void dfss(int x, int y, int l)
{
	if (x == y)
	{
		anss = min(anss, l);
		return;
	}
	for (int i = 0; i < g[x].size(); i++)
	{
		if (vis[g[x][i]] == false && l + ch[x][i] < anss)
		{
			vis[g[x][i]] = true;
			dfss(g[x][i], y, l + ch[x][i]);
			vis[g[x][i]] = false;
		}
	}
}
signed main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
	{
		cin >> w[i];
	}
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			b[i][j] = maxn;
		}
	}
	if (n > 50)
	{
		while (n--)
		{
			int k;
			cin >> k;
			if (k == 2)
			{
				int aa, bb, cc, dd;
				cin >> aa >> bb >> cc >> dd;
				g[aa].push_back(cc);
				ch[aa].push_back(bb + dd);
				g[cc].push_back(aa);
				ch[cc].push_back(bb + dd);
			}
		}
		while (q--)
		{
			int xi, yi;
			cin >> xi >> yi;
			anss = maxn;
			vis[xi] = true;
			dfss(xi, yi, 0);
			vis[xi] = false;
			cout << anss + w[xi] + w[yi] << endl;
		}
		return 0;
	}
	while (n--)
	{
		int k;
		cin >> k;
		for (int i = 1; i <= k; i++)
		{
			cin >> a[i] >> t[i];
		}
		for (int i = 1; i < k; i++)
		{
			for (int j = i + 1; j <= k; j++)
			{
				b[a[i]][a[j]] = min(b[a[i]][a[j]], t[i] + t[j]);
				b[a[j]][a[i]] = min(b[a[j]][a[i]], t[i] + t[j]);
			}
		}
	}
	while (q--)
	{
		int x, y;
		cin >> x >> y;
		ans = maxn;
		vis[x] = true;
		dfs(x, y, 0);
		vis[x] = false;
		cout << b[x][y] + w[x] + w[y] << endl;
	}
	return 0;
}
