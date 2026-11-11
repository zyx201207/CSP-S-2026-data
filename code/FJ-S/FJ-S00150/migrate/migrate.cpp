#include <bits/stdc++.h>
using namespace std;

const int N = 2e6 + 5;
int n, d; long long ans, x[N], cnt[N], dist[N]; bool vis[N];
typedef pair <long long, int> pii;
vector <int> e[N];

void Dijkstra(int s)
{
	long long tot = 0;
	for (int i = 1; i <= n; i ++) dist[i] = 1e18;
	memset(vis, false, sizeof vis);
	memset(cnt, 0, sizeof cnt);
	
	priority_queue <pii, vector <pii>, greater <pii>> q;
	dist[s] = 0; q.push({dist[s], s});
	cnt[s] = 1;
	while (!q.empty())
	{
		pii u = q.top(); q.pop();
		if (vis[u.second] || u.first != dist[u.second]) continue;
		vis[u.second] = true;
		
		for (int i = 0; i < e[u.second].size(); i ++)
		{
			int v = e[u.second][i];
			if (dist[v] > u.first + 1)
			{
				cnt[v] = cnt[u.second];
				dist[v] = u.first + 1;
				q.push({dist[v], v}); 
				continue;
			}
			if (dist[v] == u.first + 1) cnt[v] += cnt[u.second];
		} 
	}
	
	for (int i = 1; i <= n; i ++)
		if (cnt[i] == 2)
			tot ++;
	ans += tot;
}

int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout); 
	
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int c, t;
	cin >> c >> t;
	while (t --)
	{
		ans = 0;
		cin >> n >> d;
		for (int i = 1; i <= n; i ++) e[i].clear();
		for (int i = 1; i <= n; i ++) cin >> x[i];
		for (int i = 1; i <= n; i ++)
			for (int j = 1; j <= n; j ++)
				if (i != j && abs(x[i] - x[j]) <= d) e[i].push_back(j);				
				
		for (int i = 1; i <= n; i ++) Dijkstra(i);
		cout << ans / 2 << "\n";
	}
	return 0;
} 
