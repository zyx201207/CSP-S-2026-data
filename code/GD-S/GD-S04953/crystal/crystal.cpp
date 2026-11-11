#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#define ll long long

using namespace std;
const int MAXN = 5e5 + 10;
ll n, m;
ll a[MAXN];
ll p[MAXN];
ll l = 1e12, r = -1e12;
bool check(ll x) {
	int pos = 0;
	for(int i = 1;i <= n;i ++) {
		if(a[i] > x) {
			pos = i - 1;
			break;
		}
	}
	if(pos == 0) pos = n;
	return (ll)(x * pos - p[pos]) <= m;
}
ll ans;
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i ++) {
		cin >> a[i];
		l = min(l, a[i]);
		r = max(r, a[i]);
	}
	sort(a + 1, a + 1 + n);
	for(int i = 1;i <= n;i ++) {
		p[i] = p[i - 1] + a[i];
	}
	while(l <= r) {
		ll mid = l + (r - l) / 2;
		if(check(mid)) {
			ans = mid;
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	int pos = 0;
	for(int i = 1;i <= n;i ++) {
		if(a[i] > ans) {
			pos = i - 1;
			break;
		}
	}
	if(pos == 0) pos = n;
	cout << pos;
	return 0;
}
