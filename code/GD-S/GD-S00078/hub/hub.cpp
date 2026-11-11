#include <bits/stdc++.h>
using namespace std;

int n, k, dis[200010];
vector<int> e[200010];
bool b[200010];
set<int> st;

void dfs(int x) {
	b[x] = true;
	for (auto y : e[x]) if (!b[y] && st.count(y)) {
		dfs(y);
	}
}
void solve() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) e[i].clear();
	for (int i = 1; i < n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		e[x].push_back(y);
		e[y].push_back(x);
	}
	int ans = (int)1e9;
	for (int i = 0; i < (1 << n); i++) {
		for (int j = 1; j <= n; j++) b[j] = false;
		st.clear();
		for (int j = 0; j < n; j++) if ((i >> j) & 1) {
			st.insert(j + 1);
		}
		if ((int)st.size() != k) continue;
		int cnt = 0;
		for (auto j : st) if (!b[j]) {
			cnt++; dfs(j);
		}
		if (cnt > 2) continue;
		int mx = 0;
		for (int j = 1; j <= n; j++) {
			for (int l = 1; l <= n; l++) dis[l] = -1;
			dis[j] = 0;
			queue<int> q; q.push(j);
			while (!q.empty()) {
				int x = q.front(); q.pop();
				for (auto y : e[x]) if (dis[y] == -1) {
					dis[y] = dis[x] + 1; q.push(y);
				}
			}
			int mn = (int)1e9;
			for (auto l : st) mn = min(mn, dis[l]);
			mx = max(mx, mn);
		}
		ans = min(ans, mx);
	}
	printf("%d\n", ans);
}
int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	
	int test, c;
	scanf("%d%d", &c, &test);
	while (test--) solve();
	return 0;
}

