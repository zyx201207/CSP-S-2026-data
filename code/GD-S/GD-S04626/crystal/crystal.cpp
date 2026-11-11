#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m, a[500001], sum, ans;
signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	for (int i = 1; i <= n; i++){
		scanf("%lld", &a[i]);
	}
	sort(a + 1, a + n + 1);
	for (int i = 1, j = 1; i <= n; i++){
		while (sum <= m && j <= n){
			sum += (a[j + 1] - a[j]) * (j - i + 1);
			j++;
		}
		ans = max(ans, j - i);
		sum -= a[j] - a[i];
	}
	printf("%lld", ans);
	return 0;
}
