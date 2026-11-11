#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int a[200005];
int n, m;
//bool t[200005];
//int forceans = -1;
//int force(int left, int leda, int index = 0) {
//	if (left <= 0) {
//		return leda & index;
//	}
//	for (int i = 1; i <= n; i++) {
//		if (!t[i]) {
//			t[i] = true;
//			force(index);
//			t[i] = false;
//		}
//	}
//}
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (n == m) {
		int ans = a[1];
		for (int i = 1; i <= n; i++) {
			ans = a[i] & ans;
			// << ans;
		}
		cout << ans << endl;
	}
	else if (m == 1) {
		cout << *max_element(a + 1, a + n + 1) << endl;
	}
	else if (m == 2) {
		int maxans = -10;
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				int f = a[i] & a[j];
				maxans = max(maxans, f);
			}
		}
		cout << maxans << endl;
	}
	/*else if (n <= 20) {
		cout << force(m, -1) << endl;
	}*/
	return 0;
}
