#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e5 + 10;

int n, m, a[N], l, r, ans;

bool check(int x) {
	int cnt = 0;
	for(int i = 1;i <= x;i++) {
		cnt += a[x] - a[i];
	}
	for(int i = x + 1;i <= n;i++) {
		if(cnt <= m) return true;
		cnt += x * (a[i] - a[i-1]);
		cnt -= a[i] - a[i-x];
	}
	return cnt <= m;
}

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	sort(a + 1, a + 1 + n);
	l = 1, r = n;
	while(l < r) {
		int mid = l + r >> 1;
		if(check(mid)) {
			l = mid + 1;
			ans = mid;
		}
		else {
			r = mid;
		}
	}
	cout << ans;
	return 0;
}
