// 王名扬 GZ-S00063 观山湖区铭苑中学 
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct Edge{
	ll to, idx, w;
	Edge(ll to_, ll idx_, ll w_) {
		to = to_, idx = idx_, w = w_;
	}
};
enum Node{
	Dist, From, Idx
};
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	ll c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	vector<ll> weight(m + 1);
	for (ll i = 1; i <= m; ++i)
		cin >> weight[i];
	
	vector<vector<vector<Edge>>> adj(m + 1, vector<vector<Edge>>(n + 1));
	for (ll i = 1; i <= n; ++i) {
		ll k;
		cin >> k;
		ll from, t;
		cin >> from >> t;
		adj[from][0].push_back(Edge(from, i, t));
		adj[from][i].push_back(Edge(from, 0, t));
		for (ll j = 2; j <= k; ++j) {
			ll to, t;
			cin >> to >> t;
			adj[from][i].push_back(Edge(to, i, 0));
			adj[to][i].push_back(Edge(from, i, 0));
			adj[to][0].push_back(Edge(to, i, t));
			adj[to][i].push_back(Edge(to, 0, t));
			from = to;
		}
	}
		
	const ll INF = 1e18;
	while (q--) {
		ll start, end;
		cin >> start >> end;
		
		vector<vector<ll>> dist(m + 1, vector<ll>(n + 1, INF));
		vector<vector<bool>> is_vis(m + 1, vector<bool>(n + 1));
		priority_queue<tuple<ll, ll, ll>, vector<tuple<ll, ll, ll>>, greater<tuple<ll, ll, ll>>> pq;
		dist[start][0] = 0;
		pq.push(make_tuple(0, start, 0));
		while (!pq.empty()) {
			ll d = get<Dist>(pq.top()), from = get<From>(pq.top()), idx = get<Idx>(pq.top());
			pq.pop();
			if (is_vis[from][idx])
				continue;
			for (Edge &v : adj[from][idx]) {
				ll nd = d + v.w;
				if (nd < dist[v.to][v.idx])
					pq.push(make_tuple(dist[v.to][v.idx] = nd, v.to, v.idx));
			}
		}
		cout << dist[end][0] + weight[start] + weight[end] << '\n';
	}

//	vector<vector<vector<vector<ll>>>> dp(m + 1,
//		vector<vector<vector<ll>>>(n + 1,
//			vector<vector<ll>>(m + 1,
//				vector<ll>(n + 1, INF)
//			)
//		)
//	);
//	
//	for (ll i = 1; i <= m; ++i)
//		for (ll j = 0; j <= n; ++j)
//			for (Edge v : adj[i][j])
//				dp[i][j][v.to][v.idx] = v.w;
//	
//	for (ll i = 1; i <= m; ++i)
//		for (ll j = 0; j <= n; ++j)
//			dp[i][j][i][j] = 0;
//	
//	for (ll ki = 1; ki <= m; ++ki)
//		for (ll kj = 0; kj <= n; ++kj)
//			for (ll ii = 1; ii <= m; ++ii)
//				for (ll ij = 0; ij <= n; ++ij)
//					for (ll ji = 1; ji <= m; ++ji)
//						for (ll jj = 0; jj <= n; ++jj)
//							dp[ii][ij][ji][jj] = min(dp[ii][ij][ji][jj], 
//																			 dp[ii][ij][ki][kj] + dp[ki][kj][ji][jj]);
//
//	while (q--) {
//		ll start, end;
//		cin >> start >> end;
//		cout << dp[start][0][end][0] + weight[start] + weight[end] << '\n';
//	}
}










