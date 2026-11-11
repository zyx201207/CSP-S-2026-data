#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2e6 + 5;
int c, t, n, d, x[N], vis[N], ans, minn = 1e9, cnt;
vector<int> g[N];

void dfs(int u, int e, int f)
{
	if (u == e) 
	{
		if (f < minn) minn = f, cnt = 1;
		else if (f == minn) cnt++;
		return;
	}
	if (cnt > 2) return;
	vis[u] = 1;
	for (int v : g[u])
		if (!vis[v])
			dfs(v, e, f + 1);
	vis[u] = 0;	
}

int check(int u, int v)
{
	fill(vis + 1, vis + n + 1, 0);
	minn = 1e9, cnt = 0;
	dfs(u, v, 0);
	return cnt == 2;
}

void solve()
{
	cin >> n >> d;
	for (int i = 1; i <= n; i++) g[i].clear(); 	
	for (int i = 1; i <= n; i++) cin >> x[i];
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
			if (llabs(x[i] - x[j]) <= d)
				g[i].push_back(j);
	ans = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j) continue;
			ans += check(i, j);
		}
	}
	cout << ans << "\n";
}

signed main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> t;
	while (t--) solve();
	return 0;
}
