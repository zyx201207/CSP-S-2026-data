#include <bits/stdc++.h>
using namespace std;

const int N = 2e6 + 5;

long long d, ans, x[N];
int n, h, t, f[N], g[N], q[N];

void P(int x) {
	while (h <= t && q[h] < x)
		++h;
}

void I(int x) {
	while (h <= t && f[q[t]] > f[x])
		--t;
	q[++t] = x;
}

void solve1() {
	ans = 0, cin >> n >> d;
	for (int i = 1; i <= n; ++i)
		cin >> x[i];
	for (int i = 1; i <= n; ++i) {
		h = t = 0, q[0] = i, g[i] = 1;
		for (int j = i+1, l = i; j <= n; ++j) {
			while (x[j] - x[l] > d)
				++l;
			P(l);
			if (h > t)
				break;
			f[j] = f[q[h]] + 1, g[j] = g[q[h]];
			if (g[j] < 3) {
				for (int k = h+1; k <= t; ++k) {
					if (f[j] == f[q[k]] + 1) {
						g[j] += g[q[k]];
						if (g[j] > 2)
							break;
					}
					else
						break;
				}
			}
			I(j), ans += g[j] == 2;
		}
	}
	cout << ans << '\n';
}

void solve2() {
	ans = 0, cin >> n >> d;
	for (int i = 1; i <= n; ++i)
		cin >> x[i];
	h = t = 0, f[0] = 0, q[0] = g[1] = 1;
	for (int i = 2, l = 1; i <= n; ++i) {
		while (x[i] - x[l] > d)
			++l;
		P(l);
		if (h > t)
			break;
		f[i] = f[q[h]] + 1, g[i] = g[q[h]];
		if (g[i] < 3) {
			for (int j = h+1; j <= t; ++j) {
				if (f[i] == f[q[j]] + 1) {
					g[i] += g[q[j]];
					if (g[i] > 2)
						break;
				}
				else
					break;
			}
		}
		I(i), ans += (n - i + 1) * (g[i] == 2);
	}
	cout << ans << '\n';
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios :: sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int c, T;
	cin >> c >> T;
	while (T--) {
		if (c >= 11 && c <= 12)
			solve2();
		else
			solve1();
	}
	return 0;
}
