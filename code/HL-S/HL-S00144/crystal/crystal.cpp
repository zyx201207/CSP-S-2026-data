#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5 + 10;
ll a[N], tmp[N], s[N];
ll m; int n;
bool check (ll x) {
	int lx = 1, rx = x;
	while (rx <= n) {
		ll k = (s[rx] - s[lx - 1] + 1) * 1LL / x - 1;
		ll cost = 0;
		for (int i = lx; i <= rx; i++) {
			if (k - a[i] >= 0) 
				cost = cost + (k - a[i] * 1LL);
			else
				cost = cost + (a[i] * 1LL - k);	
			if (cost > m) break;	
		} 
		if (cost <= m)
			return true;
		lx++, rx++;	
	}
	return false;
}
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		s[i] = a[i] + s[i - 1];
	}
	int l = 1, r = n;
	while (l < r) {
		ll mid = (l + r + 1) / 2;
		if (check(mid))
			l = mid;
		else
			r = mid - 1;
	}
	cout << l << "\n"; 
	return 0;
} 

