#include<bits/stdc++.h>
using namespace std;

const int inf = 1e9;

struct DSU{
	vector<int> p;
	DSU(int n) {init(n);}
	void init(int n){
		p.resize(n + 1);
		iota(p.begin(), p.end(), 0);
	}
	int find(int x) {
		return x == p[x] ? p[x] : p[x] = find(p[x]);
	}
	void merge(int x, int y){
		x = find(x), y = find(y);
		if(x == y) return ;
		else p[x] = y;
	}
};

void solve(){
	int n, k;
	cin >> n >> k;
	vector<vector<int>> g(n + 1, vector<int> (n + 1));
	for(int i = 1; i < n; i++){
		int u, v;
		cin >> u >> v;
		g[u][v] = g[v][u] = 1;
	}
	int ans = inf;
	for(int i = 0; i < (1 << n); i++){
		vector<int> a;
		for(int j = n - 1; j >= 0; j--){
			if((i >> j) & 1) a.push_back(j + 1);
		}
		if((int)a.size() != k) continue;
		DSU d(n + 1);
		for(auto x : a)
			for(auto y : a)
				if(g[x][y])
					d.merge(x, y);
		set<int> s;
		for(auto x : a) s.insert(d.find(x));
		if(s.size() > 2) continue;
		vector<int> dis(n + 1, inf);
		auto bfs = [&](int st) -> void {
			dis[st] = 0;
			queue<int> q;
			q.emplace(st);
			while(!q.empty()){
				int u = q.front();
				q.pop();
				for(int v = 1; v <= n; v++){
					if(!g[u][v]) continue;
					if(dis[v] > dis[u] + 1){
						dis[v] = dis[u] + 1;
						q.emplace(v);
					}
				}
			}
		};
		for(auto x : a) bfs(x);
		ans = min(ans, *max_element(dis.begin() + 1, dis.end()));
	}
	cout << ans << '\n';
}

int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int c, T;
	cin >> c >> T;
	while(T--) solve();
	return 0;
}
