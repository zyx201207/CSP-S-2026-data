#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 5;

bool is[MAXN]; int c, t, dep[MAXN], fa[MAXN]; vector <int> G[MAXN];

void dfs(int u, int f)
{
	for (int v : G[u])
	{
		if (v == f) continue; dep[v] = dep[u] + 1; dfs(v, u);
	}
}

int find(int x)
{
	if (x == fa[x]) return x; return fa[x] = find(fa[x]);
}

void merge(int x, int y)
{
	int rx = find(x), ry = find(y); if (rx != ry) fa[ry] = rx;
}

int main()
{
	freopen("hub.in", "r", stdin); freopen("hub.out", "w", stdout);
	
	cin >> c >> t;
	
	while (t --)
	{
		int k, n; cin >> n >> k;
		
		for (int i = 1; i <= n; i ++) G[i].clear();
		
		for (int i = 1; i <= n - 1; i ++)
		{
			int u, v; cin >> u >> v;
			
			G[u].push_back(v); G[v].push_back(u);
		}
		
		int ans = n - 1;
		
		for (int S = 1; S <= (1 << n) - 1; S ++)
		{
			if (__builtin_popcount(S) != k) continue;
			
			for (int i = 1; i <= n; i ++)
			{
				is[i] = 0; fa[i] = i;
			}
			
			vector <int> vec;
			
			for (int i = 1; i <= n; i ++)
			{
				if (S & (1 << (i - 1)))
				{
					vec.push_back(i); is[i] = 1;
				}
			}
			
			for (int x : vec)
			{
				for (int y : G[x])
				{
					if (is[y]) merge(x, y);
				}
			}
			
			unordered_set <int> ust; for (int x : vec) ust.insert(find(x));
			
			if (ust.size() > 2) continue;
			
			int cur = 0;
			
			for (int i = 1; i <= n; i ++)
			{
				if (is[i]) continue;
				
				for (int j = 1; j <= n; j ++) dep[j] = 0;
				
				dfs(i, 0);
				
				int tmp = n - 1; for (int j = 1; j <= n; j ++) if (is[j]) tmp = min(tmp, dep[j]);
				
				cur = max(cur, tmp);
			}
			
			ans = min(ans, cur);
		}
		
		cout << ans << "\n";
	}
	
	return 0;
}
