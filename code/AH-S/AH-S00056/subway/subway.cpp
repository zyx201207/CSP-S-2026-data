#include <bits/stdc++.h>
using namespace std;
const int N = 510, M = 5e5 + 10;
int w[M], k[N], a[N][M], t[N][M];
bool vis[N];
int ans = 0x3f3f3f3f;
int c, n, m, d, q;
void dfs(int zd, int xl, int times, int tar)
{
	if (zd == tar)
	{
		ans = min(ans, times);
		return;
	}
	for (int i = 1; i <= k[xl]; i++)
	{
		if (!vis[a[xl][i]])
		{
			vis[a[xl][i]] = true;
			dfs(a[xl][i], xl, times, tar);
			//vis[a[xl][i]] = false;
		}
	}	
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (a[i][j] == zd)
			{
				dfs(a[i][j], i, times + w[zd] + t[i][j], tar);
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
		cin >> w[i];
	for (int i = 1; i <= n; i++)
	{
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++)
			cin >> a[i][j] >> t[i][j];
	}
	while (q--)
	{
		int x, y;
		cin >> x >> y;
		ans = 0x3f3f3f3f;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (a[i][j] == x) dfs(a[i][j], i, w[x] + t[i][j], y);
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
