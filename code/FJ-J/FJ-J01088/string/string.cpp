#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10;
int n, a[N], s[N];
char c[N];
signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
//	freopen("string6.in", "r", stdin);
//	freopen("strings.out", "w", stdout);
	scanf("%lld", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld %c", &a[i], &c[i]);
		s[i] = s[i - 1] + a[i];
	}
	int m = 0, y = 0;
	int ups = (s[n] - 1) / 2 + 1;
	for (int i = 1; i <= n; i++) {
		m += a[i];
		if (m > ups) {
			y = i;
			break;
		}
	}
	int ya = y, yb = y;
	int la, lb;
	if (s[n] % 2 == 0) {
		la = ups - s[y - 1];
		lb = s[y] - ups;
	}
	else {
		la = ups - s[y - 1] - 1;
		lb = s[y] - ups;
	}
	int ans = 0;
	while (true) {
		if (la < lb) {
			if (c[ya] != c[yb]) {
				ans += la;
			}
			lb -= la;
			if (ya != 1) {
				ya--;
				la = a[ya];
			}
			else {
				break;
			}
		}
		else {
			if (c[ya] != c[yb]) {
				ans += lb;
			}
			la -= lb;
			if (yb != n) {
				yb++;
				lb = a[yb];
			}
			else {
				break;
			}
		}
	}
	printf("%lld", ans);
	return 0;
}
