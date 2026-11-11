#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
long long a[N], sum[N];
/*
不能直接从 1 开始，因为可以从后面任意位置开始连续操作
似乎可以二分看最多可以加到多少。 
*/
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n;
	long long m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] + a[i];
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		//二分从 i 开始，最多可以加到 mid 
		int l = i, r = n;
		while (l < r) {
			int mid = (l + r + 1) >> 1;
			long long t = a[mid] * (mid - i + 1) - sum[mid] + sum[i - 1];
			if (t <= m) {
				l = mid;
			} else {
				r = mid - 1;
			}
		}
		ans = max(ans, l - i + 1);
	}
	cout << ans;
	return 0;
}
