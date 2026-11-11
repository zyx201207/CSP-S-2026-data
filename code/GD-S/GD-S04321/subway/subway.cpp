#include<bits/stdc++.h>
#define ll long long
#define N 1010


using namespace std;
//bool Mst;
int c, n, m, d, q;
int st, ed;
int a[550010];
int dis[N][N];
struct edge{
	int to, w;
};
struct node{
	int d, u;
	bool operator<(const node& o) const{
		//为什么老是给我报错，不解 
		return d > o.d; 
	}
};
vector<edge> e[N];

void dijkstra(int s){
	bool vis[N]; priority_queue<node> q;
	memset(vis, 0, sizeof(vis));
	dis[s][s] = 0;
	q.push({0, s});
	while(!q.empty()){
		node cur = q.top(); q.pop(); 
		int d = cur.d; int u = cur.u;
		if(dis[s][u] < d) continue;
		if(vis[u]) continue;
		vis[u] = true;
		for(edge cu : e[u]){
			int v = cu.to; int w = cu.w;
			if(v == u) continue;
			dis[s][v] = min(dis[s][u] + w, dis[s][v]);
			//cout << s << " " << v << " " << d + w << endl;
			q.push({d + w, v});
		}
	}
	//cout << endl;
	return;
}//为什么我的dijkstra炸了，不解 
//bool Med;
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//cerr << "Memory is:" << abs(&Mst - &Med) / 1024.0 / 1024 << "MB" << endl;
	freopen("subway.in", "r", stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	memset(dis, 0x3f, sizeof(dis));
	for(int i = 1; i <= m; ++i) cin >> a[i];
	for(int i = 1; i <= n; ++i){
		int k; cin >> k;
		while(k--){
			int v, w; cin >> v >> w;
			e[i + m].push_back({v, w});
			e[v].push_back({i + m, w});
		}
	}
	for(int i = 1; i <= m; ++i){
		dijkstra(i);
	}
	while(q--){
		cin >> st >> ed;
		cout << a[st] + a[ed] + dis[st][ed] << endl;
	}
	return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
