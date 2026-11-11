#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
int n;
long long m, a[N], s[N];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	sort(a+1, a+n+1);
	for (int i = 1; i <= n; i++) {
		s[i] = s[i-1] + a[i];
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int left = 1, right = i, res = -1;
		while (left <= right) {
			int mid = (left + right) >> 1;
			long long len = i-mid+1;
			long long tmp = len * a[i] - (s[i]-s[mid-1]);
			if (tmp <= m) {
				res = mid;
				right = mid - 1;
			} else {
				left = mid + 1;
			}
		}
		ans = max(ans, i - res + 1);
	}
	cout << ans;
	return 0;
}
