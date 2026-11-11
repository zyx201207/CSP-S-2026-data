#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10, inf = 1e9;
int c;

int n, k;
int head[N], to[2*N], nxt[2*N], cn;
void add(int x, int y)
{
	to[++cn] = y;
	nxt[cn] = head[x];
	head[x] = cn;
}

bool vis[N];
int val[N];
int mdep[N];
int ans;

int dfs1(int x, int fa)
{
	int sum = vis[x];
	for (int i = head[x]; i; i = nxt[i])
	{
		int go = to[i];
		if (go == fa)
			continue ;
		int v = dfs1(go, x);
		if (vis[x] && vis[go])
			--v;
		sum += v;
	}
	return sum;
}

void dfs2(int x, int fa, int d)
{
//	cerr << x << ' ' << fa << ' ' << d << '\n';
	mdep[x] = inf;
	if (vis[x] == 1)
		val[x] = mdep[x] = 0;
	else
		val[x] = d;
	for (int i = head[x]; i; i = nxt[i])
	{
		int go = to[i];
		if (go == fa)
			continue ;
		if (vis[x] == 0)
			dfs2(go, x, d + 1);
		else
			dfs2(go, x, 1);
		mdep[x] = min(mdep[x], mdep[go] + 1);
	}
	if (vis[x] == 0)
		val[x] = min(val[x], mdep[x]);
}

void dfs(int x, int s, bool fl)
{
	if (fl)
	{
		if (x > n)
		{
			for (int i = 1; i <= n; ++i)
				vis[i] ^= 1;
			if (dfs1(1, 1) > 2)
				return ;
			dfs2(1, 1, inf);
			int maxn = 0;
			for (int i = 1; i <= n; ++i)
				maxn = max(maxn, val[i]);
			ans = min(ans, maxn);
//			if (maxn == 1)
//			{
//				
//			}
			return ;
		}
		if (s + n - x >= n - k + 1)
		{
			vis[x] = 0;
			dfs(x+1, s, fl);
		}
		if (s < n - k + 1)
		{
			vis[x] = 1;
			dfs(x+1, s+1, fl);
		}
	}
	else
	{
		if (x > n)
		{
			if (dfs1(1, 1) > 2)
				return ;
			dfs2(1, 1, inf);
			int maxn = 0;
			for (int i = 1; i <= n; ++i)
				maxn = max(maxn, val[i]);
//			if (maxn == 1)
//			{
//				for (int i = 1; i <= n; ++i)
//					cerr << vis[i] << ' ';
//				cerr << '\n';
//			}
			ans = min(ans, maxn);
			return ;
		}
		if (s + n - x >= k)
		{
			vis[x] = 0;
			dfs(x+1, s, fl);
		}
		if (s < k)
		{
			vis[x] = 1;
			dfs(x+1, s+1, fl);
		}
	}
}

void solve()
{
	ans = inf;
	cin >> n >> k;
	for (int i = 1; i < n; ++i)
	{
		int u, v;
		cin >> u >> v;
		add(u, v);
		add(v, u);
	}
	
	if (k <= n - k)
		dfs(1, 0, 0);
	else
		dfs(1, 0, 1);
	cout << ans << '\n';
	
	for (int i = 1; i <= n; ++i)
		head[i] = 0;
	cn = 0;
}

signed main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout); 
	int T;
	cin >> c >> T;
	while (T--)
		solve();
	return 0;
}
