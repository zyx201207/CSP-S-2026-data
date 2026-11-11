#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll n, m, ans;
ll a[500010];

bool check(ll mid) {
	ll sum = 0;
	vector<ll> b;
	for (int i = 1; i <= n; i++) {
		if (a[i] > mid) {
			break;
		}
		b.push_back(mid - a[i]));
	}
	sort(b.begin(), b.end());
	for (int i = 0; i < n; i++) {
	    sum += b[i];
	}
	return (sum <= m);
}

int main() {
	//freopen("crystal.in", "r", stdin);
	//freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	ll l = 1, r = n;
	while (l <= r) {
		ll mid = (l + r) >> 1;
		if (check(mid)) {
			r = mid + 1;
			ans = mid;
		} else {
			l = mid - 1;
		}
	}
	cout << ans;
	return 0;
}
/*
5 5
1 2 4 8 9
3

5 8
-3 -1 2 2 7
4
*/
