#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5 + 5;

int n, ans = 0;
ll m, a[N], sum[N];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; ++i) sum[i] = sum[i - 1] + a[i];
	for (int i = 1; i <= n; ++i) {
		int res = 0;
		for (int l = i, r = n, mid; l <= r;) {
			mid = (l + r) >> 1;
			if (a[mid] * (mid - i + 1) - (sum[mid] - sum[i - 1]) <= m) l = mid + 1, res = mid - i + 1;
			else r = mid - 1;
		}
		ans = max(ans, res);
	}
	cout << ans;
	return 0;
}

/*
a[j]-a[i]+a[j]-a[i+1]+a[j]-a[i+2]+...<=m
*/
