#include <bits/stdc++.h>
using namespace std;


int c, T, n, k;
int u[1000010];
int w[1000010];
int y[1000010];
int cnt[1000010];
int l, r, mid, ans;
bool vis[21][1000010];
vector<int> e[1000010];
int fa[1000010];
int find(int x) {
	if (!fa[x]) return x;
	else fa[x] = find(fa[x]);
}
bool check(int x) {
	queue<int> q;
	int t = 0, v = 0;
	memset(vis, 1, sizeof(vis));
	memset(cnt, 0, sizeof(cnt));
	memset(fa, 0, sizeof(fa));
	for (int i = 1; i <= n; i++) {
		if (e[i].size() == 1) {
			t = (t + 1) % 1000000;
			v++;
			u[t] = i;
			w[t] = x;
			y[t] = v;
			cnt[i]++;
			q.push(t);
			vis[v][i] = 1;
		}
	}
	while (q.size()) {
		int t = q.front();
		q.pop();
		for (int v : e[u[t]]) {
			if (!vis[y[t]][v]) {
				int nt = (t + 1) % 1000000;
				u[nt] = v;
				w[nt] = w[t] - 1;
				y[nt] = y[t];
				cnt[v]++;
				if (w[nt]) {
					q.push(nt);
					vis[y[nt]][v] = 1;
					t = nt;
				}
			}
		}
	}
	int h = 0, p = 0;
	for (int i = 1; i <= n; i++) {
		if (cnt[i] == v) {
			int u = i;
			for (int k : e[i]) {
				if (cnt[k] == v) {
					u = find(u);
					k = find(k);
					if (u != k) {
						fa[u] = k;
						h++;
					}
				}
			}
			p++;
		}
	}
	if (p - h > 2) {
		return false;
	} else {
		return true;
	}
}
int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> T;
	while (T--) {
		cin >> n >> k;
		for (int i = 1; i<= n; i++) e[i].clear();
		for (int i = 1; i <= n - 1; i++) {
			int u, v;
			cin >> u >> v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		l = 0, r = n;
		while (l <= r) {
			mid = (l + r) >> 1;
			if (check(mid)) {
				ans = mid;
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
