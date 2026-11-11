#include <bits/stdc++.h>
using namespace std;
using uint = unsigned int; using ll = long long; using ld = long double;
using pii = pair<int, int>; using pll = pair<ll, ll>;
template<typename T, typename U>
bool chkmin(T &a, const U &b) { return (b < a ? (a = b, true) : false); }
template<typename T, typename U>
bool chkmax(T &a, const U &b) { return (b > a ? (a = b, true) : false); }
void fileIO(const string &x) { freopen((x + ".in").c_str(), "r", stdin); freopen((x + ".out").c_str(), "w", stdout); }
mt19937_64 gen(random_device{}());
constexpr int infi = 1e9;
constexpr ll  infl = 2e18;

int test_case;

void solution() {
	int c, n, m, d, q; cin >> c >> n >> m >> d >> q;
	vector<int> w(m);
	for(int i = 0; i < m; i++) cin >> w[i];
	
	struct Route {
		int x, cost; // 第x条地铁线路，前往需要cost代价 
		Route(int x_, int cost_) : x(x_), cost(cost_) {}
	};
	vector<vector<Route> > stt(m);
	vector<int> k(n);
	vector<vector<int> > a(n), t(n);
	for(int i = 0; i < n; i++) {
		cin >> k[i];
		for(int j = 0; j < k[i]; j++) {
			a[i].emplace_back(), t[i].emplace_back();
			cin >> a[i][j] >> t[i][j]; a[i][j]--;
			stt[a[i][j]].emplace_back(i, t[i][j]);
		}
	}
	vector<vector<ll> > f(n, vector<ll>(n, infl));
	for(int i = 0; i < n; i++) f[i][i] = 0;
	for(int i = 0; i < m; i++) {
		for(int u = 0; u < stt[i].size(); u++) {
			for(int v = u + 1; v < stt[i].size(); v++) {
				auto [x, cx] = stt[i][u];
				auto [y, cy] = stt[i][v];
//				cout << "[" << i + 1 << " " << x + 1 << " " << y + 1 << "]" << " " << cx <<" " << cy << "\n";
				chkmin(f[x][y], cx + cy);
				chkmin(f[y][x], cx + cy);
			}
		}
	}
//	for(int i = 0; i < n; i++) {
//		for(int j = 0; j < n; j++) {
//			cout << "(" << i + 1 << ", " << j + 1 << ")" << f[i][j] << "\n";
//		}
//	}
	for(int k = 0; k < n; k++) {
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				chkmin(f[i][j], f[i][k] + f[k][j]);
			}
		}
	}
	while(q--) {
		int x, y; cin >> x >> y; x--, y--;
		ll ans = w[x] + w[y], sum = infl;
		for(auto [u, cu] : stt[x]) {
			for(auto [v, cv] : stt[y]) {
				chkmin(sum, cu + cv + f[u][v]);
			}
		}
		cout << ans + sum << "\n";
	}
}
void prework() {}

int main() {
	fileIO("subway");
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int test_num = 1; // cin >> test_num;
	prework();
	for (test_case = 1; test_case <= test_num; test_case++) solution();
	return 0;
}
