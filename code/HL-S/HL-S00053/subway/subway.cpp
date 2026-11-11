#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#define int long long
using namespace std;
struct node
{
	int v,w;
	bool operator<(const node T) const{
		return w > T.w;
	}
};
int c,n,m,d,qt;
int cw[500002],cnt[3002];
//n为线路数，m为地铁站数，d为每个地铁站最多有几条
//线路经过，q为出行计划数 
vector<node> e[3002];
int Dijkstra(int s,int g){
	int dis[3002] = {};
	bool vis[3002] = {};
	for (int i = 0;i <= 3001;i++){
		dis[i] = 0x3f3f3f3f3f3f3f3f;
	}
	dis[s] = 0;
	priority_queue<node> qu;
	qu.push({s,0});
	while (!(qu.empty())){
		int u,x;
		node ccx = qu.top();
		u = ccx.v;
		x = ccx.w;
		qu.pop();
		if (vis[u]) continue;
		vis[u] = 1;
		for (int i = 0;i < e[u].size();i++){
			int v = e[u][i].v;
			int w = e[u][i].w;
			if (dis[v] > dis[u] + w){
				dis[v] = dis[u] + w;
				qu.push({v,dis[u] + w});
			}
		}
		if (vis[g]) return dis[g];
	}
}

signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&qt);
	for (int i = 1;i <= m;i++){
		cin >> cw[i];
		
	}
	if (c >= 0 && c < 9){
		
		for (int i = 1;i <= n;i++){
			int k;
			cin >> k;
			for (int j = 1;j <= k;j++){
				int a,t;
				cin >> a >> t;
                e[a].push_back({m + i,t});
                e[m + i].push_back({a,t});
			}
		}
		for (int i = 1;i <= qt;i++){
			int s,g;
			cin >> s >> g;
			Dijkstra(s,g);
			printf("%lld\n",Dijkstra(s,g) + cw[s] + cw[g]);
		}
	}
}
