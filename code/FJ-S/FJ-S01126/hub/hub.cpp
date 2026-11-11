#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

int C, T, n, k;
vector <int> sons[1000005];
void add(int u, int v) {
	sons[u].push_back(v);
}
void init() {
	for (int i = 1; i <= n; i++) {
		sons[i].clear();
	}
}
int s[1005];
void dfs(int u, int fa) {
	if (s[u]) s[u] = 0;
	for (int i = 0; i < (int)sons[u].size(); i++) {
		int v = sons[u][i]; if (v == fa) continue;
		if (s[v]) dfs(v, u);
	}
}
int dis[1005];
void dfs2(int u, int fa, int cnt) {
	dis[u] = min(dis[u], cnt);
	for (int i = 0; i < (int)sons[u].size(); i++) {
		int v = sons[u][i]; if (v == fa) continue;
		dfs2(v, u, cnt + 1);
	}
}
void sub_1() {
	int ans = 1e18;
	for (int i = 0; i < (1 << n); i++) {
		if (__builtin_popcount(i) != k) continue;
		for (int i = 1; i <= n; i++) s[i] = 0;
		for (int i = 1; i <= n; i++) dis[i] = 1e18;
		for (int j = 1; j <= n; j++) {
			if (i & (1 << (j - 1))) {
				s[j] = 1;
			}
		}
		int cnt = 0;
		for (int j = 1; j <= n; j++) {
			if (s[j]) {
				cnt++;
				dfs(j, 0);
			}
		}
		if (cnt <= 2) {
			for (int j = 1; j <= n; j++) {
				if (i & (1 << (j - 1))) {
					dfs2(j, 0, 0);
				}
			}
			int qwq = 0;
			for (int j = 1; j <= n; j++) 
				qwq = max(qwq, dis[j]);
			ans = min(ans, qwq);
		}
	}
	cout << ans << endl;
}
void sub_A() {
	if (n == k) cout << 0 << endl;
	else if (k >= ((n - 1) / 2)) {
		cout << 1 << endl;
	}
	else {
		int s = (n + 1) / 2 + 3 - k;
		int ansA = s / 4;
		if (s % 4) ansA++;
		cout << ansA << endl;
	}
}
void solve() {
	cin >> n >> k;
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		add(u, v); add(v, u);
	}
	if (C <= 3) {
		sub_1();
		init();
		return ;
	}
	if (C == 13 || C == 14) {
		sub_A();
		init();
		return ;
	}
}

signed main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);

	std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> C >> T;
	while (T--) solve();
	return 0;
}

