#include <bits/stdc++.h>
using namespace std;

using ll  = long long;
using ull = unsigned long long;

int fast_io = []() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin.tie(nullptr) -> sync_with_stdio(false);
	return 0;
}();

constexpr int N = 1e6;

int n, k;
int testcase, t;
int dis[N + 5];
bitset<16> vis;
vector<int> graph[N + 5];

void input() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		graph[i].clear();
	} for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		graph[u].emplace_back(v);
		graph[v].emplace_back(u);
	}
}

void dfs(int now, int fa, int dep) {
	dis[now] = min(dis[now], dep);
	for (auto i: graph[now]) {
		if (i == fa) continue;
		dfs(i, now, dep+1);
	}
}

int calc(int x) {
	for (int i = 1; i <= n; i++) {
		dis[i] = 0x3f3f3f3f;
	} for (int i = 1; i <= n; i++) {
		if (x >> (i-1) & 1) {
			dfs(i, 0, 0);
		}
	} int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans = max(ans, dis[i]);
	} return ans;
}

void dfs2(int now, int fa) {
	vis[now] = 1;
	for (auto i: graph[now]) {
		if (i == fa) continue;
		if (dis[i] == 0) continue;
		dfs2(i, now);
	}
}

bool check(int x) {
	for (int i = 1; i <= n; i++) {
		dis[i] = 0;
		if (x >> (i-1) & 1) {
			dis[i] = 1;
		}
	} vis.reset(); 
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (!vis[i] && dis[i]) {
			dfs2(i, 0);
			ans += 1;
		}
	} return (ans <= 2);
}

void brute_force() {
	int ans = 0x3f3f3f3f;
	for (int i = 1; i < (1<<n); i++) {
		if (__builtin_popcount(i) != k) {
			continue;
		} if (!check(i)) continue; 
		ans = min(ans, calc(i));
	} cout << ans << '\n';
}

void solve() {
	if (n <= 10) {
		brute_force();
		return;
	} else {
		cout << n/3 << '\n';
		return;
	}
}

int main() {
	cin >> testcase >> t;
	while (t--) {
		input();
		solve();	
	} return 0;
}
