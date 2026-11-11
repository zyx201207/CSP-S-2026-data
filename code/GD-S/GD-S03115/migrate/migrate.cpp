#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
#define int long long

using namespace std;

const int N = 2e6 + 10, Inf = 1e18;

int c, T;
int n, d;
int a[N];
vector<int> g[N];
int dis[N], cnt[N];

void subA() {
	if (d < (a[3] - a[1]))
		puts("0");
	else {
		d /= (a[2] - a[1]);
		printf("%lld\n", max(0ll, n - d - d + 1));
	}
}

void dfs(int u) {
	for (int v : g[u]) {
		if (dis[v] > dis[u] + 1)
			dis[v] = dis[u] + 1, cnt[v] = 1, dfs(v);
		else if (dis[v] == dis[u] + 1)
			cnt[v] ++ , dfs(v);
	}
}

void baoli() {
	for (int i = 1; i <= n; i ++ )
		g[i].clear();
	for (int i = 1; i <= n; i ++ ) {
		for (int j = i + 1; j <= n; j ++ )
			if (a[j] - a[i] <= d)
				g[i].push_back(j);
			else
				break;
	}
	int ans = 0;
	for (int i = 1; i <= n; i ++ ) {
		for (int j = i; j <= n; j ++ )
			dis[j] = Inf, cnt[j] = 0;
		dis[i] = 0;
		dfs(i);
		for (int j = i + 1; j <= n; j ++ )
			ans += (cnt[j] == 2);
	}
	printf("%lld\n", ans);
}

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%lld%lld", &c, &T);
	while (T -- ) {
		scanf("%lld%lld", &n, &d);
		for (int i = 1; i <= n; i ++ )
			scanf("%lld", a + i);
		if (c == 11 || c == 12) {
			subA();
			continue;
		}
		if (c <= 6) {
			baoli();
			continue;
		} 
		puts("0");
	}
	return 0; // 16
}
