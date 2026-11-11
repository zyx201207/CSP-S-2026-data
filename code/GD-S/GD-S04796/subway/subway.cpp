#include <bits/stdc++.h>
using namespace std;

/*
换线 站台1 厅台1 站台2
站台1 -> 线路1 -> 线路2 -> 站台2 -> 厅台2 -> 站台3 
出入 ct 
*/
const int inf = 1e9;

vector<int> dijkstra (vector<vector<pair<int, int>>>& g,
vector<int>& ct, int n, int m, int s){
	vector<int> dist(n + 1, inf);
	vector<bool> vis(n + 1, false);
	priority_queue<pair<int, int>, 
	vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({0, s});
	dist[s] = 0;
	while(!pq.empty()){
		auto top = pq.top();
		pq.pop();
		int u = top.second;
		if(vis[u]) continue;
		vis[u] = true;
		for(int i = 0;i < g[u].size();i++){
			int v = g[u][i].second, w = g[u][i].first;
			if(dist[v] > dist[u] + w){
				dist[v] = dist[u] + w;
				pq.push({dist[v], v});
			}
		}
	}
	return dist;
}

int main(){
	freopen("subway.in", "in", stdin);
	freopen("subway.out", "out", stdout);
	int c = 0, n = 0, m = 0, d = 0, q = 0;
	cin >> c >> n >> m >> d >> q;
	vector<int> ct(m + 1, 0); //口到站厅 
	//线路数量，站数量，最多被几个路线经过，计划数量
	vector<vector<pair<int, int>>> g(m + 1);
	for(int i = 1;i <= m;i++){
		cin >> ct[i];
	}
	for(int i = 1;i <= n;i++){
		int k = 0;
		cin >> k;
		for(int j = 1;j <= k;j++){
			//i j w
			int tar = 0, w = 0;
			cin >> tar >> w;
			g[i].push_back({w, tar}); 
		}
	}
	for(int i = 0;i < q;i++){
		int res = inf / 2, s = 0, t = 0;
		vector<int> dist;
		cin >> s >> t;
		dist = dijkstra(g, n, m, s);
		for(int j = 0;j < dist.size();j++){
			res = min(res, dist[t] + ct[t] + ct[s]);
		}
		cout <<endl << res << endl;
	}
	return 0;
}
