#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = (a); i <= (n); i++)
#define pre(i, n, a) for (int i = (n); i >= (a); i--)
#define pb push_back
#define eb emplace_back
#define mp std::make_pair
#define SZ(x) (int)((x).size())
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef std::vector<int> VI;
typedef std::pair<int, int> PII;
std::mt19937 mrand(std::random_device{}());
int rnd(int x) { return mrand() % x; }
// head

constexpr ll inf = 1ll << 60;

const int M = 500010;
std::vector<std::pair<int, ll>> adj[M + M];
std::vector<ll> dist[M + M];

int main() {
	int tc, n, m, d, q;
	scanf("%d%d%d%d%d", &tc, &n, &m, &d, &q);

	VI w(m + 1);
	rep(i, 1, m) scanf("%d", &w[i]);

	rep(i, 1, n) {
		int k;
		scanf("%d", &k);
		rep(j, 1, k) {
			int v;
			ll w;
			scanf("%d%lld", &v, &w);
			adj[m + v].eb(v, w);
			adj[v].eb(m + v, w);
		}
	}

	auto dijkstra = [&](int st) -> void {
		std::priority_queue<PLI, std::vector<PLI>, std::greater<>> q;
		rep(i, 1, m + m) dist[st][i] = inf;
		q.emplace(dist[st][st] = 0, st);
		while (!q.empty()) {
			ll d = q.top().first;
			int x = q.top().second;
			q.pop();
			if (d != dist[st][x]) continue;
			for (auto nxt : adj[x]) {
				int y = nxt.first;
				ll v = nxt.second;
				if (dist[st][y] > d + v) 
					q.emplace(dist[st][y] = d + v, y);
			}
		}
	};

	rep(i, 1, m) {
		rep(j, 0, adj2[i].size() - 1) adj2[i][j] = inf;
		adj2[i][i] = 0;
	}

	rep(i, 1, m) {
		for (auto x : adj[i])
			for (auto y : adj[i]) {
				
			}
	}

	rep(i, 1, m) dijkstra(i);

	for (; q--; ) {
		int u, v;
		scanf("%d%d", &u, &v);

	}

	return 0;
}