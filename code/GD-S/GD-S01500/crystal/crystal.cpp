#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e5 + 5;
const int LINF = 4e18;
ll n, m;
ll a[N], b[N], c[N];
bool check (ll x) {
	ll sum = 0, minn = LINF, cnt = 0;
	for (int i = 1; i < n; i ++) {
		sum += 1LL * b[i] * (i - cnt);
	//	if (x == 3)cout << i << ' ' << b[i] << ' ' << sum << ' ';
		if (i >= x) {
			cnt ++;
			sum = sum - c[i] + c[i - x];
		}
		if (i >= x - 1)	minn = min (minn, sum);
	//	if (x == 3) cout << sum << '\n';
		
	}
	return minn <= m;
}
int main () {
	ios::sync_with_stdio (0);
	cin.tie (0);
	freopen ("crystal.in", "r", stdin);
	freopen ("crystal.out", "w", stdout);
	cin >> n >> m;
	for (ll i = 1; i <= n; i ++) {
		cin >> a[i];
	//	cout << a[i] << ' ' << b[i - 1] << ' ' << c[i - 1] << '\n';
	}
	sort (a + 1, a + 1 + n);
	for (int i = 2; i <= n; i ++) {
		b[i - 1] = a[i] - a[i - 1];
		c[i - 1] = c[i - 2] + b[i - 1];
	}
	ll l = 1, r = n, mid;
	while (r - l >= 5) {
		mid = (r - l) / 2 + l;
		if (check (mid)) l = mid;
		else r = mid - 1; 
	}
	for (ll i = r; i >= l; i --) {
		if (check (i)) {
			cout << i;
			return 0;
		}
	}
	return 0;
} 
/*
test 1:

5 5
1 2 4 8 9


test 2:

5 8 
-3 -1 2 2 7
*/
