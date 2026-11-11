#include<bits/stdc++.h>
using namespace std;

#define int long long

const int INF = 0x3f3f3f3f3f3f3f3f;
void solve() {
	int n, d;
	cin >> n >> d;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	if (n <= 300) {	
		vector<vector<int>> dp(n + 1, vector<int>(n + 1)), f(n + 1, vector<int>(n + 1, INF));
		for (int i = 1; i <= n; ++i) {
			f[i][i] = 0;
			dp[i][i] = 1;
			for (int j = i + 1; j <= n; ++j) {
				if (a[j] - a[i] <= d) {
					f[i][j] = 1;
					dp[i][j] = 1;
				}
				else 
					f[i][j] = INF;
			}
		}
		for (int i = 1; i <= n; ++i) {
			dp[i][i] = 0;
			for (int j = i; j <= n; ++j) {
				for (int k = i + 1; k < j; ++k) {
					if (f[i][k] != INF && f[k][j] != INF) {
						if (f[i][k] + f[k][j] == f[i][j]) {
							dp[i][j] += dp[i][k] * dp[k][j];
						}
						if (f[i][k] + f[k][j] < f[i][j]) {
							f[i][j] = f[i][k] + f[k][j];
							dp[i][j] = dp[i][k] * dp[k][j];
						}
					}
				}
			}
		}
		int ans = 0;
		for (int i = 1; i <= n; ++i) {
			for (int j = i + 1; j <= n; ++j) {
				if (dp[i][j] == 2) {
					ans++;
					// cout << i << " " << j << endl;
				}
			}
		}
		cout << ans << endl;
		return;
	}
	vector<vector<int>> adj(n + 1);
	vector<int> in(n + 1);
	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			if (a[j] - a[i] <= d) {
				adj[i].push_back(j);
				in[j]++;
			}
		}
	}
	queue<int> q;
	vector<int> dist(n + 1, INF), dp(n + 1);
	for (int i = 1; i <= n; ++i) 
		if (in[i] == 0) {
			q.push(i);
			dist[i] = 0;
			dp[i] = 1;
		}
		
	
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int v : adj[u]) {
			if (dist[v] == INF) {
				dist[v] = dist[u] + 1;
				dp[v] = dp[u];
			} else if (dist[v] == dist[u] + 1) {
				dp[v] += dp[u];
			} else if (dist[v] > dist[u] + 1) {
				dist[v] = dist[u] + 1;
				dp[v] = dp[u];
			}
			if (--in[v] == 0) q.push(v);
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j) if (dp[j] - dp[i] == 2) ans++;
	}
	cout << ans << endl;
}

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int c, t;
	cin >> c >> t;
	while (t--) {
		solve();
	}
	return 0;
}
