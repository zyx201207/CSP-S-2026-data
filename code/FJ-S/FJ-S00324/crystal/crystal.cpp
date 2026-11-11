#include<bits/stdc++.h>
using namespace std;
#define int long long
int n, m, a[514527], l, ans, sum;
signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	sort(a + 1, a + n + 1); l = ans = 1; sum = 0;
	for(int i = 2; i <= n; i++){
		sum += (i - l) * (a[i] - a[i - 1]);
		while(sum > m) sum -= (a[i] - a[l++]);
		ans = max(ans, i - l + 1);
	}
	printf("%lld\n", ans);
	return 0;
}

