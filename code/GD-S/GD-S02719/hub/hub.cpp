#include <bits/stdc++.h>
using namespace std;

int c, t, n, k, fa[1000005][25], a[1000005], dep[1000005], ans = 1e9;
vector <int> g[1000005];
bool used[1000005], vis[1000005];

void dfs1(int u, int f)
{
	dep[u] = dep[f] + 1;
	fa[u][0] = f;
	for (int i = 1; i <= 20; i++)
		fa[u][i] = fa[fa[u][i - 1]][i - 1];
	for (int v: g[u])
		if (v != f)
			dfs1(v, u);
}

int LCA(int u, int v)
{
	if (dep[u] < dep[v])
		return LCA(v, u);
	for (int i = 0; i <= 20; i++)
	{
		if (dep[fa[u][i]] == dep[v])
		{
			u = fa[u][i];
			break;
		}
		if (dep[fa[u][i]] > dep[v])
			u = fa[u][i];
	}
	if (u == v)
		return u;
	for (int i = 20; i >= 0; i--)
	{
		if (fa[u][i] != fa[v][i])
			u = fa[u][i], v = fa[v][i];
	}
	return fa[u][0];
}

int dis(int u, int v)
{
	return -2 * dep[LCA(u, v)] + dep[u] + dep[v];
}

void dfs2(int u, int fa)
{
	if (!used[u])
		return ;
	vis[u] = true;
	for (int v: g[u])
		if (v != fa)
			dfs2(v, u);
}

void solve(int step)
{
	if (step > k)
	{
		memset(vis, 0, sizeof vis);
		int cnt = 0;
		for (int i = 1; i <= k; i++)
		{
			if (!vis[a[i]])
			{
				cnt++;
				dfs2(a[i], 0);
			}
		}
		if (cnt > 2)
			return ;
		int t = 0;
//		for (int i = 1; i <= k; i++)
//			printf("%d ", a[i]);
//		printf(": ");
		for (int i = 1; i <= n; i++)
		{
			int x = 1e9;
			for (int j = 1; j <= k; j++)
				x = min(x, dis(a[j], i));
//			printf("%d ", x);
			t = max(t, x);
		}
//		printf("\n");
		ans = min(ans, t);
		return ;
	}
	for (int i = a[step - 1] + 1; i <= n; i++)
	{
		a[step] = i;
		used[a[step]] = true;
		solve(step + 1);
		used[a[step]] = false;
	}
}

void Main()
{
	scanf("%d%d", &n, &k);
	ans = 1e9;
	for (int i = 1; i <= n; i++)
		g[i].clear();
	memset(a, 0, sizeof a);
	memset(fa, 0, sizeof fa);
	memset(used, 0, sizeof used);
	memset(dep, 0, sizeof dep);
	for (int i = 1; i < n; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs1(1, 0);
	solve(1);
//	printf("%d\n", dis(1, 8));
	printf("%d\n", ans);
}

int main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	scanf("%d%d", &c, &t);
	while (t--)
		Main();
	return 0;
}
