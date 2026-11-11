#include <bits/stdc++.h>
using namespace std;

long long read() {
	long long x = 0, k = 1; char c = getchar();
	while (c != '-' && (c < '0' || c > '9')) c = getchar();
	if (c == '-') k = -1, c = getchar();
	while (c >= '0' && c <= '9') x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
	return x * k;
}

const int N = 2e6 + 7;

int n;
long long d;
long long x[N];
int p[N], q[N], suf[N], pre[N], f[N], g[N], cnt[N], fcnt[N], gcnt[N], fdir[N], gdir[N];

void solve() {
	n = read(), d = read();
	for (int i = 1; i <= n; i ++)
		x[i] = read();
	for (int i = 1, j = 1; i <= n; i ++) {
		while (j < n && x[j + 1] <= x[i] + d) j ++;
		p[i] = j;
	}
	for (int i = n, j = n; i >= 1; i --) {
		while (j > 1 && x[j - 1] >= x[i] - d) j --;
		q[i] = j; 
	}
	for (int i = 1; i <= n; i ++) {
		suf[i] = (i == q[p[i]] && p[i] != i ? p[i] : 0);
		pre[i] = (i == p[q[i]] && q[i] != i ? q[i] : 0);
	}
	for (int i = n; i >= 1; i --)
		f[i] = (suf[i] != 0 ? f[suf[i]] : i);
	for (int i = 1; i <= n; i ++)
		g[i] = (pre[i] != 0 ? g[pre[i]] : i);
	for (int i = 0; i <= n + 1; i ++) cnt[i] = 0;
	for (int i = 1; i <= n; i ++) if (g[q[i]] != q[i] && q[i] != i) cnt[g[q[i]]] ++;
	long long ans = 0;
	for (int i = 1, j = 1; i <= n; i ++) {
		if (f[p[i]] == p[i] || p[i] == i) continue;
		while (j <= n && j <= f[p[i]]) {
			if (g[q[j]] != q[j] && q[j] != j)
				cnt[g[q[j]]] --;
			j ++;
		}
		ans += 1ll * cnt[f[p[i]] - 1];
	}
	for (int i = 0; i <= n + 1; i ++) cnt[i] = 0;
	for (int i = 1; i <= n; i ++) cnt[q[i]] ++;
	for (int i = 1, j = 1; i <= n; i ++) {
		if (!p[i]) continue;
		while (j <= n && j <= p[i]) cnt[q[j ++]] --;
		ans += 1ll * cnt[p[i] - 1];
	}
	for (int i = 0; i <= n + 1; i ++) fcnt[i] = gcnt[i] = fdir[i] = gdir[i] = 0;
	for (int i = 1; i <= n; i ++) {
		if (suf[i]) fcnt[suf[i]] += fcnt[i];
		if (p[i] != i) fcnt[p[i]] ++, fdir[p[i]] ++;
	}
	for (int i = n; i >= 1; i --) {
		if (pre[i]) gcnt[pre[i]] += gcnt[i];
		if (q[i] != i) gcnt[q[i]] ++, gdir[q[i]] ++;
	}
	for (int j = 1; j <= n; j ++)
		if (g[q[j]] == q[j] && q[j] + 1 < j)
			ans += 1ll * fcnt[q[j] + 1] - fdir[q[j] + 1];
	for (int j = 1; j <= n; j ++)
		if (f[p[j]] == p[j] && p[j] - 1 > j)
			ans += 1ll * gcnt[p[j] - 1] - gdir[p[j] - 1];
	cout << ans << '\n';
}

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int qwq = 1, col;
	col = read(), qwq = read();
	while (qwq --)
		solve();
	return 0;
}
/*
0 2
6 4
-3 0 1 2 3 4
7 666666666666666663
-1000000000000000000 -555555555555555558 -111111111111111116 111111111111111105 333333333333333326 555555555555555547 999999999999999989

*/
