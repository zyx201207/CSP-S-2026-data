#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 5;
typedef long long ll;
ll n, m, ans = -1;
ll crystal[MAXN], pre[MAXN];
bool check(ll mid) {
	for(ll i = 1; i + mid - 1 <= n; i++) {
		if(mid * crystal[i] - (pre[i + mid - 1] - pre[i - 1]) <= m) {
			return true;
		}
	}
	return false;
}
bool cmp(ll p, ll q) {
	return p > q;
}
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
//	freopen("E://csps-new//down//crystal//crystal3.in", "r", stdin);
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n >> m;
	for(ll i = 1; i <= n; i++) {
		cin >> crystal[i];
	}
	sort(crystal + 1, crystal + n + 1, cmp);
	for(ll i = 1; i <= n; i++)
		pre[i] = crystal[i] + pre[i - 1];
	ll L = 0, R = n;
	while(L <= R) {
		ll mid = L + (R - L) / 2;
		if(check(mid)) ans = mid, L = mid + 1;
		else R = mid - 1;
	}
	cout << ans << endl;
	return 0;
}
