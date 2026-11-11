#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 4000000 + 5000; 
ll f[N], md[N], x[N];
int c, t;
void solve() {
	while (t--) {
		int n;
		ll d;
		scanf("%d%lld", &n, &d);
//		cout << n << ' ' << d << endl; 
		ll cz = 0;
		for (int i = 1; i <= n; i++) {
			scanf("%lld", &x[i]);
		}
		if (n < 2) {
			printf("0\n");
			continue;
		}
		cz = x[2] - x[1];
//		cout << d << ' ' << cz << endl;
		ll num = d / cz;
//		cout << ' ' << num << endl;
		long long ans = 0;
		for (int i = num + 1; i < 2 * num; i++) {
			ans += max(0, n - i);
		}
		printf("%lld\n", ans);
	}
	return;
}
int main() {
//	freopen("cs.txt", "w", stdout);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%d%d", &c, &t);
//	cout << c << ' ' << t << endl; 
	if (c == 11 || c == 12) {
		solve();
		return 0;
	}
	while (t--) {
		int n;
		ll d;
		scanf("%d%lld", &n, &d);
		for (int i = 1; i <= n; i++) {
			scanf("%lld", &x[i]);
		}
		long long ans = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				f[j] = 0;
				md[j] = n + 1;
			}
			md[i] = 0;
			f[i] = 1;
			for (int j = i + 1; j <= n; j++) {
				for (int k = j - 1; k >= i; k--) {
					if (x[j] - x[k] <= d) {
						if (md[j] > md[k] + 1) {
							md[j] = md[k] + 1;
							f[j] = f[k];
						} else if (md[j] == md[k] + 1) {
							f[j] += f[k];
						}
					} else {
						break;
					}
				}
			}
			for (int j = i + 1; j <= n; j++) {
				if (f[j] == 2) {
//					cout << i << ' ' << j << endl;
					ans++;
				}
			}
		}
		printf("%lld\n", ans);
//		cout << endl;
	}
	return 0;
}
