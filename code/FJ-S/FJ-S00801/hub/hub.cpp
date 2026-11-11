#include <bits/stdc++.h>
using namespace std;

struct node {
	long long u, v;
} a[1000005];

long long dis[101][101], d[51], c, t, n, k, minn;
bool vis[51], b[51], v[51];
vector<long long> e[1000005];

void dfs1(long long u, long long fa) {
	vis[u] = 1;
	for (auto i : e[u]) {
		if (i == fa) continue;
		dfs1(i, u);
	}
}

void dfs2(long long x) {
	if (x == n + 1) {
		long long tot = 0;
		for (long long i = 0; i <= n; i++) {
			e[i].clear();
			d[i] = 1e18;
			vis[i] = 0;
		}
		long long cnt = 0;
		for (long long i = 1; i <= n; i++) {
			if (b[i]) cnt++;
		}
		if (cnt != k) return;
		for (long long i = 1; i < n; i++) {
			if (b[a[i].u] && b[a[i].v]) {
				e[a[i].u].push_back(a[i].v);
				e[a[i].v].push_back(a[i].u);
			}
		}
		for (long long i = 1; i <= n; i++) {
			if (!vis[i] && b[i]) {
				dfs1(i, 0);
				tot++;
			}
		}
		if (tot < 3) {
			long long maxn = 0;
			for (long long i = 1; i <= n; i++) {
				for (long long j = 1; j <= n; j++) {
					if (b[j]) d[i] = min(d[i], dis[i][j]);
				}
				maxn = max(maxn, d[i]);
			}
			minn = min(minn, maxn);
		}
		return;
	}
	b[x] = 0;
	dfs2(x + 1);
	b[x] = 1;
	dfs2(x + 1);
}

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		minn = 1e18;
		cin >> n >> k;
		for (long long i = 0; i <= n; i++) {
			for (long long j = 0; j <= n; j++) dis[i][j] = 1e18;
		}
		for (long long i = 1; i < n; i++) {
			cin >> a[i].u >> a[i].v;
			dis[a[i].u][a[i].v] = dis[a[i].v][a[i].u] = 1;
		}
		for (long long i = 1; i <= n; i++) dis[i][i] = 0;
		for (long long k = 1; k <= n; k++) {
			for (long long i = 1; i <= n; i++) {
				for (long long j = 1; j <= n; j++) dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
		dfs2(1);
		cout << minn << endl;
	}
	return 0;
}
