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

int test_case, data_id;

void solution() {
	int n, k; cin >> n >> k;
	vector<pii> edg;
	for(int i = 0; i < n - 1; i++) {
		int x, y; cin >> x >> y; x--, y--;
		edg.emplace_back(x, y);
	}
	int ans = n;
	auto solve = [&](int id) {
		vector<vector<int> > G(n);
		for(int i = 0; i < n - 1; i++) {
			if(i == id) continue;
			auto [x, y] = edg[i];
			G[x].emplace_back(y);
			G[y].emplace_back(x);
		}
		vector<int> vis(n);
		auto dfs = [&](auto &&dfs, int u, vector<vector<int>> &vec, vector<int> &deg) -> void {
			vis[u] = true;
			for(auto v : G[u]) if(!vis[v]) {
				vec[u].emplace_back(v);
				vec[v].emplace_back(u);
				deg[u]++, deg[v]++;
				dfs(dfs, v, vec, deg);
			}
		};
		vector<vector<int> > T1(n), T2(n);
		vector<int> deg1(n), deg2(n);
		if(id == n - 1) {
			dfs(dfs, 0, T1, deg1);
		} else {
			dfs(dfs, edg[id].first, T1, deg1);
			dfs(dfs, edg[id].second, T2, deg2);
		} 
		vector<int> q1, q2;
		for(int i = 0; i < n; i++) if(deg1[i] == 1) q1.emplace_back(i);
		for(int i = 0; i < n; i++) if(deg2[i] == 1) q2.emplace_back(i);
		int r = 0, c1 = T1.size() / 2 + 1, c2 = T2.size() / 2 + 1;
		
		for(; r <= n - 1; r++) {
			if(max(1, c1) + max(1, c2) <= k) break;
			vector<int> nq1, nq2;
			for(auto x : q1) {
				for(auto v : T1[x]) {
					if(--deg1[v] == 1) nq1.emplace_back(v);
				}
			}
			for(auto x : q2) {
				for(auto v : T2[x]) {
					if(--deg2[v] == 1) nq2.emplace_back(v);
				}
			}
			c1 -= (int)q1.size();
			c2 -= (int)q2.size();
			q1 = nq1, q2 = nq2;
		}
		return r;
	};
	for(int i = 0; i < n; i++) chkmin(ans, solve(i));
//	for(int i = 0; i < n - 1; i++) cout << i + 1 << ": " << solve(i) << "\n";
	cout << ans << "\n";
}
void prework() {}

int main() {
	fileIO("hub");
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int test_num = 1; cin >> data_id >> test_num;
	prework();
	for (test_case = 1; test_case <= test_num; test_case++) solution();
	return 0;
}
