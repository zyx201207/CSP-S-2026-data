#include<bits/stdc++.h>
using namespace std;
#define int long long
#define Min(a, b) a = min(a, b)
#define pp pair<int, int>
#define ft first
#define sd second
const int N = 5005;
int c, t, n, mx, ans, a[N];
int d[N][N], cnt[N][N], vis[N][N];
vector<int> g[N];
void init() {
	ans = 0;
	for (int i = 1; i <= n; i++) {
		g[i].clear();
		for (int j = 1; j <= n; j++) {
			cnt[i][j] = vis[i][j] = 0;
			d[i][j] = 1e18;
		}
	}
}
void djk(int x) {
	queue<pp> q;
	d[x][x] = 0;
	cnt[x][x] = 1;
	q.push({0, x});
	while (!q.empty()) {
		auto tp = q.front(); q.pop(); 
		int u = tp.sd;
		if (vis[x][u]) continue;
		vis[x][u] = 1;
		int z = d[x][u] + 1;
		for (int i : g[u]) {
			if (vis[x][i] || z > d[x][i]) continue;
			if (z < d[x][i]) {
				d[x][i] = z;
				cnt[x][i] = cnt[x][u];
				q.push({-z, i});
			}
			else cnt[x][i] += cnt[x][u];
		}
	}
}
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> c >> t;
	while (t--) {
		cin >> n >> mx, init();
		for (int i = 1; i <= n; i++) cin >> a[i];
		sort(a + 1, a + 1 + n);
		for (int i = 1; i <= n; i++)
			for (int j = 1; j < i; j++) 
				if (a[i] - a[j] <= mx) {
					g[j].push_back(i);
					g[i].push_back(j);
				}
		for (int i = 1; i <= n; i++) djk(i);
		for (int i = 1; i <= n; i++) 
			for (int j = i + 1; j <= n; j++) 
				if (cnt[i][j] == 2) ans++;
		cout << ans << "\n";
	}
	return 0;
}
