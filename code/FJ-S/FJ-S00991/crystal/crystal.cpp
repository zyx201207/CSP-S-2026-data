#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 5e5 + 5, INF = LONG_LONG_MAX - 1;
ll n, m, a[N], p[N];
bool check(ll x) {
	ll minn = INF, tmp, l;
	for(int r = x; r <= n; r++) {
		l = r - x + 1;
		tmp = p[r] - p[l - 1];
		minn = min(minn, a[r] * x - tmp);
	}
	return minn <= m;
}
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout); 
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++) 
		p[i] = p[i - 1] + a[i];
	ll l = 1, r = n, mid, ans = 1;
	while(l <= r) {
		mid = (l + r) >> 1;
		if(check(mid)) ans = mid, l = mid + 1;
		else r = mid - 1; 
	}
	cout << ans;
	return 0;
}
