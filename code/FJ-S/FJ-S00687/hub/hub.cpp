#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 20;
int c, T;
int n, k, ans;
vector<int> G[N]; 
bool chos[N];
int fa[N], f[N][20];
int dis[N];
int find(int x)
{
	if (fa[x] == x) return x;
	return fa[x] = find(fa[x]); 
} 
int lca(int x, int y)
{
	if (dis[x] < dis[y]) swap(x, y);
//	cout << x << ' ' << y << '\n';
	for (int i = 10; i >= 0; i--) if (dis[f[x][i]] >= dis[y]) x = f[x][i];
	if (x == y) return x;
	for (int i = 10; i >= 0; i--) if (f[x][i] != f[y][i]) x = f[x][i], y = f[y][i];
	return f[x][0];
}
void dfs(int pos, int k)
{
	if (pos > n || k == 0)
	{
		for (int i = 1; i <= n; i++) fa[i] = i;
		for (int i = 1; i <= n; i++)
		{
			if (chos[i])
			{
				for (int j : G[i])
				{
					if (chos[j])
					{
						if (find(i) != find(j)) fa[find(i)] = find(j);
					}
				}
			}
		}
		int cnt = 0, p1 = 0, p2 = 0;
		for (int i = 1; i <= n; i++)
		{
			if (chos[i])
			{
				int x = find(i);
				if (p1 == 0 || p1 == x) p1 = x;
				else
				{
					if (p2 == 0 || p2 == x) p2 = x;
					else return;
				}
			}
		}
		
		int mx = 0;
		for (int i = 1; i <= n; i++)
		{
			if (!chos[i])
			{
				int mi = 1e9;
				for (int j = 1; j <= n; j++)
					if (chos[j])
						mi = min(mi, dis[i] + dis[j] - 2*dis[lca(i, j)]);
				mx = max(mx, mi);
			}
		}
		ans = min(ans, mx);
		return;	
	}
	
	chos[pos] = 0;
	dfs(pos + 1, k);
	
	if (k > 0)
	{
		chos[pos] = 1;
		dfs(pos + 1, k-1);
	}
	chos[pos] = 0;
 } 
void pre(int u, int fat)
{
	f[u][0] = fat;
	for (int i = 1; i <= 10; i++) f[u][i] = f[f[u][i-1]][i-1];
	
	for (int v : G[u])
	{
		if (v != fat)
		{
			dis[v] = dis[u] + 1;
			pre(v, u);
		 } 
	}
}
void baoli()
{
	memset(f, 0, sizeof f);
	memset(dis, 0, sizeof dis);
	dis[1] = 1;
	pre(1, 0);
//	cout << lca(1, 2) << '\n';
	
	ans = 1e9; 
	dfs(1, k);
	cout << ans << '\n';
}
int main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> c >> T;
	while (T--)
	{
		cin >> n >> k;
		for (int i = 1; i <= n; i++) G[i].clear();
		for (int i = 1, u, v; i < n; i++)
		{
			cin >> u >> v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		
		
		baoli();
	}
	return 0;
 }

