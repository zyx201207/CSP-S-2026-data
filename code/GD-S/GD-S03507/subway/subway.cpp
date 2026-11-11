#include <bits/stdc++.h>
#define int long long
using namespace std;
int c, n, m, d, q;
int w[500005], dist[505][505];
vector<pair<int,int> > g[550005], g2[505];
priority_queue<pair<int,int> > pq;
int dis[550005], vis[550005], cnt;
void dij(int x)
{
	cnt = 0;
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	while(!pq.empty()) pq.pop();
	dis[x] = 0;
	pq.push({dis[x],x});
	while(!pq.empty())
	{
		auto u = pq.top();
		pq.pop();
		vis[u.second] = 1;
		if(u.second > m) cnt++;
		if(cnt >= n) break;
		for(auto v : g2[u.second])
		{
			if(vis[v.first]) continue;
			if(dis[v.first] > dis[u.second] + v.second)
			{
				dis[v.first] = dis[u.second] + v.second;
				pq.push({-dis[v.first],v.first});
			}
		}
		if(cnt >= n) break;
	}
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i = 1; i <= m; i++) scanf("%lld",&w[i]);
	for(int i = 1; i <= n; i++)
	{
		int x;
		scanf("%lld",&x);
		for(int j = 1; j <= x; j++)
		{
			int y, z;
			scanf("%lld%lld",&y,&z);
			for(auto u : g[y])
			{
				g2[i].push_back(make_pair(u.first-m,z+u.second));
				g2[u.first-m].push_back(make_pair(i,z+u.second));
			}
			g[m+i].push_back(make_pair(y,z));
			g[y].push_back(make_pair(m+i,z));
		}
	}
	for(int i = 1; i <= n; i++)
	{
		dij(i);
		for(int j = 1; j <= n; j++) dist[i][j] = dis[j]/*, cout << i << " " << j << " " << dist[i][j] << "\n"*/;
	}
	while(q--)
	{
		int x, y, ans = 0x3f3f3f3f3f3f3f3f;
		scanf("%lld%lld",&x,&y);
		if(x == y)
		{
			puts("0");
			continue;
		}
		for(auto u : g[x])
		{
			for(auto v : g[y])
			{
				ans = min(ans,u.second+v.second+dist[u.first-m][v.first-m]);
			//	cout << u.second << " " << v.second <<" " << u.first << " " << v.first << " " << dist[u.first][v.first] << "\n";
			}
				
		}
			
		printf("%lld\n",ans+w[x]+w[y]);
	 } 
	return 0; 
	
}
