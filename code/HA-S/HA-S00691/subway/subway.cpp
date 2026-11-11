#include <bits/stdc++.h>
#define f first
#define s second
#define put make_pair
using namespace std;
typedef pair<int, int> PII;
const int N = 1e6 + 10, M = 1e3 + 5;
int c, n, m, d, q;
int w[N];
int f[N], t[N], l[N], cnt;
int h[N], e[N], ne[N], idx;
int mp[M][M];
void add(int u, int v, int a) {
	e[idx] = v, w[idx] = a, ne[idx] = h[u], h[u] = idx++;
}
int dis[N];
bool vis[N];
void dfs(int u) {
	memset(dis, 0x7f, sizeof dis);
	memset(vis, 0, sizeof vis);
	dis[u] = 0;
	priority_queue<PII, vector<PII>, greater<PII> > q;
	q.push(put(0, u));
	while (!q.empty()) {
		PII t = q.top();
		q.pop();
		int diss = t.f, id = t.s;
		if (vis[id]) continue;
		vis[id] = true;
		for (int i = h[id]; ~i; i = ne[i]) {
			int j = e[i];
			if (dis[j] > diss + w[i]) {
				dis[j] = diss + w[i];
				q.push(put(dis[j], j));
			}
			
		}
	}
}
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	memset(h, -1, sizeof h);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
		f[++cnt] = i, t[cnt] = i + m, l[cnt] = w[i];
	}
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		for (int j = 1; j <= k; j++) {
			int a, ti;
			cin >> a >> ti;
			f[++cnt] = a + m, t[cnt] = 2 * m + i, l[cnt] = ti;
		}
	}
	for (int i = 1; i <= cnt; i++) {
		add(f[i], t[i], l[i]);
		add(t[i], f[i], l[i]);
	}
	for (int i = 1; i <= m; i++) {
		dfs(i);
		for (int j = 1; j <= m; j++) {
			mp[i][j] = dis[j];
		}
	}
	while (q--) {
		int x, y;
		cin >> x >> y;
		cout << mp[x][y] << endl;
	}
	return 0;
}
