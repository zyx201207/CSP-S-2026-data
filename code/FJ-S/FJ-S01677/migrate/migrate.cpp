#include <bits/stdc++.h>
using namespace std;

inline long long read(void) {
	long long x = 0, f = 1; char c = getchar();
	while (c > '9' || c < '0') {
		if (c == '-') f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') x = (x << 1) + (x << 3) + c - 48, c = getchar();
	return x * f;
}

long long c, T, n, d, ans, a[2000005], nxt[2000005], f[2000005][5];

int main(void) {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	c = read(), T = read();
	while (T--) {
		n = read(), d = read(), ans = 0;
		for (int i = 1; i <= n; i++) {
			a[i] = read();
			f[i][0] = f[i][1] = f[i][2] = f[i][3] = f[i][4] = 0;
		}
		nxt[n] = n;
		for (int i = n - 1; i >= 1; i--) {
			nxt[i] = nxt[i + 1];
			while (a[nxt[i]] - a[i] > d) nxt[i]--;
		}
		for (int i = n; i >= 1; i--) {
			if (nxt[i] == i) continue;
			if (i > 3) {
				if (nxt[i - 1] <= i) {
					if (nxt[i] - i >= 3) f[i][0] = f[nxt[i]][0];
					else if (nxt[i] - i == 2) f[i][0] = f[nxt[i]][1];
					else f[i][0] = f[nxt[i]][2];
				} else if (nxt[i - 2] <= i) {
					f[i][0] = nxt[i - 1] - i;
					if (nxt[i] == nxt[i - 1]) f[i][0] += f[nxt[i]][3];
					else if (nxt[i] - nxt[i - 1] >= 3) f[i][0] += f[nxt[i]][0];
					else if (nxt[i] - nxt[i - 1] == 2) f[i][0] += f[nxt[i]][0];
					else f[i][0] += f[nxt[i]][4];
				} else if (nxt[i - 1] == nxt[i - 2]) {
					if (nxt[i] > nxt[i - 1]) {
						if (nxt[i] - nxt[i - 1] >= 3) f[i][0] = f[nxt[i]][0];
						else if (nxt[i] - nxt[i - 1] == 2) f[i][0] = f[nxt[i]][0];
						else f[i][0] = f[nxt[i]][4];
					} else f[i][0] = 0;
				} else {
					f[i][0] = nxt[i - 1] - nxt[i - 2];
					if (nxt[i] == nxt[i - 1]) f[i][0] += f[nxt[i]][3];
					else if (nxt[i] - nxt[i - 1] >= 3) f[i][0] += f[nxt[i]][0];
					else if (nxt[i] - nxt[i - 1] == 2) f[i][0] += f[nxt[i]][0];
					else f[i][0] += f[nxt[i]][4];
				}
			}
			if (i > 2) {
				if (nxt[i - 1] <= i) {
					if (nxt[i] - i >= 3) f[i][1] = f[nxt[i]][0];
					else if (nxt[i] - i == 2) f[i][1] = f[nxt[i]][1];
					else f[i][1] = f[nxt[i]][2];
				} else {
					f[i][1] = nxt[i - 1] - i;
					if (nxt[i - 1] == nxt[i]) f[i][1] += f[nxt[i]][3];
					else if (nxt[i] - nxt[i - 1] >= 3) f[i][1] += f[nxt[i]][0];
					else if (nxt[i] - nxt[i - 1] == 2) f[i][1] += f[nxt[i]][0];
					else f[i][1] += f[nxt[i]][4];
				}
			}
			if (i > 1) {
				if (nxt[i] - i >= 3) f[i][2] += f[nxt[i]][0];
				else if (nxt[i] - i == 2) f[i][2] += f[nxt[i]][1];
				else f[i][2] += f[nxt[i]][2];
			}
			if (i > 1) {
				if (nxt[i - 1] > i) {
					if (nxt[i - 1] != nxt[i]) f[i][3] = nxt[i] - nxt[i - 1] + f[nxt[i]][3];
					else f[i][3] = 0;
				} else f[i][3] = nxt[i] - i + f[nxt[i]][3];
			}
			if (i > 2) {
				if (nxt[i - 1] > i) {
					if (nxt[i] - nxt[i - 1] >= 3) f[i][4] = f[nxt[i]][0];
					else if (nxt[i] - nxt[i - 1] == 2) f[i][4] = f[nxt[i]][0];
					else if (nxt[i] - nxt[i - 1] == 1) f[i][4] = f[nxt[i]][4];
				} else {
					if (nxt[i] - i >= 3) f[i][4] = f[nxt[i]][0];
					else if (nxt[i] - i == 2) f[i][4] = f[nxt[i]][1];
					else f[i][4] = f[nxt[i]][2];
				}
			}
			if (nxt[i] - i >= 3) ans += f[nxt[i]][0];
			else if (nxt[i] - i == 2) ans += f[nxt[i]][1];
			else ans += f[nxt[i]][2];
		}
		printf("%lld\n", ans);
	}
	return 0;
}
