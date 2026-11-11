#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
vector<int> G[N];
int p, maxd;
void dfs(int u, int fa, int dep) {
	if (dep > maxd) {
		p = u;
		maxd = dep;
	}
	for (auto e : G[u]) {
		if (fa == e) continue;
		dfs(e, u, dep + 1);
	}
}
int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int c, t;
	scanf("%d%d", &c, &t);
	while (t--) {
		int n, k;
		scanf("%d%d", &n, &k);
		for (int i = 1; i <= n; i++) G[i].clear();
		for (int i = 1; i < n; i++) {
			int u, v;
			scanf("%d%d", &u, &v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
		if (c == 13 || c == 14) {
			int l = (n + 1) / 2 + 1;
			if (k == 1) printf("%d\n", l / 2);
			else printf("%d\n", (l - k + 3) / 4);
		} else {
			if (k == n) {
				printf("0\n");
				continue;
			}
			dfs(1, 0, 1);
			dfs(p, 0, 1);
			printf("%d\n", max((maxd - (k / 2 * 2) + 3) / 4, 1));
		}
	}
	return 0;
}
