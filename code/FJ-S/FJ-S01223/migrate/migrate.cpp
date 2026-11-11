#include <bits/stdc++.h>
typedef long long ll;
const int N = 2e6 + 5;

int n, pre[N], nxt[N]; ll d;
ll a[N], f[N][3], ans, sum[N];
std::vector<int> e[N], g[N];

int len(int l, int r) {
	if (l > r) return 0;
	return r - l + 1;
}

int C;

void run()
{
	++C;
	scanf("%d%lld", &n, &d); ans = 0;
	for (int i = 1; i <= n; ++i) scanf("%lld", a + i);
//	printf("%d %lld  %lld\n", n, d, a[2] - a[1]);
	for (int i = 1; i <= n; ++i) e[i].clear(), g[i].clear();
	int j = 1;
	for (int i = 1; i <= n; ++i) {
		while (j < n && a[j + 1] - a[i] <= d) ++j;
		nxt[i] = j;
		e[i].push_back(j);
		g[j].push_back(i);
	}
	j = n;
	for (int i = n; i >= 1; --i) {
		while (j > 1 && a[i] - a[j - 1] <= d) --j;
		pre[i] = j;
	}
//	for (int i = 1; i <= n; ++i)
//		printf(">%d %d\n", pre[i], nxt[i]);
	for (int i = 1; i <= n; ++i) {
		f[i][0] = 1;
		f[i][1] = f[i][2] = 0;
		if (pre[i] == i) continue;
		if (nxt[pre[i]] == i) f[i][2] += f[pre[i]][2];
		else ans += f[pre[i]][2];
//		for (int j = pre[i] + 1; j < i; ++j)
//			ans += f[j][2];
//			printf(">%d %d %lld\n", i, j, f[j][2]);
		if (nxt[pre[i]] == i) {
			f[i][0] += f[pre[i]][0];
			for (int j : g[i])
				if (j > pre[i]) ++f[i][0];
		}
		if (f[pre[i]][1]) {
			if (nxt[pre[pre[i]] + 1] == pre[i]) { 
				if (nxt[pre[i]] == i) f[i][2] += f[pre[i]][1];
				else ans += f[pre[i]][1];
			}
		}
		int u = pre[i];
		if (u == i - 1) continue;
		if (pre[u + 1] == pre[u + 2]) continue;
		if (pre[u] != u) {
//			if (C == 12 && i == 5) puts("ok");
			if (pre[u] == pre[u + 1]) {
				f[i][1] += f[pre[u]][0] + len(pre[u] + 1, pre[u + 2] - 1);
			} else {
				f[i][1] += len(pre[u + 1], pre[u + 2] - 1);
			}
//			f[i][1] += sum[pre[u + 2] - 1] - sum[pre[u + 1] - 1];
//			for (int j = pre[u + 1]; j < pre[u + 2]; ++j)
//				f[i][1] += f[j][0];
		}
//		sum[i] = sum[i - 1] + f[i][0];
//		if (pre[u] != u && pre[u] == pre[u + 1])
//			f[i][1] = f[pre[u]][0];
//		if (g[i].size() <= 1) continue;
//		if (g[i].size() >= 3) {
//			int v = g[i][2];
//			if (pre[u] == pre[v]) continue;
//		}
//		int v = g[i][1];
//		if (pre[u] != u && pre[u] == pre[v])
//			f[i][1] = f[pre[u]][0];
	}
//	if (C == 12) {
//		for (int i = 1; i <= n; ++i) printf("%lld ", a[i]); puts("");
//		for (int i = 1; i <= n; ++i) printf("%d ", pre[i]); puts("");
//		for (int i = 1; i <= n; ++i) printf("%d ", nxt[i]); puts("");
//		for (int i = 1; i <= n; ++i) {
//			printf("%lld %lld %lld\n", f[i][0], f[i][1], f[i][2]);
//		}
//	}
//	for (int i = 1; i <= n; ++i)
//		if (C == 10) printf(">%lld %lld\n", f[i][0], f[i][1]);
	for (int i = 1; i <= n; ++i) ans += f[i][1] + f[i][2];
	printf("%lld\n", ans);
}

int main()
{
//	freopen("0.txt", "r", stdin);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, T; scanf("%d%d", &c, &T);
	while (T--) run();
	return 0;
}
