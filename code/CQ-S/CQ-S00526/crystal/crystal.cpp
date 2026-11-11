#include <bits/stdc++.h>
using namespace std;
//aÎÞÐò£¬¿ªlong long 
const int N = 5e5 + 5;
int n;
long long m, a[N], sum[N];
map<long long, int> mp;
int l, r;
bool check(int mid) {
	long long minn = 1e18;
	for (int i = 1; i + mid - 1 <= n; i++) {
		int lid = i, rid = i + mid - 1;
		long long now = 0;
		now = a[rid] * (rid - lid + 1) - (sum[rid] - sum[lid - 1]);
		minn = min(minn, now);
	}
	return minn <= m;
}
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		mp[a[i]]++;
	}
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++) {
		l = max(l, mp[a[i]]);
		sum[i] = sum[i - 1] + a[i];
	}
	r = n;
	int ans = -1;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (check(mid)) {
			ans = mid;
			l = mid + 1;
		}else {
			r = mid - 1;
		}
	}
	cout << ans;
	return 0;
}
