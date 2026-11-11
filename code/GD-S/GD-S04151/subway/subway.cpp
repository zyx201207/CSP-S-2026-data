#include<bits/stdc++.h>
#define pair pair<int, int>
using namespace std;
const int N = 501, M = 5e5 + 1, INF = 0x3f3f3f3f, C = 2001;

int c, n, m, d, q;
vector<pair> ph[N + M];
vector<vector<int>> ds(C, vector<int>(C, INF));

int djstl(int x, int y){
	vector<int> dt(N + M, INF);
	priority_queue<pair, vector<pair>, greater<pair>> q;
	q.push({0, x});
	dt[x] = 0;
	if(m < C) ds[x][x] = 0;
	while(!q.empty()){
		pair it = q.top();
		q.pop();
		int u = it.second, val = it.first;
		if(val != dt[u]) continue;
		for(pair e : ph[u]){
			int v = e.first, w = e.second;
			if(val + w < dt[v]){
				dt[v] = val + w;
				if(m < C) ds[x][v] = ds[v][x] = dt[v];
				q.push({dt[v], v});
			}
		}
	}
	return dt[y];
}

int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> c >> n >> m >> d >> q;
	vector<int> w(m + 1);
	for(int i=1; i<=m; i++) cin >> w[i];
	for(int i=1; i<=n; i++){
		int k;
		cin >> k;
		for(int j=1; j<=k; j++){
			int a, t;
			cin >> a >> t;
			ph[i + m].push_back({a, t});
			ph[a].push_back({i + m, t});
		}
	}
	while(q--){
		int x, y;
		cin >> x >> y;
		if(m <= C && ds[x][y] != INF) cout << w[x] + ds[x][y] + w[y] << "\n";
		else{
			int dist = w[x] + djstl(x, y) + w[y];
			cout << dist << "\n";
		}
	}
	return 0;
}
