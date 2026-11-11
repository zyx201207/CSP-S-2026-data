// Waiting for the one,
#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;
int c, T, n;
long long d, a[N];
int dis[N];	// times of flight
int f[N], g[N];

inline long long read() {
	long long x = 0; bool f = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9') f |= (ch == '-'), ch = getchar();
	while (ch >= '0' && ch <= '9') x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int check(int u) {
	int ed = u;
	while (ed < n && a[ed + 1] - a[ed] <= d) ++ed;
	if (ed == u) return 0;
	// consider seg[u, ed]
	for (int i = u - 1; i <= ed + 1; i++) dis[i] = f[i] = g[i] = 0;
	for (int i = u + 1, j = u; i <= ed; i++) {
		while (a[i] - a[j] > d) ++j;
		dis[i] = dis[j] + 1;
	}
	f[u] = g[u] = 1;
	for (int i = u + 1, j = u, k = u; i <= ed; i++) {
		while (a[i] - a[j] > d) ++j;
		while (k <= i - 2 && dis[k + 1] == dis[i] - 1) ++k;
//		cout << '\t' << i << ' ' << j << ' ' << k << endl;
		f[i] = g[k] - g[j - 1];
		g[i] = g[i - 1] + f[i];
	}
	int cnt = 0;
	for (int i = u; i <= ed; i++) cnt += (f[i] == 2);
	
//	for (int i = u; i <= ed; i++) cout << dis[i] << ' '; puts("");
//	for (int i = u; i <= ed; i++) cout << f[i] << ' '; puts("");
	return cnt;
}

void subA(long long gap) {	// µÈ²îÊýÁÐ 
	long long step = d / gap;
	if (step <= 1) return puts("0"), void();
	printf("%lld\n", max(0ll, n - 2 * step + 1));
}

//void subC() {
//	
//}

void solve() {
	n = read(), d = read();
	for (int i = 1; i <= n; i++) a[i] = read();
	
	long long gap = a[2] - a[1]; bool flag = 1;
	for (int i = 3; i <= n; i++) flag &= (gap == a[i] - a[i - 1]);
	if (flag) return subA(gap), void();
	
//	if ((a[n] - a[1]) / d <= 12) return subC(), void();
	
	long long ans = 0;
	for (int u = 1; u <= n; u++) ans += check(u);
//	cout << check(1) << endl;
	printf("%lld\n", ans);
}	

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	c = read(), T = read();
	while (T--) solve();
	return 0;
}
/*
0 1
6 2
-4 -3 -2 -1 3 6
*/
