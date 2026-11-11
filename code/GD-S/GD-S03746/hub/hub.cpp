#include<bits/stdc++.h>
using namespace std;

const int N = 2e6 + 7;
const int INF = 0x3f3f3f3f;

int n, k;
int fa[N], dep[N], head[N << 1], to[N << 1], nxt[N << 1], cnt = 0;
void add(int u, int v) {
	to[cnt] = v;
	nxt[cnt] = head[u];
	head[u] = cnt++;
}
int tot = 0;
void dfs(int u, int f, int msk) {
	fa[u] = f;
	if ((1 << (u - 1)) & msk) {
		tot += ((1 << (f - 1)) & msk) == 0;
	}
	for (int i = head[u]; ~i; i = nxt[i]) {
		int v = to[i];
		if (v != f) {
			dfs(v, u, msk);
		}
	}
}
bool check(int msk) {
	if (__builtin_popcount(msk) != k) return false;
	tot = 0;
	dfs(1, 0, msk);
	return tot <= 2;
}
void solve() {
	cnt = 0;
	memset(head, -1, sizeof(head));
	memset(to, 0, sizeof(to));
	memset(nxt, 0, sizeof(nxt));
	cin >> n >> k;
	for (int i = 1; i <= n - 1; ++i) {
		int x, y;
		cin >> x >> y;
		add(x, y);
		add(y, x);
	}
	if (k == 2) {
		int ans = INF;
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				queue<int> q;
				vector<int> dist(n + 1, INF);
				dist[i] = 0;
				dist[j] = 0;
				q.push(i);
				q.push(j);
				while (!q.empty()) {
					int u = q.front();
					q.pop();
					for (int k = head[u]; ~k; k = nxt[k]) {
						int v = to[k];
						if (dist[v] > dist[u] + 1) {
							dist[v] = dist[u] + 1;
							q.push(v);
						}
					}
				}
				int res = 0;
				for (int k = 1; k <= n; ++k) res = max(res, dist[k]);
				ans = min(ans, res);
			}
		}
		cout << ans << endl;
		return;
	}
	int ans = INF;
	for (int i = 0; i < (1 << n); ++i) {
		vector<int> dist(n + 1, INF);
		if (!check(i)) continue;
		vector<bool> flag(N);
		queue<int> q;
		for (int j = 0; (1 << j) < i; ++j) {
			if ((1 << j) & i) {
				dist[j + 1] = 0;
				q.push(j + 1);
			}
		}
		while (!q.empty()) {
			int u = q.front();
			q.pop();		
			for (int j = head[u]; ~j; j = nxt[j]) {
				int v = to[j];
				if (dist[v] > dist[u] + 1) {
					dist[v] = dist[u] + 1;
					q.push(v);
				}
			}
		}
		int res = 0;
		for (int i = 1; i <= n; ++i) res = max(res, dist[i]);
		ans = min(res, ans);
	}
	cout << ans << endl;
}

signed main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int c, t;
	cin >> c >> t;
	while (t--) solve();
	return 0;
}
