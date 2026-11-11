//12
#include <bits/stdc++.h>
using namespace std;

const int N = 505, M = 1005;

int c, n, m, d, q;
int w[M], k[N], a[N][M], t[N][M], p[N][M];
vector<int> g[M];
bool v[M];
long long ans;

void bfs(int x, int e, long long sum) {
	if (x == e) {
		ans = min(ans, sum);
		return;
	}
	v[x] = true;
	for (auto y : g[x]) {
		for (int i = 1; i <= k[y]; i++)
			if (!v[a[y][i]]) {
				bfs(a[y][i], e, sum + t[y][p[y][x]] + t[y][i]);
				v[a[y][i]] = false;
			}
	}
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	bool flagk2 = true;
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
	for (int i = 1; i <= m; i++)
		scanf("%d", &w[i]);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &k[i]);
		if (k[i] > 2) flagk2 = false;
		for (int j = 1; j <= k[i]; j++) {
			scanf("%d%d", &a[i][j], &t[i][j]);
			g[a[i][j]].push_back(i);
			p[i][a[i][j]] = j;
		}
	}
	while (q--) {
		int x, y;
		scanf("%d%d", &x, &y);
		ans = 1e18;
		memset(v, false, sizeof v);
		bfs(x, y, 0);
		ans += w[x] + w[y];
		printf("%lld\n", ans);
	}
	return 0;
}
