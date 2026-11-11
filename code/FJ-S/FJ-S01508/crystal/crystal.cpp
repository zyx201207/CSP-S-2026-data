#include <bits/stdc++.h>
#define int long long
using namespace std;
const int Max = 5e5 + 9;
int n, m, a[Max], num[Max], cnt[Max], ans = 1;
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for(int i = 2; i <= n; i++) cnt[i] = a[i] - a[1], num[i] = num[i-1] + cnt[i];
	for(int i = 1; i <= n; i++) {
		int l = 1, r = i-1, tans = 0;
		while(l <= r) {
			int mid = (l + r) >> 1;
			int t = (i - mid) * cnt[i] - (num[i-1] - num[mid-1]);
			if(t <= m) r = mid - 1, tans = mid;
			else l = mid + 1; 
		}
		ans = max(ans, i - tans + 1);
	}
	cout << ans;
	return 0;
}
