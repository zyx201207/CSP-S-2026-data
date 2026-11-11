#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e6 + 5;
vector<int> g[N];
int a[N];
ll res, dis, mi = 1e18;
int e; // 终点
bool vis[N];

void dfs(int x, int fa) { // x当前点 fa上一个点
	if (x == e) {
	   if (dis < mi) {
		   mi = dis;
		   res = 1;
	   } else if (dis == mi) res++;
	   return;
    }
	if (vis[x]) return;
	vis[x] = 1; dis++;
	for (int y : g[x]) {
		if (y == fa) continue;
		dfs(y, x);
	}
	vis[x] = 0; dis--;
}

void solve() {
	int n, d; scanf("%d%d", &n, &d);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]), g[i].clear();
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++) {
			if (abs(a[i] - a[j]) <= d) {
				g[i].push_back(j);
				g[j].push_back(i);
			}
		}
	ll ans = 0;
	for (int l = 1; l <= n; l++) {
		for (int r = l + 1; r <= n; r++) {
			res = 0, dis = 0, mi = 1e18, e = r;
			dfs(l, 0);
			if (res == 2) ans++;
		}
	}
	printf("%lld\n", ans);
}

int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
	int c, t; scanf("%d%d", &c, &t);
	while (t--) solve();
	return 0;
}
