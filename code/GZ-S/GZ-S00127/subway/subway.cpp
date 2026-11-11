//GZ-S00127 ½ªÃú²Ó 
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <queue>
using namespace std;
typedef long long LL;
const int MAXN = 5e2 + 5, MAXM = 5e5 + 5;
const LL INF = 0x3f3f3f3f3f3f3f3f;
LL C, n, m, D, q, w[MAXM], mn_t[MAXN][MAXN], dis[MAXN][MAXN];
struct Node{
	int u;
	LL t;
}; vector <Node> stt[MAXN], lne[MAXM];

LL arv[MAXM];
LL calc(int u, int v){
	LL ret = INF;
	for(Node x : stt[u]) arv[x.u] = x.t;
	for(Node y : stt[v]) ret = min(ret, arv[y.u] + y.t);
	for(Node x : stt[u]) arv[x.u] = INF;
	return ret;
}

bool vis[MAXN];
void dijkstra(int s, LL *dis){
	memset(vis, 0, sizeof(vis));
	for(int i = 1; i <= n; i++) dis[i] = INF;
	dis[s] = 0;
	priority_queue< pair<LL, int> > pque;
	pque.push({-dis[s], s});
	while(!pque.empty()){
		int u = pque.top().second;
		pque.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		for(int v = 1; v <= n; v++)
			if(dis[v] > dis[u] + mn_t[u][v]) 
				dis[v] = dis[u] + mn_t[u][v], pque.push({-dis[v], v});
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> C >> n >> m >> D >> q;
	for(int i = 1; i <= m; i++) cin >> w[i], arv[i] = INF;
	for(int i = 1, k; i <= n; i++){
		cin >> k;
		while(k--){
			int a, t;
			cin >> a >> t;
			stt[i].push_back({a, t});
			lne[a].push_back({i, t});
		}
		for(int j = 1; j < i; j++) mn_t[i][j] = mn_t[j][i] = calc(i, j);
	}
	for(int i = 1; i <= n; i++)
		dijkstra(i, dis[i]);
	while(q--){
		int x, y;
		cin >> x >> y; 
		LL ret = INF;
		for(Node a : lne[x])
			for(Node b : lne[y])
				ret = min(ret, w[x] + w[y] + a.t + b.t + dis[a.u][b.u]);
		cout << ret << "\n";
	}
	return 0;
} 
