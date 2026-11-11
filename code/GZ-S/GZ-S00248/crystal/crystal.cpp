//孙宇宸 GZ-S00248 贵阳市华师一学校 
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	int n;
	ll m;
	cin >> n >> m;
	vector<ll> a(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	int ans = 0;
	sort(a.begin() + 1, a.end());
	vector<ll> pre(n + 1);
	for (int i = 1; i <= n; ++i) {
		pre[i] = pre[i - 1] + a[i];
	}
	for (int i = 1; i <= n; ++i) {
		int l = 1, r = i - 1;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (a[i] * (i - mid + 1) - (pre[i] - pre[mid - 1]) <= m) {
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		}
		ans = max(ans, i - l + 1);
	}
	cout << ans << '\n';
	return 0;
}
