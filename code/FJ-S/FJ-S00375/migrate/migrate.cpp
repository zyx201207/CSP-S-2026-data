#include <bits/stdc++.h>

#define int long long

const int N = 2e6 + 7;

int a[N], f[N], cnt[N];
int Case, T, n, D, ans;

void BFS(int x, int R) {
	std::queue<int> Q; Q.push(x); f[x] = 1;
	while (!Q.empty()) {
		int x = Q.front(); Q.pop();
		int pos = std::min(std::upper_bound(a + 1, a + n + 1, a[x] + D) - a - 1, R);
		for (int i = pos; i > x; i --)
			if (!f[i]) f[i] = f[x] + 1, Q.push(i);
	}
	cnt[x] = 1; Q.push(x);
	while (!Q.empty()) {
		int x = Q.front(); Q.pop();
		int pos = std::min(std::upper_bound(a + 1, a + n + 1, a[x] + D) - a - 1, R);
		for (int i = pos; i > x; i --)
			if (f[i] == f[x] + 1) cnt[i] ++, Q.push(i);
	}
}

void Solve(int l, int r) {
	if (r - l + 1 <= 3) return;
	for (int i = l; i <= r; i ++) {
		for (int j = i; j <= r; j ++) f[j] = cnt[j] = 0;
		BFS(i, r);
		for (int j = i; j <= r; j ++) ans += cnt[j] == 2;
	}
}

void solve() {
	ans = 0;
	scanf("%lld%lld", &n, &D); for (int i = 1; i <= n; i ++) scanf("%lld", &a[i]);
	for (int i = 1, l = 1; i <= n; i ++) if (i == n || a[i] + D < a[i + 1]) Solve(l, i), l = i + 1;
	printf("%lld\n", ans);
}

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);

	for (scanf("%lld%lld", &Case, &T); T --; ) solve();
	
	return 0;
} 
