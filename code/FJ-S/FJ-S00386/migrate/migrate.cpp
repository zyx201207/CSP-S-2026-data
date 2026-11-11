#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int readint() {
	int nu = 0;
	bool sign = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9') (ch == '-') && (sign = 1), ch = getchar();
	while (ch >= '0' && ch <= '9') nu = nu * 10 + ch - '0', ch = getchar();
	sign && (nu = -nu);
	return nu;
}
ll readll() {
	ll nu = 0;
	bool sign = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9') (ch == '-') && (sign = 1), ch = getchar();
	while (ch >= '0' && ch <= '9') nu = nu * 10ll + ch - '0', ch = getchar();
	sign && (nu = -nu);
	return nu;
}
const int maxn = 2e6 + 5;
int c, t, n;
ll d, x[maxn], f[maxn], dis[maxn];
bool sf[maxn];
int main()  {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	c = readint(); t = readint();
	while (t--) {
		n = readint();
		d = readll();
		ll ans = 0;
		for (int i = 1; i <= n; ++i) x[i] = readll(), sf[i] = false;
		if (n <= 3) {
			puts("0");
		}
		for (int i = 1; i <= n; ++i) {
			for (int j = i + 3; j <= n; ++j) {
				f[i] = 1;
				dis[i] = 0;
				for (int k = i + 1; k <= j; ++k) {
					int minx = dis[k - 1], cnt = 0;
					for (int l = k - 1; l >= i; --l) {
						if (x[k] - x[l] > d) break;
						if (dis[l] < minx) minx = dis[l], cnt = f[l];
						else if (dis[l] == minx) cnt += f[l];
					}
					dis[k] = minx + 1;
					f[k] = cnt;
				}
				if (f[j] == 2) ++ans;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

*/
