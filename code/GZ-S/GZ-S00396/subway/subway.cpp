//GZ-S00396 罗思妤 北京师范大学贵阳附属中学 
#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int c, n, m, d, q, a[N], k, x, y, ans, o, p;
vector <int> e[N], f[N];
map <pair <int, int>, int> b;
bool g[N], l;
int main () {
	freopen ("subway.in", "r", stdin);
	freopen ("subway.out", "w", stdout);
	scanf ("%d%d%d%d%d", &c, &n, &m, &d, &q);
	for (int i = 1; i <= m; i++) scanf ("%d", &a[i]);
	for (int i = 1; i <= n; i++) {
		scanf ("%d", &k);
		for (int j = 1; j <= k; j++) {
			scanf ("%d%d", &x, &y);
			b[{i, x}] = y, e[x].push_back (i), f[i].push_back (x);
		}
	}
	while (q--) {
		scanf ("%d%d", &x, &y);
		ans = INT_MAX;
		for (int i = 0; i < e[x].size(); i++) for (int j = 0; j < e[y].size(); j++) if (e[x][i] == e[y][j]) ans = min (ans, a[x] + a[y] + b[{e[x][i], x}] + b[{e[y][j], y}]);
		if (ans != INT_MAX) {
			printf ("%d\n", ans);
			continue;
		}
		queue <pair <int, int> > h;
		memset (g, 0, sizeof(g)), l = 0, g[x] = 1, h.push({x, a[x]});
		while (!h.empty()) {
			if (l) break;
			o = h.front().first, p = h.front().second, h.pop();
			for (int i = 0; i < e[o].size(); i++) {
				if (l) break;
				p += b[{e[o][i], o}];
				for (int j = 0; j < f[e[o][i]].size(); j++) {
					if (f[e[o][i]][j] == y) {
						ans = p + a[i] + b[{e[o][i], y}], l = 1;
						break;
					}
					if (!g[f[e[o][i]][j]] && e[f[e[o][i]][j]].size() > 1) g[f[e[o][i]][j]] = 1, h.push({f[e[o][i]][j], p + b[{e[e[o][i]][i], e[o][i]}]});
				}
			}
		}
		printf ("%d\n", ans);
	}
	fclose (stdin);
	fclose (stdout);
	return 0;
}
