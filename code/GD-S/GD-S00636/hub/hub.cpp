#include <bits/stdc++.h>
using namespace std;
const long long N = 1000006;
long long cc, t, n, k, dep[N], deps[N][2], fa[N], root1, root2, maxn, root, len[N], cnt[N], c[N];
vector <long long> e[N];
void dfs1(long long x)
{
	if (x != 1 && e[x].size() == 1)
	{
		deps[x][0] = 0;
		return;
	}
	for (auto i : e[x])
	{
		if (i == fa[x])
			continue;
		fa[i] = x;
		dep[i] = dep[x] + 1;
		dfs1(i);
		if (deps[i][0] + 1 > deps[x][0])
		{
			deps[x][1] = deps[x][0];
			deps[x][0] = deps[i][0] + 1;
		}
		else if (deps[i][0] + 1 > deps[x][1])
			deps[x][1] = deps[i][0] + 1;
	}
	return;
}
void dfs2(long long x, long long tf)
{
	len[x] = max(deps[x][0], deps[1][tf] + dep[x]);
	for (auto i : e[x])
	{
		if (i == fa[x])
			continue;
		if (x == 1 && deps[i][0] + 1 == deps[x][0])
			dfs2(i, 1);
		else
			dfs2(i, tf);
	}
	return;
}
void dfs3(long long x)
{
	c[x] = 1;
	if (x != root1 && e[x].size() == 1)
	{
		deps[x][0] = 0;
		return;
	}
	for (auto i : e[x])
	{
		if (i == fa[x] || (i == root1 && x == root2) || (i == root2 && x == root1))
			continue;
		fa[i] = x;
		dep[i] = dep[x] + 1;
		dfs3(i);
		if (deps[i][0] + 1 > deps[x][0])
		{
			deps[x][1] = deps[x][0];
			deps[x][0] = deps[i][0] + 1;
		}
		else if (deps[i][0] + 1 > deps[x][1])
			deps[x][1] = deps[i][0] + 1;
	}
	return;
}
void dfs4(long long x, long long tf)
{
	len[x] = max(deps[x][0], deps[root1][tf] + dep[x]);
	for (auto i : e[x])
	{
		if (i == fa[x] || (i == root1 && x == root2) || (i == root2 && x == root1))
			continue;
		if (x == root1 && deps[i][0] + 1 == deps[x][0])
			dfs4(i, 1);
		else
			dfs4(i, tf);
	}
	return;
}
void dfs5(long long x)
{
	c[x] = 2;
	if (x != root2 && e[x].size() == 1)
	{
		deps[x][0] = 0;
		return;
	}
	for (auto i : e[x])
	{
		if (i == fa[x] || (i == root1 && x == root2) || (i == root2 && x == root1))
			continue;
		fa[i] = x;
		dep[i] = dep[x] + 1;
		dfs5(i);
		if (deps[i][0] + 1 > deps[x][0])
		{
			deps[x][1] = deps[x][0];
			deps[x][0] = deps[i][0] + 1;
		}
		else if (deps[i][0] + 1 > deps[x][1])
			deps[x][1] = deps[i][0] + 1;
	}
	return;
}
void dfs6(long long x, long long tf)
{
	len[x] = max(deps[x][0], deps[root2][tf] + dep[x]);
	for (auto i : e[x])
	{
		if (i == fa[x] || (i == root1 && x == root2) || (i == root2 && x == root1))
			continue;
		if (x == root2 && deps[i][0] + 1 == deps[x][0])
			dfs6(i, 1);
		else
			dfs6(i, tf);
	}
	return;
}
void solve()
{
	scanf("%lld%lld", &n, &k);
	for (long long i = 1; i <= n; i++)
		e[i].clear();
	memset(deps, 0xc0, sizeof deps);
	memset(c, 0, sizeof c);
	memset(dep, 0, sizeof dep);
	memset(fa, 0, sizeof fa);
	for (long long i = 1, u, v; i < n; i++)
	{
		scanf("%lld%lld", &u, &v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs1(1);
	for (long long i = 1; i <= n; i++)
		deps[i][1] = max(deps[i][1], 0ll);
	dfs2(1, 0);
	maxn = LONG_LONG_MAX;
	for (long long i = 1; i <= n; i++)
	{
		if (maxn > len[i])
		{
			root = i;
			maxn = len[i];
		}
	}
	memset(dep, 0, sizeof dep);
	root1 = root;
	root2 = e[root][0];
	memset(deps, 0xc0, sizeof deps);
	memset(fa, 0, sizeof fa);
	dfs3(root1);
	dfs5(root2);
	for (long long i = 1; i <= n; i++)
		deps[i][1] = max(deps[i][1], 0ll);
	dfs4(root1, 0);
	dfs6(root2, 0);
	maxn = 0;
	for (long long i = 1; i <= n; i++)
	{
		if (maxn > len[i] && c[i] == 1)
		{
			root1 = i;
			maxn = len[i];
		}
	}
	maxn = 0;
	for (long long i = 1; i <= n; i++)
	{
		if (maxn > len[i] && c[i] == 2)
		{
			root2 = i;
			maxn = len[i];
		}
	}
	memset(dep, 0, sizeof dep);
	memset(deps, 0xc0, sizeof deps);
	dfs3(root1);
	dfs5(root2);
	long long minn = 0;
	for (long long i = 1; i <= n; i++)
		minn = max(minn, dep[i]);
	for (long long i = 1; i <= n; i++)
	{
		cnt[minn - dep[i]]++;
		maxn = max(maxn, minn - dep[i]);
	}
	root = 1;
	for (long long i = maxn; i > 0; i--)
	{
		if (k >= cnt[i])
			k -= cnt[i];
		else
		{
			root = i;
			break; 
		}
	}
	printf("%lld\n", root);
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%lld%lld", &cc, &t);
	while(t--)
		solve();
}
