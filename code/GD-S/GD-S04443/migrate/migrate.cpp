#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n; i64 d; cin >> n >> d; vector<i64> x(n);
	for (int i = 0; i < n; i++) cin >> x[i];
	/*
	bool arith = true;
	for (int i = 0; i < n - 2; i++) arith &= (x[i+1]-x[i]==x[i+2]-x[i+1]);
	*/
	int ans = 0;
	for (int s = 0; s < n; s++) {
		vector<int> dis(n, -1), ways(n); queue<int> q;
		dis[s] = 0, ways[s] = 1, q.push(s);
		while (!q.empty()) {
			int u = q.front(); q.pop();
			for (int v = 0; v < n; v++) if(abs(x[u] - x[v]) <= d) {
				if (dis[v] == -1) dis[v] = dis[u] + 1, ways[v] = ways[u], q.push(v);
				else if (dis[v] == dis[u] + 1) ways[v] = min(ways[v] + ways[u], 3);
			}
		}
		for (int t = s + 1; t < n; t++) ans += ways[t] == 2;
	}
	cout << ans << '\n';
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int c, t; cin >> c >> t;
	while (t--) solve();
	
	return 0;
}

