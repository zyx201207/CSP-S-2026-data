#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N = 5e5 + 5;

int n, m;

int power[N];

int minus[N], s1[N], s[N];

int change[N];

int ans = 1;

signed main () {
	freopen ("crystal.in", "r", stdin);
	freopen ("crystal.out", "w", stdout);
	
	scanf ("%lld%lld", &n, &m);
	
	for (int i = 1; i <= n; i++) {
		scanf ("%lld", &power[i]);
	}
	sort (power + 1, power + 1 + n);
	
	change[1] = 0;
	for (int i = 2; i <= n; i++) {
		change[i] = change[i - 1] + (power[i] - power[i - 1]) * (i - 1);
	}
	
	
	for (int i = 2; i <= n; i++) {
		int l = 1, r = i - 1;
		int cnt = 1;
		while (l <= r) {
			int mid = (l + r) / 2;
			if (change[i] - change[mid] - (mid - 1) * (power[i] - power[mid]) <= m) {
				r = mid - 1;
				cnt = mid;
			}
			else {
				l = mid + 1;
			}
		}
		ans = max (ans, i - cnt + 1);
	}
	
	printf ("%lld", ans);
	return 0;
}
