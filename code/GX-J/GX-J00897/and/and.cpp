#include <bits/stdc++.h>
using namespace std;
inline int read() {
	int x = 0;
	char c = getchar();
	while (c < '0' || c > '9') {
		c = getchar();
	}
	while ('0' <= c && c <= '9') {
		x = (x << 3) + (x << 1) + (c ^ 48);
		c = getchar();
	}
	return x;
}
int n, m, a[200005], f[200005], ans;
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	n = read(), m = read();
	for (int i = 1; i <= n; i++) {
		a[i] = read();
		f[i] = 1;
	}
	sort(a + 1, a + n + 1);
	for (int j = 29; j >= 0; j--) {
		int cnt = 0;
		for (int i = n; i >= 1; i--) {
			if (!f[i]) {
				continue;
			}
			if ((a[i] >> j) & 1) {
				cnt++;
			}
		}
		if (cnt >= m) {
			ans |= (1 << j);
			for (int i = n; i >= 1; i--) {
				if (!f[i]) {
					continue;
				}
				if (((a[i] >> j) & 1) == 0) {
					f[i] = 0;
				}
			}
		}
	}
	cout << ans;
	return 0;
}
