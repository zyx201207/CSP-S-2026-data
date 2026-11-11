#include <bits/stdc++.h>
using namespace std;

int n, ans;
long long m, a[500010], sum[500010];
bool check(int l, int r) {
	return (a[r] * (r - l) - (sum[r - 1] - sum[l - 1])) <= m;
}
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] + a[i];
	}
	for (int i = 1; i <= n; i++) {
		int l = 1, r = i - 1, mid, res = i - 1;
		while (l <= r) {
			mid = (l + r) >> 1;
			if (check(mid, i)) {
				res = mid;
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		}
		ans = max(ans, i - l + 1);
	}
	cout << ans;
	return 0;
} 
