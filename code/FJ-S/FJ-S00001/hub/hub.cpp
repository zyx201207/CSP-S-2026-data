#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5, inf = 1e9;
int c, t, n, k, u[N], v[N], dis[105][105], fa[105];
vector<int> e[N];
int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
void solve() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) e[i].clear();
	for (int i = 1; i < n; i++) {
		cin >> u[i] >> v[i];
		e[u[i]].push_back(v[i]);
		e[v[i]].push_back(u[i]);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) dis[i][j] = -1;
		dis[i][i] = 0; queue<int> q; q.push(i);
		while(!q.empty()) {
			int u = q.front(); q.pop();
			for (int v : e[u]) {
				if(dis[i][v] == -1) {
					dis[i][v] = dis[i][u] + 1;
					q.push(v);
				}
			}
		}
	}
	int ans = inf;
	for (int i = 0; i < (1 << n); i++) {
		int cnt = 0;
		for (int j = 1; j <= n; j++) cnt += (i & (1 << (j - 1))) > 0;
		if(cnt != k) continue;
		for (int j = 1; j <= n; j++) fa[j] = j;
		for (int j = 1; j < n; j++) {
			if((i & (1 << (u[j] - 1))) && (i & (1 << (v[j] - 1)))) fa[find(u[j])] = v[j];
		}
		cnt = 0;
		for (int j = 1; j <= n; j++) {
			if((i & (1 << (j - 1))) && fa[j] == j) cnt ++;
		}
		if(cnt <= 2) {
			int sum = 0;
			for (int j = 1; j <= n; j++) {
				int mi = inf;
				for (int k = 1; k <= n; k++) {
					if(i & (1 << (k - 1))) mi = min(mi, dis[k][j]);
				} sum = max(sum, mi); 
			} ans = min(ans, sum);
		}
	} cout << ans << '\n';
}
signed main() {
	freopen("hub.in", "r", stdin); freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0), cout.tie(0);
	cin >> c >> t;
	while(t --) solve();
	return 0;
}
