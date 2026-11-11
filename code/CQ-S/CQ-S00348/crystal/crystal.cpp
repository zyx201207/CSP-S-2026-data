#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e5 + 5;
 
int n, m;
int a[N], sum[N], ans = 0;

signed main () {
	freopen ("crystal.in", "r", stdin);
	freopen ("crystal.out", "w", stdout);
	ios::sync_with_stdio (false);
	cin.tie (0), cout.tie (0);
	cin >> n >> m;
	for (int i = 1; i <= n; ++ i) cin >> a[i];
	sort (a + 1, a + 1 + n);
	for (int i = 1; i <= n; ++ i) {
		sum[i] = sum[i - 1] + a[i];
		int L = 1, R = i, t, mid;
		while (L <= R) {
		 	mid = ((L + R) >> 1);
		 	if (sum[i] - sum[mid - 1] + m >= a[i] * (i - mid + 1)) R = mid - 1, t = mid;
		 	else L = mid + 1; 
		}
		ans = max (ans, i - t + 1);
	}
	cout << ans << "\n";
	return 0;
}
/*
虽然不想写但是还是写一下吧： 
连续的显然最优，修改为k则k属于a
a[i] * k - sum[i] <= m
k <= sum[i] + m / a[i]
*/
