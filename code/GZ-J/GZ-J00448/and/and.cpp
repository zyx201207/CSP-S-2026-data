//GZ-J00448 ÁõãäÃú 
#include <bits/stdc++.h>
#define LL long long
using namespace std;

LL n, m, ans, a[200010];
LL sum[200010], dp[200010];

bool cmp (LL x, LL y) {
	return x > y;
}
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	scanf("%lld %lld", &n, &m);
	for (int t = 1; t <= n; t++)
		scanf("%lld", &a[t]);
	
	memset(dp, -1, sizeof(dp));
	sort(a + 1, a + n + 1, cmp);
	
	if (m == 1){
		printf("%lld", a[1]);
		return 0;
	}
	
	if (m == 2) {
		for (int t = 1; t <= n; t++) {
			for (int i = 1; i <= n; i++) {
				if (t == i) continue;
				ans = max(ans, a[t]  a[i]);
			}
		}
		printf("%lld", ans);
		return 0;
	}
	if (m == n) {
		for (int t = 1; t <= n; t++) {
			a[t + 1] = (a[t] and a[t + 1]);
		}
		printf("%lld", a[n]);
	}
	
	/*for (int t = 1; t <= n; t++)
		sum[t] = sum[t - 1] & a[t];
	for (int t = 1; t <= n; t++) {
		
	}*/
	//printf("%lld", dp[n]);
	
	return 0;
}
