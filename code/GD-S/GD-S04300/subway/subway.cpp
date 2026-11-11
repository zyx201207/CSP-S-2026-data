#include<bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define pb push_back
using namespace std;

const int inf = 1e18;
int c, n, m, d, q;

void solve(){
	vector<int> w(m + 1);
	for(int i = 1; i <= m; i++) cin >> w[i];
	vector<vector<pii>> g(m + n + 1);
	for(int i = 1; i <= n; i++){
		int num;
		cin >> num;
		for(int j = 1; j <= num; j++){
			int a, t;
			cin >> a >> t;
			g[i + m].pb({a, t});
			g[a].pb({i + m, t});
		}
	}
	auto dij = [&](int s, int e) -> int {
		vector<int> dis(n + m + 1, inf);
		priority_queue<pii, vector<pii>, greater<pii>> pq;
		dis[s] = 0;
		pq.push({0, s});
		while(!pq.empty()){
			int d = pq.top().first, u = pq.top().second;
			pq.pop();
			if(d != dis[u]) continue;
			if(u == e) return d;
			for(pii it : g[u]){
				int v = it.first, w = it.second;
				if(dis[v] > dis[u] + w){
					dis[v] = dis[u] + w;
					pq.push({dis[v], v});
				}
			}
		}
		return 0;
	};
	while(q--){
		int x, y;
		cin >> x >> y;
		cout << dij(x, y) + w[x] + w[y] << '\n';
	}
}

signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	solve();
	return 0;
} 
