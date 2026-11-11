#include <bits/stdc++.h>
using namespace std;

long long c, t;
vector<long long> T[1000001];

void dfs(vector<long long>& a, vector<bool>& vis, long long u, long long w)
{
	a[u] = min(a[u], w);
	
	for (long long e : T[u])
	{
		if (vis[e])
		{
			vis[e] = false;
			
			dfs(a, vis, e, w + 1);
		}
	}
}

int main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	
	vector<long long> S;
	
	cin >> c >> t;
	
	while (t--)
	{
		long long n, k, ans = 1000001;
		
		cin >> n >> k;
		
		for (long long i = 1; i < n; ++i)
		{
			long long u, v;
			
			cin >> u >> v;
			
			T[u].push_back(v);
			T[v].push_back(u);
		}
		
		for (long long i = 1; i <= n; ++i)
		{
			for (long long j = 1; j <= n; ++j)
			{
				vector<long long> a(n + 1, 1000001);
				vector<bool> vis1(n + 1, true), vis2(n + 1, true);
				long long maxx = 0;
				
				dfs(a, vis1, i, 0);				
				dfs(a, vis2, j, 0);
				
				for (long long k = 1; k <= n; ++k)
				{					
					maxx = max(maxx, a[k]);
				}
								
				ans = min(ans, maxx);
			}
		}
		
		cout << ans << "\n";
	}
	
	return 0;
}
