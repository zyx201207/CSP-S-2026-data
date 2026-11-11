#include<bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int N = 500, M = 5e5;
int c, n, m, dd, Q;
ll w[M + 5], d[N + M + 5], x[M + 5], y[M + 5], Ans[M + 5];
vector<pair<ll, ll> > G[N + M + 5];
bool vis[N + M + 5];
void dijkstra(int s) {
	for(int i = 1; i <= n + m; ++i) 
	  d[i] = 5000000000000000, vis[i] = 0;
	d[s] = 0;
	priority_queue<pair<ll, ll> > q;
	q.push({0, s});
	while(!q.empty()) {
		ll xx = q.top().second; q.pop();
		if(vis[xx] == 1) continue; vis[xx] = 1;
		for(auto Y : G[xx]) {
			ll yy = Y.first, ww = Y.second;
			if(d[yy] > d[xx] + ww) {
				d[yy] = d[xx] + ww;
				q.push({-d[yy], yy});
			}
		}
	}
	for(int i = 1; i <= Q; ++i) {
		Ans[i] = min(Ans[i], d[n + x[i]] + d[n + y[i]] + w[x[i]] + w[y[i]]);
	}
}
void bfs(int s) {
	for(int i = 1; i <= n + m; ++i) 
	  d[i] = 5000000000000000, vis[i] = 0;
	d[s] = 0;
	queue<ll> q;
	q.push(s);
	while(!q.empty()) {
		ll xx = q.front(); q.pop();
		for(auto Y : G[xx]) {
			ll yy = Y.first, ww = Y.second;
			if(d[yy] > d[xx] + ww) {
				d[yy] = d[xx] + ww;
				q.push(yy);
			}
		}
	}
	for(int i = 1; i <= Q; ++i) {
		Ans[i] = min(Ans[i], d[n + x[i]] + d[n + y[i]] + w[x[i]] + w[y[i]]);
	}
}
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
// don't forget change your freopen!!!!!!!!
// don't forget change your freopen!!!!!!!!
// don't forget change your freopen!!!!!!!!
// don't forget change your freopen!!!!!!!!
// don't forget change your freopen!!!!!!!!
// don't forget change your freopen!!!!!!!!
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> c >> n >> m >> dd >> Q;
	for(int i = 1; i <= m; ++i) cin >> w[i];
	for(int i = 1; i <= n; ++i) {
		int K; cin >> K;
		for(int j = 1; j <= K; ++j) {
			ll a, t; cin >> a >> t;
			G[i].push_back({n + a, t}); G[n + a].push_back({i, t});
		}
	}
	for(int i = 1; i <= Q; ++i) 
	  cin >> x[i] >> y[i], Ans[i] = 5000000000000000;
	for(int i = 1; i <= n; ++i) {
		if(c >= 16 && c <= 19) bfs(i); else dijkstra(i);
	}
	for(int i = 1; i <= Q; ++i) cout << Ans[i] << '\n';
	return 0;
}
