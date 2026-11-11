#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5 + 10;
ll n, m, ans, a[N];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);

	scanf("%lld%lld", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	sort(a + 1, a + 1 + n);
	
	ll l = 1, r = 1, sum = 0, res = 1;
	while (l <= r && r <= n) {
		if (sum + (a[r + 1] - a[r]) * res <= m) {
			sum += (a[r + 1] - a[r]) * res;
			r++;
			res++;
			ans = max(ans, res); 
		} else {
			do {
				sum -= (a[r] - a[l]);
				res--;
				l++;
			} while (sum - (a[r] - a[l]) > m);
		}
	}
	
	printf("%lld\n", ans);
	return 0;
}
