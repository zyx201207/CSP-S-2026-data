#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
const ll INF = 1e18;
const int N = 510;
const int M = 5e5 + 3;
ll dist[N][N], ans[N][N];
vector<pii> tmp[M];
vector<pil> g[N]; 

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	vector<int> w(m + 1);
	for(int i = 1; i <= m; ++i) cin >> w[i];
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j) {
			dist[i][j] = INF;
		}
	}
	for(int i = 1; i <= n; ++i) {
		int k; cin >> k;
		while(k--) {
			int a, t;
			cin >> a >> t;
			for(pii x : tmp[a]) {
				int id = x.first, t2 = x.second;
				dist[i][id] = min(dist[i][id], (ll)t + t2);
				dist[id][i] = min(dist[id][i], (ll)t + t2);
			}
			tmp[a].push_back({i, t});
		}
	}
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j) {
			if(dist[i][j] != INF) {
				g[i].push_back({j, dist[i][j]});
				//cout << i << ' ' << j << ' ' << dist[i][j] << '\n';
			}
		}
	}
	
	for(int s = 1; s <= n; ++s) {
		vector<ll> dis(n + 1, INF);
		vector<bool> done(n + 1);
		priority_queue<pli, vector<pli>, less<pli>> q;
		q.push({0, s});
		dis[s] = 0;
		
		while(!q.empty()) {
			pli tmp = q.top();
			q.pop();
			int u = tmp.second;
			if(done[u]) continue;
			done[u] = 1;
			for(pil to : g[u]) {
				int v = to.first;
				ll w = to.second;
				if(dis[u] + w < dis[v]) {
					dis[v] = dis[u] + w;
					q.push({dis[v], v});
				}
			}
		}
		for(int j = 1; j <= n; ++j) {
			ans[s][j] = dis[j];
		}
	}
	
	
	while(q--) {
		int s, t;
		cin >> s >> t;
		ll res = INF;
		for(pii x : tmp[s]) {
			for(pii y : tmp[t]) {
				res = min(res, ans[x.first][y.first] + x.second + y.second);
			}
		}
		cout << res + w[s] + w[t] << '\n';
	}
	
	return 0;
} 
