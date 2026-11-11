#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, m, a[500010], sum[500010], ans[500010], ma, mi = 1e18;
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		mi = min(mi, a[i]);
	}
	mi = min(mi, 0LL);
	mi = abs(mi);
	for(int i = 1; i <= n; i++) {
		a[i] += mi;
	}
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] + a[i];
//		cout << sum[n - i + 1] << ' ';
	}
	for(int i = n; i >= 1; i--) { 
		int l = 1, r = n; //展示手写二分 
		while(l <= r) {
			int mid = (l + r) / 2;
			int x = sum[i - 1] - sum[mid - 1];
			if((i - mid) * a[i] - x <= m) r = mid - 1;
			else l = mid + 1;
		}
		ma = max(ma, i - l + 1);
	}
	cout << ma;
	return 0;
} 
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7

5 1
1 2 2 2 2
*/
