#include <bits/stdc++.h>
using namespace std;

const int N = 2e6 + 10;
int c, t, n, a[N], b[N];
long long d, x[N];

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		scanf("%d%lld", &n, &d);
		for (int i = 1; i <= n; i++) {
			scanf("%lld", &x[i]);
		}
		long long ans = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = i+1; j <= n; j++) {
				int ta = 0, tb = 0, ansa = 0, ansb = 0;
				long long sum = 0;
				for (int k = i; k <= j; k++) {
					if (sum > d) {
						++ansa;
						a[ansa] = k-1;
						sum = x[i] - x[i-1];
					}
				}
				a[++ansa] = j;
				sum = 0;
				for (int k = j; k >= i; k--) {
					if (sum > d) {
						++ansb;
						b[ansb] = k-1;
						sum = x[i+1] - x[i];
					}
				}
				b[++ansb] = i;
				reverse(b+1, b+ansb+1);
				bool flag = 0;
				if (ansa != ansb) continue;
				for (int k = 1; k <= ansa; k++) {
					if (a[k] != b[k]) {
						flag = true;
						break;
					}
				}
				if (flag) ++ans;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
