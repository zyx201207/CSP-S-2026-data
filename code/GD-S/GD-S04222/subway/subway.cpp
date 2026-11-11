#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
int c, n, m, d, q, w[500005], k, a[500005], t[500005], x, y;
vector<pair<int, int>> g[500005];
int dis[500005];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
bool vis[500005];
int dijs()
{
	memset(dis, 0x3f3f3f, sizeof(dis));
	while(!pq.empty()) pq.pop();
	memset(vis, 0, sizeof(vis));
	vis[x] = 1;
	dis[x] = 0;
	pq.push({0, x});
//	printf("x=%d, y=%d, get ready\n", x, y);
	while(!pq.empty())
	{
		int w = pq.top().fi, u = pq.top().se;
		pq.pop();
		for(int i = 0; i < g[u].size(); i++)
		{
//			printf("u=%d, w=%d, i=%d, g[u][i]={%d, %d}\n", u, w, i, g[u][i].fi, g[u][i].se);
			if(vis[g[u][i].se]) continue;
			if(w + g[u][i].fi < dis[g[u][i].se])
			{
				dis[g[u][i].se] = w + g[u][i].fi;
//				printf("dis[%d] refreshed:%d\n", g[u][i].se, dis[g[u][i].se]);
				pq.push({dis[g[u][i].se], g[u][i].se});
			}
		}
		vis[u] = 1;
	}
	return dis[y];
}
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i = 1; i <= m; i++) cin>>w[i];
	for(int i = 1; i <= n; i++)
	{
		cin>>k;
		for(int j = 1; j <= k; j++) cin>>a[j]>>t[j];
		for(int j = 1; j < k; j++)
		{
			for(int kk = j + 1; kk <= k; kk++)
			{
				g[a[j]].push_back({t[j] + t[kk], a[kk]});
				g[a[kk]].push_back({t[j] + t[kk], a[j]});
			}
		}
	}
	for(int i = 1; i <= q; i++)
	{
		cin>>x>>y;
		cout<<dijs() + w[x] + w[y]<<'\n';
	}
	return 0;
}
