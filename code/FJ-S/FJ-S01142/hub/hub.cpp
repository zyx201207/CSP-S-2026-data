#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e3 + 10;

int h[N], e[N], ne[N], idx, siz[N];
int fa[N][11], dep[N], mk[N];
int n, k;
int uu[N], vv[N];
void add(int a, int b)
{
	e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

void dfs(int u, int fat)
{
	dep[u] = dep[fat] + 1;
	fa[u][0] = fat;
	for(int i = 1; i <= 10; i ++ )
		fa[u][i] = fa[fa[u][i - 1]][i - 1];
	for(int i = h[u]; ~i; i = ne[i])
	{
		int j = e[i];
		if(j == fat)
			continue;
		dfs(j, u);
	}	
} 
int f[N], vis[N];

int find(int x)
{
	if(f[x] == x)
		return x;
	return (f[x] = find(f[x]));
}

int LCA(int u, int v)
{
	if(dep[u] < dep[v])
		swap(u, v);
	for(int i = 10; i >= 0; i -- )
		if(dep[fa[u][i]] >= dep[v])	
			u = fa[u][i];
	if(u == v)
		return u;
	for(int i = 10; i >= 0; i -- )
		if(fa[u][i] != fa[v][i])
			u = fa[u][i], v = fa[v][i];
	return fa[u][0];
} 


signed main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int cc, t;
	cin >> cc >> t;
	while(t -- )
	{
		cin >> n >> k;
		idx = 0;
		for(int i = 1; i <= n; i ++ )
			h[i] = -1;
		for(int i = 1; i <= n; i ++ )
			for(int j = 0; j <= 10; j ++ )
				fa[i][j] = 0;
		for(int i = 1; i < n; i ++ )
		{
			int u, v;
			cin >> u >> v;
			add(u, v), add(v, u); 
			uu[i] = u, vv[i] = v;
		}	
		dfs(1, 0);
		int res = 0x3f3f3f3f;
		
		for(int i = 0; i < (1 << n); i ++ )
		{
			for(int j = 1; j <= n; j ++ )
				f[j] = j, mk[j] = 0, vis[j] = 0, siz[j] = 0;
			int cnt = 0;
			for(int j = 0; j < n; j ++ )
				if((i >> j & 1) == 1)
					cnt ++ , mk[j + 1] = 1, siz[j + 1] = 1;
			if(cnt != k)
				continue;
			int now = 0;
			for(int j = 1; j < n; j ++ )
			{
				if(mk[uu[j]] && mk[vv[j]])
				{
					int fu = find(uu[j]), fv = find(vv[j]);
					f[fu] = fv;
					siz[fv] += siz[fu];
				}
			}
			int cont = 0;
			for(int j = 1; j <= n; j ++ )
			{
				int fj = find(j);
				if(siz[fj] >= 1 && !vis[fj])
					cont ++ , vis[fj] = 1;
			}
			if(cont <= 2)
			{
				int ans = -0x3f3f3f3f;
				for(int i = 1; i <= n; i ++ )
				{
					int nowans = 0x3f3f3f3f;
					for(int j = 1; j <= n; j ++ )
					{
						if(mk[j])
						{
							int nowdis = dep[i] + dep[j] - 2 * dep[LCA(i, j)];
							nowans = min(nowans, nowdis);
						} 
					}
					ans = max(ans, nowans);
				}
				res = min(res, ans);
			}
		}
		cout << res << endl;
	}
	return 0;
}
