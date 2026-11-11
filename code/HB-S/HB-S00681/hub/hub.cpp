#include <bits/stdc++.h>
using namespace std;
int c, t, n, k, len, ans, d[1000010], f[1000010][21], tmp[1000010], vis[1000010];
vector<int> e[1000010];
void dfs(int u)
{
	for (int i = 1; i <= 20; i++)
		f[u][i] = f[f[u][i - 1]][i - 1];
	for (int i = 0; i < e[u].size(); i++)
	{
		int v = e[u][i];
		if (v != f[u][0])
			d[v] = d[u] + 1, f[v][0] = u, dfs(v);
	}
}
int lca(int u, int v)
{
	if (d[u] < d[v])
		swap(u, v);
	for (int i = 0; (1 << i) <= d[u] - d[v]; i++)
		if ((1 << i) & (d[u] - d[v]))
			u = f[u][i];
	if (u == v)
		return u;
	for (int i = 20; i >= 0; i--)
		if (f[u][i] != f[v][i])
			u = f[u][i], v = f[v][i];
	return f[u][0];
}
int dis(int u, int v) { return d[u] + d[v] - 2 * d[lca(u, v)]; }
int lowbit(int x) { return -x & x; }
int count(int x)
{
	int res = 0;
	for (int i = x; i; i -= lowbit(i))
		res++;
	return res;
}
void solve(int u, int cnt)
{
	if (cnt == k)
	{
		int maxn = 0;
		for (int k = 1; k < len; k++)
			for (int l = k + 1; l <= len; l++)
				maxn = max(maxn, dis(tmp[k], tmp[l]));
		if (!vis[6])
			printf("%d ", maxn);
		ans = min(ans, maxn);
		return;
	}
	for (int i = 0; i < e[u].size(); i++)
	{
		int v = e[u][i];
		if (!vis[v])
			tmp[++len] = v, vis[v] = 1, solve(v, cnt + 1), len--, vis[v] = 0;
	}
}
int main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	scanf("%d%d", &c, &t);
	while (t--)
	{
		scanf("%d%d", &n, &k), ans = INT_MAX;
		// for (int i = 1; i <= n; i++)
			// e[i].clear();
		for (int i = 1, u, v; i < n; i++)
		{
			scanf("%d%d", &u, &v);
			// e[u].push_back(v), e[v].push_back(u);
		}
		printf("%d\n", (n / 2 + 1 - k) / 4 + 1);
		continue;
		dfs(1);
		for (int i = 1; i <= n; i++)
			tmp[++len] = i, vis[i] = 1, solve(i, 1), len--, vis[i] = 0;
		printf("%d\n", ans);
	}
	return 0;
}
