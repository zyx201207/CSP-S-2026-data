#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 5e6 + 5, M = 1e12 + 5;
ll n, m, a[N], res;
ll ans = 0;
ll sum[N];
bool check(ll x) {
	ll cst = 0, tot = 0;
	ans = 0;
	for (ll i = 1; i + x - 1 <= n; i ++) {
		cst = 0;
		ll d = a[i + x - 1];
		cst = d * x - sum[i + x - 1] - sum[i - 1]; 
		if (cst <= m) return 1;
	}
	return false;
} 
bool subtaskA = 1, subtaskB = 1;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	ll tmp  = 0;
	for (ll i = 1; i <= n; i ++) {
		cin >> a[i];
//		if (a[i] != i) subtaskA = 0;
//		if (i >= 3 && a[i] - a[i - 1] != a[i - 1] - a[i - 2]) subtaskB = 0;
	}
//	if (subtaskA == 1) {
//		
//	}
//	cout << tmp << "\n";
	sort(a + 1, a + n + 1);
	for (ll i = 1; i <= n; i ++) {
		sum[i] = sum[i - 1] + a[i];
	}
	ll l = 0, r = n;

	while (l < r) {
		ll mid = (l + r + 1LL) >> 1;
//		cout << l << " " << r << endl;
		if (check(mid)) {
			l = mid;
		} else r = mid - 1;
	}
	cout << l;
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/
