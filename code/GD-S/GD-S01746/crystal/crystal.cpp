#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int N = 5e5 + 5;
int n , m;
int a[N] , pre[N] , val[N];

bool check (int x) {
	int ans = 0;
	for (int i = 2 ; i <= x ; i++)
		ans += (i-1) * val[i];
	if (ans <= m) return true;
//	cerr << x << " " << ans << endl;
	for (int i = x + 1 ; i <= n ; i++) {
		ans -= (pre[i-1] - pre[i-x]);
		ans += (x-1) * val[i];
		if (ans <= m) return true;
	}
	return false;
}

signed main () {
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w" , stdout);
	scanf("%lld%lld" ,&n ,&m);
	for (int i = 1 ; i <= n ; i++)
		scanf("%lld" ,&a[i]);
	sort (a + 1 , a + n + 1);
	for (int i = 2 ; i <= n ; i++)
		val[i] = a[i] - a[i-1];
	for (int i = 2 ; i <= n ; i++)
		pre[i] = pre[i-1] + val[i];
	int l = 1 , r = n + 1;
	while (l + 1 < r) {
		int mid = (l + r) / 2;
		if (check(mid)) l = mid;
		else r = mid;
	}
	printf("%lld\n" , l);
	return 0;
}
