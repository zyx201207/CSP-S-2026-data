#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 2000010;

int n, k;
vector <int> edge[N];

namespace From_1_to_3
{
	struct DSU
	{
		int fa[N];
		inline void init (const int &n)
		{
			for (int i = 1; i <= n; i++)
				fa[i] = i;
		}
		inline int find (const int &x)
		{
			if (fa[x] == x) return fa[x];
			return fa[x] = find(fa[x]);
		}
		inline void merge (const int &x, const int &y)
		{
			int fx = find(x), fy = find(y);
			fa[fx] = fy;
		}
	} dsu;
	int dis[N]; bool vis[N];
	inline void dfs (const int &u, const int &fa, const int &dep)
	{
		dis[u] = min(dis[u], dep);
		for (auto v : edge[u])
			if (v != fa)
				dfs(v, u, dep + 1);
	}
	inline void clear ()
	{
		for (int i = 1; i <= n; i++) edge[i].clear();
	}
	inline void solve ()
	{
		clear();
		scanf("%lld %lld", &n, &k);
		for (int i = 1; i < n; i++)
		{
			int u, v; scanf("%lld %lld", &u, &v);
			edge[u].push_back(v); edge[v].push_back(u);
		}
		
		int Ans = 998244353;
		for (int i = 0; i < (1 << n); i++)
		{
			if (__builtin_popcount(i) != k) continue;
			dsu.init(n);
			for (int j = 0; j < n; j++)
			{
				if (((i >> j) & 1) == 0) continue;
				int u = j + 1;
				for (auto v : edge[u])
					if ((i >> (v - 1)) & 1)
						dsu.merge(u, v);
			}
			
			for (int j = 1; j <= n; j++) vis[j] = 0;
			for (int j = 1; j <= n; j++)
				if ((i >> (j - 1)) & 1)
					vis[dsu.find(j)] = 1;
			
			int tot = 0;
			for (int j = 1; j <= n; j++) if ((i >> (j - 1)) & 1) if (vis[j] == 1) tot++;
			if (tot > 2) continue;
			
			for (int j = 1; j <= n; j++) dis[j] = 998244353;
			for (int j = 1; j <= n; j++)
				if ((i >> (j - 1)) & 1)
					dfs(j, j, 0);
			
			int Max = 0;
			for (int j = 1; j <= n; j++)
				Max = max(Max, dis[j]);
			Ans = min(Ans, Max);
		}
		printf("%lld\n", Ans);
	}
}

int c, T;
signed main ()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	scanf("%lld %lld", &c, &T);
	while (T--) From_1_to_3::solve();
	return 0;
}
// Only feels like nothing could be better when I with you, when I with you ~ 
// Dancing all night pray we're next together it's a breakthough, it's a breakthough ~
