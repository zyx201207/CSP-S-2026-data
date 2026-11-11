#include <cstdio>
#define rep(i, l, r) for (int i = (l); i <= (r); i++)
#define per(i, r, l) for (int i = (r); i >= (l); i--)
typedef long long ll;
ll x[2000010];
int a[2000010];
ll f[2000010];
int cnt[2000010];
int n, d;
void hadcnt(int st) {
	rep (i, st + 1, n) f[i] = 2e18;
	f[st] = 0;
	rep (i, st, n) {
		if (f[i] == 2e18) break;
		per (j, a[i], i + 1) {
			if (f[j] < f[i] + 1) break;
			f[j] = f[i] + 1;
		}
	}
	rep (i, st + 1, n) cnt[i] = 0;
	cnt[st] = 1;
	rep (i, st, n) {
		if (f[i] == 2e18) break;
		rep (j, i + 1, a[i]) {
			if (f[j] == f[i] + 1) cnt[j] += cnt[i];
		}
	}
}
void solve() {
	ll ans = 0;
	scanf("%d%d", &n, &d);
	rep (i, 1, n) scanf("%lld", &x[i]), a[i] = i;
	int r = n;
	per (i, n, 1) {
		while (x[r] - x[i] > d && r >= i) r--;
		a[i] = r;
	}
	rep (i, 1, n) {
		hadcnt(i);
		rep (j, i + 1, n)
			ans += (cnt[j] == 2);
	}
	printf("%lld\n", ans);
}
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
    int c;
    scanf("%d", &c);
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}
