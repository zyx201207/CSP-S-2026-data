#include <algorithm>
#include <iostream>
#include <cstdio>
#define int long long

using namespace std;

const int N = 4001, Inf = 1e18;

int c, T;
int n, k;
int a[N], b[N];
int f[N][N];
int ans;
int anc[N];
int find(int x) {
	return anc[x] == x? x : anc[x] = find(anc[x]);
}

int get() {
	for (int i = 1; i <= k; i ++ )
		anc[i] = i;
	for (int i = 1; i <= k; i ++ )
		for (int j = i + 1; j <= k; j ++ )
			if (f[a[i]][a[j]] == 1)
				anc[find(i)] = find(j); 
	int cnt = 0;
	for (int i = 1; i <= k; i ++ )
		if (find(i) == i)
			cnt ++ ;
	if (cnt > 2)
		return Inf;
	cnt = 0;
	for (int i = 1; i <= n; i ++ ) {
		int t = Inf;
		for (int j = 1; j <= k; j ++ )
			t = min(t, f[i][a[j]]);
		cnt = max(cnt, t);
	}
	return cnt;
}

void dfs(int u, int lst) {
	if (u > k) {
		ans = min(ans, get());
		return;
	}
	for (int i = lst; i <= n; i ++ )
		a[u] = i, b[i] = true, dfs(u + 1, i + 1), b[i] = false;
}

signed main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	scanf("%lld%lld", &c, &T);
	while (T -- ) {
		ans = Inf;
		scanf("%lld%lld", &n, &k);
		for (int i = 1; i <= n; i ++ )
			for (int j = 1; j < i; j ++ )
				f[i][j] = f[j][i] = Inf;
		for (int i = 1; i < n; i ++ ) {
			int u, v;
			scanf("%lld%lld", &u, &v);
			f[u][v] = f[v][u] = 1;
		}
		for (int u = 1; u <= n; u ++ )
			for (int i = 1; i <= n; i ++ )
				for (int j = 1; j <= n; j ++ )
					f[i][j] = min(f[i][j], f[i][u] + f[u][j]);
		dfs(1, 1);
		printf("%lld\n", ans);
	}
	return 0; // 20
}
