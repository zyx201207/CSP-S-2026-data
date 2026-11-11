#include <bits/stdc++.h>
#define int long long
#define rep(i, x, y) for (int i = x; i <= y; i++)
#define rd read()
using namespace std;
const int N = 5 + 2e5;
int n, m, a[N], cnt[40], vis[N], ans;
vector<int> e[40];
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
signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	n = rd; m = rd;
	rep(i, 1, n) a[i] = rd;
	rep(i, 1, n) {
		for (int j = 30; ~j; j--) {
			if ((a[i] >> j) & 1) ++cnt[j];
			else e[j].push_back(i);
		}
	}
	for (int i = 30; ~i; i--) {
		if (cnt[i] >= m) {
			ans = (ans << 1) | 1;
			for (auto j : e[i]) {
				if (!((a[j] >> i) & 1) && !vis[j]) {
					for (int k = 30; ~k; k--) if ((a[j] >> k) & 1) --cnt[k];
					vis[j] = 1;
				}
			}
		} else ans <<= 1;
	}
	write(ans);
}
