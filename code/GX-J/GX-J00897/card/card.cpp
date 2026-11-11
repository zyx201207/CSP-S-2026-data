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
inline void write(int s) {
	if (s < 10) {
		putchar(s ^ 48);
		return ;
	}
	write(s / 10);
	putchar(s % 10 ^ 48);
}
int n, m, a[500005], f[300005], sum[500005], vis[500005], vis2[300005];
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	n = read(), m = read();
	for (int i = 1; i <= n; i++) {
		a[i] = read();
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			vis[j] = 0;
			vis2[j] = 0;
			sum[j] = 1;
		}
		for (int j = i; j <= n; j++) {
			if (vis[a[j]] && sum[vis[a[j]]]) {
				for (int k = vis[a[j]]; k < i; k++) {
					sum[i] = 0;
				}
			}
			vis[a[j]] = j;
		}
		for (int j = 1; j <= n; j++) {
			if (sum[j]) {
				vis2[a[j]] = 1;
			}
		}
		for (int j = 1; j <= m; j++) {
			f[j] += vis2[j];
		}
	}
	for (int j = 1; j <= m; j++) {
		write(f[j]);
		putchar(' ');
	}
	return 0;
}
