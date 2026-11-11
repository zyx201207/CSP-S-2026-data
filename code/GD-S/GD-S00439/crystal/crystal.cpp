#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5 + 10;
int n;
ll m, a[N], s[N];
int main() {
	freopen("crystal4.in", "r", stdin);
//	freopen("crystal.out", "w", stdout);
	scanf("%d%lld", &n, &m);
	for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	sort(a + 1, a + 1 + n);
	for(int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
	int ans = 1;
	for(int i = 2; i <= n; i++) {
		ll l = 1, r = i, res = 1;
		while(l <= r) {
			ll mid = (l + r) >> 1;
			if(mid * a[i] - (s[i] - s[i - mid]) <= m) l = mid + 1, res = mid;
			else r = mid - 1;
		}
		ans = max(ans, (int)res);
	}
	printf("%d\n", ans);
	return 0;
} 
