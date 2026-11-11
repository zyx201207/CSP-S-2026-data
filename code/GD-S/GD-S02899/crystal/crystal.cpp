#include <bits/stdc++.h>
#define int long long
#define rd read()
#define rep(i, x, y) for (int i = x; i <= y; i++)
using namespace std;
const int N = 5 + 5e5;
int n, m, a[N], p[N], ans;
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
bool chk(int len) {
	rep(r, len, n) {
		int l = r - len + 1;
		if (a[r] * len - (p[r] - p[l - 1]) <= m) return true;
	}
	return false;
}
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	n = rd; m = rd;
	rep(i, 1, n) a[i] = rd;
	sort(a + 1, a + n + 1);
	rep(i, 1, n) p[i] = p[i - 1] + a[i];
	int l = 1, r = n, mid;
	while (l <= r) {
		mid = (l + r) >> 1;
		if (chk(mid)) ans = mid, l = mid + 1;
		else r = mid - 1;
	}
	write(ans);
}
