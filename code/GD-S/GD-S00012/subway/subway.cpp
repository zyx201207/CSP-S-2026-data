#include <bits/stdc++.h>
using namespace std;

using ll  = long long;
using ull = unsigned long long;

int fast_io = []() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin.tie(nullptr) -> sync_with_stdio(false);
	return 0;	
}();

constexpr int N = 500;
constexpr int M = 5e5;

struct Station {
	int line_id;
	ll walk_t;
	
	Station(int _, ll __) {
		line_id = _;
		walk_t = __;
	}
};

int n, m;
int testcase;
int d, q;

ll graph[N + 5][N + 5];
ll extra_t[M + 5];
vector<Station> station[M + 5];

void input() {
	cin >> testcase >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> extra_t[i];
	} for (int i = 1; i <= n; i++) {
		int k; cin >> k;
		while (k--) {
			int id;
			ll tmp;
			cin >> id >> tmp;
			station[id].emplace_back(i, tmp);
		}
	}
}

void solve() {
	memset(graph, 0x3f, sizeof(graph));
	for (int i = 1; i <= m; i++) {
		for (auto a: station[i]) {
			for (auto b: station[i]) {
				int a_id = a.line_id;
				int b_id = b.line_id;
				ll a_tim = a.walk_t;
				ll b_tim = b.walk_t;
				if (a_id == b_id) continue;
				graph[a_id][b_id] = min(graph[a_id][b_id], a_tim + b_tim);
			}
		}
	}
	
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i == j) graph[i][j] = 0;
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
			}
		}
	}
	
	while (q--) {
		int u, v;
		cin >> u >> v;
		
		ll ans = 0x3f3f3f3f3f3f3f3f;
		for (auto i: station[u]) {
			for (auto j: station[v]) {
				int u_id = i.line_id;
				int v_id = j.line_id;
				ans = min(ans, graph[u_id][v_id] + i.walk_t + j.walk_t + extra_t[u] + extra_t[v]);
			}
		} cout << ans << '\n';
	} cout << flush;
}

int main() {
	input();
	solve();
	return 0;
}
