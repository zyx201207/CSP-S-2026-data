#include <iostream>
#include <algorithm>
using namespace std;

const int M = 8e5;
long long n, m, a[M], num[M];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	long long minn = 2e12;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		minn = min(minn, a[i]);
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
		a[i] -= minn;
	for (int i = 1; i <= n; i++) 
		num[i] = num[i - 1] + a[i];
	
	int ans = 0;
	for (int k = 1; k <= n; k++) {
		int l = 1, r = k, x = k;
		while (l <= r) {
			int mid = (l + r) / 2;
			if ((k - mid + 1) * a[k] - (num[k] - num[mid - 1]) <= m) {
				x = mid;
				r = mid - 1;
			} else l = mid + 1;
		}
		ans = max(ans, k - x + 1);
	}
	cout << ans;
	return 0;
}
