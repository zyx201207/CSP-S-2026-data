#include<bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;
const int MAXN = 5e5+5;
__int128 a[MAXN], s[MAXN];
ll ans = 1;
ll n,m;


bool check(ll l, ll r) {
	__int128 res = 0;
	__int128 tmp = s[r-1] - s[l-1];
	__int128 tmp1 = a[r] * (r - l);
	res = tmp1 - tmp;
	if (res > m) return false;
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++) {
		ll tmp;
		cin>>tmp;
		a[i] = tmp;
	}
	sort(a+1, a+n+1);
	for (int i=1;i<=n;i++) s[i] = s[i-1] + a[i];
	for (int i=2;i<=n;i++) {
		ll l=1,r=i-1;
		while(l<r) {
			ll mid = (l+r)>>1;
			if (check(mid, i)) {
				r = mid;
			}
			else {
				l = mid+1;
			}
		}
		ans = max(ans, i-r+1);
	}
	cout << ans;
	return 0;
}
