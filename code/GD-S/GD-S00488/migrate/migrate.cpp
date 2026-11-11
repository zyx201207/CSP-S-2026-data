#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2010000;
const int B = 100;
int id[N], st[N], ed[N];
vector<pair<int, int>> e[N];
int n, dis[N], f[N];
ll d, x[N];
bool v[N];

void addedge(int u, int l, int r) {
	if (l > r) return;
	if (id[l] == id[r]) {
		for (int v = l; v <= r; v++) {
			e[u].push_back(make_pair(v, 1));
		}
	} else {
		for (int v = l; v <= ed[id[l]]; v++) {
			e[u].push_back(make_pair(v, 1));
		}
		for (int v = id[l] + 1; v < id[r]; v++) {
			e[u].push_back(make_pair(v + n, 1));
		}
		for (int v = st[id[r]]; v <= r; v++) {
			e[u].push_back(make_pair(v, 1));
		}
	}
}

void solve() {
	scanf("%d%lld", &n, &d);
	for (int i = 1; i <= n + (n - 1) / B + 1; i++) e[i].clear();
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &x[i]);
		id[i] = (i - 1) / B + 1;
		e[id[i] + n].push_back(make_pair(i, 0));
		if (id[i] != id[i - 1]) {
			ed[id[i - 1]] = i - 1;
			st[id[i]] = i;
		}
	}
	ed[id[n]] = n;
	for (int u = 1; u <= n; u++) {
		int p = upper_bound(x + 1, x + n + 1, x[u] + d) - x - 1;
		addedge(u, u + 1, p);
	}
	ll ans = 0;
	for (int s = 1; s <= n; s++) {
		for (int t = 1; t <= n; t++) {
			dis[t] = 1 << 30;
			f[t] = 0;
			v[t] = false;
		}
		deque<int> q;
		dis[s] = 0;
		f[s] = 1;
		q.push_back(s);
		while (!q.empty()) {
			int u = q.front(); q.pop_front();
			if (f[u] > 2) continue;
			for (auto z : e[u]) {
				int v = z.first, w = z.second;
				if (w == 1) {
					if (dis[v] > dis[u] + 1) {
						dis[v] = dis[u] + 1;
						f[v] = f[u];
						q.push_back(v);
					} else if (dis[v] == dis[u] + 1) {
						f[v] += f[u];
					}
				} else {
					if (dis[v] > dis[u]) {
						dis[v] = dis[u];
						f[v] = f[u];
						q.push_front(v);
					} else if (dis[v] == dis[u]) {
						f[v] += f[u];
					}
				}
			}
		}
		for (int t = 1; t <= n; t++)
			if (f[t] == 2) ans += 1;
	}
	printf("%lld\n", ans);
}

int tp, tc;
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%d%d", &tp, &tc);
	for (int T = 0; T < tc; T++) {
		solve();
	}
	return 0;
}