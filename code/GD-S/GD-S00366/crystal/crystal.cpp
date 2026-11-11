#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int n, ans;
long long m, a[N], b[N];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; ++i) b[i] = b[i - 1] + a[i];
	int pos = 1;
	for (int i = 1; i <= n; ++i) {
		while (pos < n && a[pos + 1] * (pos + 1 - i + 1) - (b[pos + 1] - b[i - 1]) <= m) ++pos;
		ans = max(ans, pos - i + 1);
	}
	cout << ans;
	return 0;
}
/*
int l = i, r = n;
while (l < r) {
	int mid = (l + r + 1) >> 1;
	if (a[mid] * (mid - i + 1) - (b[mid] - b[i - 1]) <= m) l = mid;
	else r = mid - 1;
}
*/
