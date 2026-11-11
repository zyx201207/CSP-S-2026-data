#include <bits/stdc++.h>

using namespace std;

const long long N = 2e6 + 5;
const long long INF = 1e18;

long long c, t, n, x, a[N], d[N], u[N][2];

int main () {
	freopen ("migrate.in", "r", stdin);
	freopen ("migrate.out", "w", stdout);
	scanf ("%lld %lld", & c, & t); 
	while (t --) {
		scanf ("%lld %lld", & n, & x); 
		for (long long i = 0; i <= n; i ++) u[i][0] = u[i][1] = INF;
		long long l = 1, ans = 0, sum = 0;
		for (long long i = 1; i <= n; i ++) {
			scanf ("%lld", & a[i]); 
			while (a[i] - a[l] > x) d[l] = i - 1, l ++;
		}
		for (long long i = l; i <= n; i ++) d[i] = n;
		for (long long i = 1; i <= n; i ++) {
			long long s = 0, j = d[i], las = i, ans = 0;
			while (j < n) {
				if (las != i && u[j][s] != INF) {ans += u[j][s]; break;}
				if (j == las || j == d[j]) break;
				if (s == 0 && j > las + 1 && (las == i || d[las - 1] < j - 1)) {
					if (d[j - 1] > j) ans += d[j - 1] - d[j - 2]; 
				} else if (s == 1)
					ans += d[j] - d[j - 1];
				if (d[j - 2] == d[j] && j - 2 >= i) break;
				if (d[j - 1] == d[j]) {
					if (s == 1) break;
					if (s == 0)
						if (las != i && d[las - 1] == j - 1) break;
						else s = 1;
				}
				las = j, j = d[j];
			}
			long long kk = ans; s = 0, j = d[i], las = i, ans = 0;
			while (j < n) {
				if (las != i && u[j][s] != INF) {ans += u[j][s]; break;}
				if (las != i) u[j][s] = kk - ans;
				if (j == las || j == d[j]) break;
				if (s == 0 && j > las + 1 && (las == i || d[las - 1] < j - 1)) {
					if (d[j - 1] > j) ans += d[j - 1] - d[j - 2]; 
				} else if (s == 1)
					ans += d[j] - d[j - 1];
				if (d[j - 2] == d[j] && j - 2 >= i) break;
				if (d[j - 1] == d[j]) {
					if (s == 1) break;
					if (s == 0)
						if (las != i && d[las - 1] == j - 1) break;
						else s = 1;
				}
				las = j, j = d[j];
			}
			sum += ans;
		}
		printf ("%lld\n", sum);
	}
	return 0;
}
