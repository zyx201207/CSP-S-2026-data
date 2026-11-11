#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 5;
int t, n, d, ans, a[N], l[N], p[N];
signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%lld", &t);
	scanf("%lld", &t);
	while (t--){
		ans = 0;
		scanf("%lld", &n);
		scanf("%lld", &d);
		for (int i = 1; i <= n; i++){
			scanf("%lld", &a[i]);
		}
		for (int i = 1; i <= n; i++){
			l[i] = lower_bound(a + 1, a + n + 1, a[i] + d) - a;
			p[i] = upper_bound(a + 1, a + n + 1, a[i] - d) - a;
		}
		for (int i = 1; i <= n; i++){
			if (l[l[i] - 1] > i) ans++;
		}
		printf("%lld", ans);
	}
	return 0;
}
