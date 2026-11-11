#include<bits/stdc++.h>
using namespace std;
const int MAX = 5e5 + 5;
int c, n, m, d, q;
int t[MAX], f[MAX];
vector<int> bel[MAX];
struct edge{
	vector<pair<int, int>> d;
}ed[MAX];
vector<pair<int, int>> g[MAX];
int dfs1(int x, int y, int tim){
	f[x] = true;
	if(x == y) return tim;
	int ans = 1e9;
	for(int h: bel[x]){
		int op = 0;
		for(auto [q1, q2]: ed[h].d){
			if(q1 == x){
				op = q2;
				break;
			}
		}
		for(auto [q1, q2]: ed[h].d){
			if(q1 == x || f[q1]) continue;
			ans = min(ans, dfs1(q1, y, tim + q2 + op));
		}
	}
	return ans;
}
int dijkstra(int s, int e){
	priority_queue<pair<int, int>> pq;
	pq.push({0, s});
	while(!pq.empty()){
		auto [w, u] = pq.top();
		pq.pop();
		f[u] = true;
		if(u == e) return -w;
		for(auto [v, r]: g[u]){
			if(f[u]) continue;
			pq.push({w - r, v});
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++) cin >> t[i];
	if(c <= 3){
		for(int i = 1; i <= n; i++){
			int k;
			cin >> k;
			for(int j = 1; j <= k; j++){
				int u, v;
				cin >> u >> v;
				ed[i].d.push_back({u, v});
				bel[u].push_back(i);
			}
		}
		while(q--){
			int x, y;
			cin >> x >> y;
			for(int i = 1; i <= n; i++) f[i] = false;
			cout << dfs1(x, y, 0) + t[x] + t[y] << '\n';
		}
	}else if(c >= 7 && c <= 11){
		for(int i = 1; i <= n; i++){
			int k;
			cin >> k;
			int u, v, w1, w2;
			if(k == 1) cin >> u >> w1;
			else{
				cin >> u >> w1 >> v >> w2;
				g[u].push_back({v, w1 + w2});
				g[v].push_back({u, w1 + w2});
			}
		}
		while(q--){
			int x, y;
			cin >> x >> y;
			for(int i = 1; i <= n; i++) f[i] = false;
			cout << dijkstra(x, y) << '\n';
		}
	}
	return 0;
}
