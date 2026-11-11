#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	vector<char> b(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
	}
	int l = 0, r = n - 1, ans = 0;
	while (l < r) {
		if (b[l] == b[r]) {
			int tp = min(a[l], a[r]);
			a[l] -= tp;
			a[r] -= tp;
			if (!a[l]) {
				l++;
			}
			if (!a[r]) {
				r--;
			}
		} else {
			int tp = min(a[l], a[r]);
			ans += tp;
			a[l] -= tp;
			a[r] -= tp;
			if (!a[l]) {
				l++;
			}
			if (!a[r]) {
				r--;
			}
		}
	}
	cout << ans;
	return 0;
}