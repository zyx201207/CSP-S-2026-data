#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
typedef long long ll;
ll n, m;
ll a[N], b[N];
bool check(ll mid, int i) {
	ll sum = (i - mid + 1) * a[i];
	ll p = b[i] - b[mid - 1];
	if(sum - p <= m) return 1;
	return 0;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout); 
	ll ans = 1;
	cin >> n >> m;
	for(int i = 1; i <= n; i ++ ) cin >> a[i];
	sort(a + 1, a + 1 + n);
	for(int i = 1; i <= n; i ++ ) b[i] = a[i] + b[i - 1];
	for(int i = 1; i <= n; i ++ ) {
		ll l = 0, r = i;
		while(l + 1 < r) {
			ll mid = (l + r) / 2;
			if(check(mid, i)) r = mid;
			else l = mid;
		}
		ans = max(ans, i - r + 1);
	}
	cout << ans;
	return 0;
}
