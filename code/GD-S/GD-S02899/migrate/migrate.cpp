#include <bits/stdc++.h>
#define int long long
#define rd read()
#define fi first
#define se second
#define pii pair<int, int>
#define rep(i, x, y) for (int i = x; i <= y; i++)
using namespace std;
const int N = 5 + 1e6;
int c, t, n, d, a[N], ans, cnt, mn, dis[N], f[N];
int read() {
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') {
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		x = (x << 1) + (x << 3) + (ch ^ 48);
		ch = getchar();
	}
	return x * f;
}
void write(int x) {
	if (x < 0) x = -x, putchar('-');
	if (x > 9) write(x / 10);
	putchar(x % 10 + '0');
}
void solve() {
	n = rd; d = rd; ans = 0;
	bool chk = 0;
	rep(i, 1, n) a[i] = rd;
	rep(i, 1, n) {
		chk |= (a[i] - a[1] <= d && a[n] - a[i] <= d);
	}
	if (chk) {
		rep(i, 1, n) {
			int l = i + 1, r = n, res = -1, mid;
			while (l <= r) {
				mid = (l + r) >> 1;
				if (a[mid] - a[i] > d) res = mid, r = mid - 1;
				else l = mid + 1;
			}
			if (~res) {
				ans += res <= i + 3;
			}
		}
		write(ans), putchar('\n');
		return;
	}
	rep(i, 1, n) rep(j, i + 1, n) {
		rep(k, 1, n) f[k] = 0;
		rep(k, 1, n) dis[k] = LLONG_MAX;
		dis[i] = 0; f[i] = 1;
		rep(k, i + 1, j) {
			for (int l = k - 1; a[k] - a[l] <= d && l >= i; l--) {
				if (dis[l] + 1 < dis[k]) {
					dis[k] = dis[l] + 1;
					f[k] = f[l];
				} else if (dis[l] + 1 == dis[k]) f[k] += f[l];
			}
		}
		ans += f[j] == 2;
	}
	write(ans), putchar('\n');
}
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	c = rd; t = rd;
	while (t--) solve();
}
