#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 2e5 + 7;
char c[MAXN];
ll a[MAXN];
ll ans, tot;
int n, r;
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
		cin >> c[i];
		tot += a[i];
	}
	r = n;
	for (int l = 1; l < r; l++) {
		ll need = a[l];
		while (need > 0) {
			ll tmp = min(need, a[r]);
			if (c[r] == c[l]) {
				need -= tmp;
				a[r] -= tmp;
			} else {
				need -= tmp;
				a[r] -= tmp;
				ans += tmp;
			}
			if (a[r] == 0) r--;
			
		}
		
		a[l] = 0;
	}
	printf("%lld\n", ans);
}
