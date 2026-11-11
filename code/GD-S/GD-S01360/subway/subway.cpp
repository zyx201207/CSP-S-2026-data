#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e5 + 5, M = 505;
const ll inf = 0x3f3f3f3f3f3f3f3f;
int c, n, m, d, q, x[100005], y[100005];
int w[N];
struct Edge{
	int v, w;
};
struct Dis{
	int v;
	ll dis;
	bool operator < (const Dis &rhs) const{
		return dis > rhs.dis;
	}
};
vector<Edge> g[N + M];
ll dis[N];
ll dis2[100005];
bool vis[N];
void dijkstra(int s){
	memset(dis, 0x3f, sizeof(ll) * (n + m + 1));
	memset(vis, 0, sizeof(bool) * (n + m + 1));
	priority_queue<Dis> q;
	q.push({s, 0});
	dis[s] = 0;
	while(q.size()){
		int u = q.top().v;
		q.pop();
		if(vis[u]) continue;
//		cout << u << "\n";
		vis[u] = 1;
		for(auto edge : g[u]){
			int v = edge.v, w = edge.w;
			if(dis[u] + w < dis[v]){
				dis[v] = dis[u] + w;
				q.push({v, dis[v]});
			}
		}
	}
}
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
//	freopen("ans.txt", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
//	cerr << 111;
//	cout << 111 << "\n\n\n\n";
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++){
		cin >> w[i];
	}
	for(int i = 1, k, a, t; i <= n; i++){
		cin >> k;
		while(k--){
			cin >> a >> t;
			g[i + m].push_back({a, t});
			g[a].push_back({i + m, t});
		}
	}
//	dijkstra(1);
	for(int i = 1; i <= q; i++){
		cin >> x[i] >> y[i];
	}
	memset(dis2, 0x3f, sizeof dis2);
	for(int i = 1; i <= n; i++){
		dijkstra(i + m);
		for(int j = 1; j <= q; j++){
			dis2[j] = min(dis2[j], dis[x[j]] + dis[y[j]]);
		}
	}
	for(int i = 1; i <= q; i++){
		cout << w[x[i]] + w[y[i]] + dis2[i] << "\n";
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2



0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
