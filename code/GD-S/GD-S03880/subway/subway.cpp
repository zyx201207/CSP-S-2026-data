#include<bits/stdc++.h>
#define int long long
#define N 500005
#define dbg(x) cerr<<#x<<" "<<x<<endl
using namespace std;
int Tid, n, m, d, q, val[N];
struct Node{
	int v, w;
	bool operator<(const Node &x)const{
		return w > x.w;
	}
};
vector<Node> g[N];
int dis[N], D[1005][1005];
void dijkstra(int s){
	for(int i = 1; i <= m + n; i++) dis[i] = 1e18;
	dis[s] = 0;
	priority_queue<Node> Q;
	Q.push({s, 0});
	while(Q.size()){
		auto tp = Q.top();
		Q.pop();
		int u = tp.v;
		for(auto nxt : g[u]){
			int v = nxt.v, w = nxt.w;
			if(dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				Q.push({v, dis[v]});
			}
		}
	}
}
void sol(){
	for(int i = 1; i <= n; i++){
		int k;
		cin >> k;
		while(k--){
			int u, tu;
			cin >> u >> tu;
			g[u].push_back({i + m, tu});
			g[i + m].push_back({u, tu});
		}
	}
	for(int i = 1; i <= m; i++){
		dijkstra(i);
		for(int j = 1; j <= m; j++){
			D[i][j] = dis[j];
		}
	}
	while(q--){
		int u, v;
		cin >> u >> v;
		cout << D[u][v] + val[u] + val[v] << endl;
	}
}
void solveA(){
	for(int i = 1; i <= n; i++){
		int x, y, xt, yt, k;
		cin >> k >> x >> xt >> y >> yt;
		g[x].push_back({y, yt + xt});
		g[y].push_back({x, xt + yt});
	}
	for(int i = 1; i <= m; i++){
		dijkstra(i);
		for(int j = 1; j <= m; j++){
			D[i][j] = dis[j];
		}
	}
	while(q--){
		int u, v;
		cin >> u >> v;
		cout << D[u][v] + val[u] + val[v] << endl;
	}
}

signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out","w", stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> Tid >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++) cin >> val[i];
	if(Tid <= 6)sol();
	if(Tid >= 7 && Tid <= 11) solveA();
	return 0;
}

