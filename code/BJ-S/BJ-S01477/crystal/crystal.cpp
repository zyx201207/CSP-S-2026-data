#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 2;
int n;
long long m;
long long a[N], sum[N];
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] + a[i];
	}
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		// cout << "i:" << i << endl;
		//都变成a[i]
		//二分左边至多可以变到哪里
		int l = 1, r = i, tmp = 0;
		while(l <= r) {
			// cout << "l:" << l << " r:" << r << endl;
			int mid = (l + r) / 2;
			// cout << "mid:" << mid << endl;
			// cout << "i - 1 - mid + 1:" << i - 1 - mid + 1 << " a[i]:" << a[i] << endl;
			// cout << "sum[i-1]-sum[mid-1]:" << sum[i - 1] - sum[mid - 1] << endl;
			if((long long)(i - 1 - mid + 1) * a[i] - (sum[i - 1] - sum[mid - 1]) <= m) {
				r = mid - 1;
				tmp = mid;
			} else {
				l = mid + 1;
			}
		}
		// cout << "tmp:" << tmp << endl;
		ans = max(ans, i - tmp + 1);
	}
	cout << ans;
	return 0;
}