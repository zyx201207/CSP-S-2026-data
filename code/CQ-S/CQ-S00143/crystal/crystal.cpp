#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e6 + 10;
ll n, m, maxx;
ll a[N], s[N];
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (ll i = 1; i <= n; i++) cin >> a[i];
	sort (a + 1, a + n + 1);
	for (ll i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
	for (ll i = 1; i <= n; i++){
		ll l = i, r = n;
		while (l <= r){
			ll mid = l + r >> 1;
			if (a[mid] * (mid - i + 1) - s[mid] + s[i - 1] <= m) l = mid + 1;
			else r = mid - 1;
		}
		maxx = max(maxx, l - i);
	}
	cout << maxx;
	return 0;
}
