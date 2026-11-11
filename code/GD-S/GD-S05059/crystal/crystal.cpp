#include <bits/stdc++.h>
using namespace std;

const int kMaxN = 5 * 1e5 + 5;

int a[kMaxN], s[kMaxN], n, m, mid=0, fans = 0;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin >> n >> m;
	int mx = -1, mi = 1e9;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
		mid += a[i] >= 0 ? a[i] : 0;
		mx = max(a[i], mx);
		mi = min(a[i], mi);
	}
	mid /= n;
//	sort(a + 1, a + 1 + n);
//	for (int k = mi; k <= mx; k ++) {
//		int am = 0;
//		for (int j = n; j >= 1; j --) {
//			if ((k - a[j]) <= m && (k - a[j]) >= 0) {
//				am ++;
//				m -= a[j];
//			}
//		}
//		cout << am << "\n";
//		ans = max(am, ans);
//	}
//	cout << mid << "\n";
//	for (int i = 1; i <= n; i ++) a[i] = mid - a[i];
	sort(a + 1, a + 1 + n);
//	cout << mid << "\n";
//	int idx = 1;
//	while (a[idx] < 0) idx ++;
	int k = -1;
	int ans = 0;
//	int p = m;
//	for (int i = n; i >= 1; i --) {
////		cout << mid - a[i] << " " << p << "\n";
//		if ((mid - a[i]) <= p && (mid - a[i]) >= 0) {
//			ans ++;
//			p -= (mid - a[i]);
//		}
//	}
	while (ans >= fans) {
		fans = ans;
		k ++;
		int ans1 = 0, p = m;
		for (int i = n; i >= 1; i --) {
			if ((mid + k - a[i]) <= p && (mid + k - a[i]) >= 0) {
				ans1 ++;
				p -= (mid + k - a[i]);
			}
		}
		int ans2 = 0;
		p = m;
		if (k != 0) {
			for (int i = n; i >= 1; i --) {
			if ((mid - k - a[i]) <= p && (mid - k - a[i]) >= 0) {
					ans2 ++;
					p -= (mid + k - a[i]);
				}
			}
		}
		
		ans = max(ans1, ans2);
//		cout << ans1 << " " << ans2 << " " << k << "\n";
		fans = max(ans, fans);
	}
	
	cout << fans;
	return 0;
} 
