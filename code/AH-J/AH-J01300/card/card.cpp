#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 5e5 + 2;
const int M = 3e5 + 2;
const int INF = 0x3f3f3f3f;
int n, m, a[N], b[M], t[M], l[N], r[N], ans[N];
vector<int> g[N];

void Dfs(int u) {
	ans[u] = 1;
	for (auto v : g[u]) {
		Dfs(v);
		ans[u] += ans[v];
	}
	b[a[u]] = max(b[a[u]], ans[u]);
}

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		l[i] = t[a[i]], t[a[i]] = i;
		r[l[i]] = i;
	}
	for (int i = 1; i <= n; i++) {
		if (l[i]) {
			g[i].push_back(l[i]);
		}
		if (!r[i]) {
			g[i + 1].push_back(i);
		}
	}
	Dfs(n);
	for (int i = 1; i <= m; i++) {
		printf("%d ", b[i]);
	}
	return 0;
}
