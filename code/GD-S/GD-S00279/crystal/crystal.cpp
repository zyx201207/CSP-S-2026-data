#include <iostream>
#include <algorithm>
using namespace std;

const int N = 5e5;

long long a[N + 5], pre[N + 5];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	long long m;
	int n;
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		pre[i] = pre[i - 1] + a[i];
	}
	
	int res = 0;
	for (int i = 1; i <= n; i++) {
		int le = 0, ri = i - 1, now = 0;
		while (le <= ri) {
			int mid = ((le + ri) >> 1);
			if (a[i] * mid - (pre[i - 1] - pre[i - mid - 1]) <= m) {
				now = mid;
				le = mid + 1;
			} else {
				ri = mid - 1;
			}
		} 
		res = max(res, now + 1);
	}
	cout << res << "\n";
	
	return 0;
} 
