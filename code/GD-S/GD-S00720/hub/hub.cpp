#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
const int INF = 1e9;

int c, T;
int n, k;
vector<int> G[N];

bool f[N];
int dis[N][N];

int fa[N];
int Find(int x)
{
	return fa[x] == x ? x : fa[x] = Find(fa[x]);
}

void Merge(int x, int y)
{
	int fx = Find(x), fy = Find(y);
	if (fx != fy)
		fa[fx] = fy;
}

int res;
bool vis[N];
void DFS(int u, int d, int &mind)
{
	if (vis[u]) return ;
	vis[u] = true;
	if (f[u])
	{
		mind = min(mind, d);
		return ;
	}
	
	for (auto v : G[u])
		DFS(v, d + 1, mind);
}

bool link[N][N];
int dis7[N];
void DFS7(int u, int d)
{
	if (d > dis7[u]) return ;
	dis7[u] = min(dis7[u], d);
	
	for (auto v : G[u])
		DFS7(v, d + 1);
}

int main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	cin >> c >> T;
	while (T -- )
	{
		res = INF;
		
		cin >> n >> k;
		for (int i = 1; i <= n; i ++ ) G[i].clear();
		if (c == 7)
		{
			for (int i = 1; i <= n; i ++ )
				for (int j = 1; j <= n; j ++ )
					link[i][j] = false;
		}
		for (int i = 1; i < n; i ++ )
		{
			int u, v; cin >> u >> v;
			G[u].push_back(v), G[v].push_back(u);
			if (c == 7) link[u][v] = link[v][u] = true;
		}
		
		if (c <= 3)
		{
			for (int mask = 1; mask < (1 << n); mask ++ )
			{
				for (int i = 1; i <= n; i ++ )
				{ 
					f[i] = false;
					fa[i] = i;
					for (int j = 1; j <= n; j ++ )
						if (i != j)
							dis[i][j] = INF;
						else
							dis[i][j] = 0;
				}
				
				int t = 0;
				for (int i = 1; i <= n; i ++ )
					if (mask >> (i - 1) & 1)
					{
						t ++ ;
						f[i] = true;
					}
				if (t != k) continue;
				
				for (int u = 1; u <= n; u ++ )
					if (f[u])
						for (int v : G[u])
							if (f[v])
								Merge(u, v);
				t = 0;
				for (int u = 1; u <= n; u ++ )
					if (f[u] && fa[u] == u)
						t ++ ;
				if (t != 2) continue;
				
				int maxd = -INF;
				for (int u = 1; u <= n; u ++ )
					if (!f[u])
					{
						for (int v = 1; v <= n; v ++ ) vis[v] = false;
						int d = INF;
						DFS(u, 0, d);
						maxd = max(maxd, d);
					}
				res = min(res, maxd);
			}
		}
		else if (c == 7)
		{
			for (int u = 1; u <= n; u ++ )
				for (int v = u + 1; v <= n; v ++ )
				{
					if (link[u][v]) continue;
					for (int i = 1; i <= n; i ++ ) dis7[i] = INF;
					DFS7(u, 0);
					DFS7(v, 0);
					
					int maxd = -INF;
					for (int i = 1; i <= n; i ++ )
						maxd = max(maxd, dis7[i]);
					res = min(res, maxd);
				}
		}
		
		cout << res << '\n';
	}

	return 0;
}

