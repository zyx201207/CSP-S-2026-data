#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = (int)5e5 + 5;
const int _N = N + 5;
ll n, m, a[_N];
bool canc(ll t) {
	ll res = m + 1;
	for(int i = t; i <= n; i++) {
		ll ai = a[i] - a[i - 1];
		res = min(res, t * ai - (a[i] - a[i - t]));
	}
	//cout << t << ": " << res << endl;
	return res <= m;
}
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	} sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++) a[i] += a[i - 1];
	ll l = 0, r = n + 1, mid;
	while(l + 1 < r) {
		mid = (l + r) / 2;
		if(canc(mid)) l = mid;
		else r = mid;
	} cout << l << endl;
	return 0;
} 
