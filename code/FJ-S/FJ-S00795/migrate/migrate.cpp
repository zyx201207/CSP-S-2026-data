#include <bits/stdc++.h>

char buf[1 << 17], *p1, *p2;
#define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 17, stdin), p1 == p2) ? EOF : *p1++)

inline long long read() {
	register int ch, sign = 0;
	register long long ret = 0;

	while (ch = getchar(), isspace(ch)) ;
	isdigit(ch) ? (ret = ch ^ 48) : (sign = ch == '-');
	while (ch = getchar(), isdigit(ch))
		ret = (ret << 3) + (ret << 1) + (ch ^ 48);

	return sign ? -ret : ret;
}

#define N ((int) 2e6)

using std::max;

int n;
long long d, a[N + 1];

int r[N + 1];

int f[N + 1], g[N + 1], h[N + 1];

main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);

	int _ = (read(), read());
	while (_ --> 0) {
		n = read(), d = read();
		for (int i = 1; i <= n; i++) a[i] = read();

		for (int i = 1, j = 1; i <= n; i++) {
			for (; j <= n && a[j] - a[i] <= d; j++) ;
			r[i] = j - 1;
		}

		for (int i = n; i; i--)
			if (i == r[i] || r[i - 1] == r[i]) g[i] = 0;
			else g[i] = r[i] - max(r[i - 1], i) + g[r[i]];
		for (int i = n; i > 1; i--) {
			if (i == r[i] || r[i - 1] == r[i]) h[i] = 0;
			else h[i] = r[i] - max(r[i - 1], i) + (r[i - 1] + 1 == r[i] ? h[r[i]] : f[r[i]]);

			if (i == r[i] || r[i - 2] == r[i]) f[i] = 0;
			else if (r[i - 1] == r[i]) f[i] = r[i] - max(r[i - 2], i) + g[r[i]];
			else f[i] = r[i] - max(r[i - 2], i) + (r[i - 1] + 1 == r[i] ? h[r[i]] : f[r[i]]);
		}

		long long ans = 0;
		for (int i = n, lst = 0; i; i--)
			if (i == r[i]) lst = 0;
			else if (i + 1 == r[i]) ans += lst;
			else ans += lst = f[r[i]] - g[r[i]];

		printf("%lld\n", ans);
	}

	return 0;
}