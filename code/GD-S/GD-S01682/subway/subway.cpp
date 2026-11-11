#include<bits/stdc++.h>
using namespace std;
#define ll long long
//m个站厅 n条地铁(可视为站台之间0距离) 共n + m的节点数量
int const N = 5e5 + 550, M = 1e7 + 10010;
ll const INF = 1e16; 
ll c, n, m, d, q;
//测试点编号 线路数 地铁站数 
//每个地铁站最多被几条线路经过 出行计划数
ll exit_hub[M];
int hd[M], nxt[M], to[M], scnt = 0;
ll wi[M];//链式前向星 
void Add(int u,int v,ll w)//1~m站台 m + 1~m + n地铁 
{
	to[scnt] = v;
	wi[scnt] = w;
	nxt[scnt] = hd[u];
	hd[u] = scnt;
	scnt++;
}
ll dist[M];
bool vis[M];
priority_queue<pair<ll, int>> que;
void dij(int st)
{
	for(int i = 1;i <= n + m;i++)
		dist[i] = INF, vis[i] = 0;
	dist[st] = 0;
	que.push({0, st});
	while(!que.empty())
	{
		int u = que.top().second;
		que.pop();
		if(vis[u])
			continue;
		vis[u] = 1;
		for(int x = hd[u];x != -1;x = nxt[x])
		{
//			cout << " to " << to[x] << " " << dist[to[x]] << " " << dist[u] + wi[x] << "\n";
			if(dist[to[x]] > dist[u] + wi[x])
			{
//				cout << "update " << dist[u] + wi[x] << "\n";
				dist[to[x]] = dist[u] + wi[x];
				que.push({-1 * dist[to[x]], to[x]});
			}
		}
//		cout << "side from " << u << "\n";
//		for(int i = 1;i <= n + m;i++)
//			cout << dist[i] << " ";
//		cout << "\n\n";
	}
}
int main()//dij q次 O(qT(N,M)) N=n+m,M=Σk_i+n
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= n + m;i++)
		hd[i] = -1;
	for(int i = 1;i <= m;i++)
		cin >> exit_hub[i];
	for(int i = 1;i <= n;i++)
	{
		int k;//这条地铁经过站点数量 
		cin >> k;
		for(int j = 0;j < k;j++)
		{
			int stat_id, t_ij;
			cin >> stat_id >> t_ij;
			Add(stat_id, i + m, t_ij);
			Add(i + m, stat_id, t_ij);
		} 
	}
	for(int i = 0;i < q;i++)
	{
		int x, y;
		cin >> x >> y;
		dij(x);
		cout << dist[y] + exit_hub[x] + exit_hub[y]<< "\n";
	}
	return 0;
 } 
