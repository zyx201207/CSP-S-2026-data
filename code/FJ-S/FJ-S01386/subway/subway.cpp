#include <bits/stdc++.h>
using namespace std;

#define MAXM 500005
vector<pair<int, long long> > g[MAXM];

long long w[MAXM];
long long dis[MAXM], ans[100005];
int c, n, m, d, q;
#define inf 0x3f3f3f3f3f3f3f3f

struct node
{
	int u;
	long long d;
	bool operator<(const node& o) const 
	{
		return d > o.d;
	}
};

struct query
{
	int x, y;
}Q[100005];
vector<int> sta[505];

void dij(int s)
{
	for (int i = 1; i <= m + n; i++) dis[i] = inf; 
	priority_queue<node> pq;
	dis[s] = 0;
	pq.push({s, 0});
	
	while (!pq.empty())
	{
		auto now = pq.top(); pq.pop();
		int u = now.u;
		if (dis[u] < now.d) continue;
		
		for (auto it : g[u])
		{
			int v = it.first;
			int w = it.second;
			if (dis[v] > dis[u] + w) 
			{
				dis[v] = dis[u] + w;
				pq.push({v, dis[v]});
			}
		}
	}
}

int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) cin >> w[i]; 	
	for (int i = 1; i <= n; i++)
	{
		int k;
		cin >> k;
		for (int j = 1; j <= k; j++)
		{
			int a, t;
			cin >> a >> t;
			g[a].push_back({m + i, t});
			g[m + i].push_back({a, t});
		}
	}
	for (int i = 1; i <= q; i++)
	{
		ans[i] = inf;
		cin >> Q[i].x >> Q[i].y;
		
		for (auto it: g[Q[i].x]) 
		{
			int v = it.first;
			sta[v - m].push_back(i);
		}
	}
			
	for (int i = 1; i <= n; i++) 
	{
		dij(m + i);	
		for (auto id : sta[i]) 
			ans[id] = min(ans[id], dis[Q[id].x] + dis[Q[id].y]); 
	}
	for (int i = 1; i <= q; i++) cout << ans[i] + w[Q[i].x] + w[Q[i].y] << "\n";
	return 0;
}
