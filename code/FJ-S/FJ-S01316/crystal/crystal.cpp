#include <bits/stdc++.h>
#define N 500005
using namespace std;

typedef long long ll;

ll n, m, a[N], sum[N]; 

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(ll i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for(ll i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
	ll anss = 0;
	for(ll i = 1; i <= n; i++) {
		ll l = 1, r = i, ans = i + 1;
		while(l <= r) {
			ll mid = (l + r) >> 1;
			if((i - mid + 1) * a[i] - sum[i] + sum[mid - 1] <= m) ans = mid, r = mid - 1;
			else l = mid + 1;
		}
		anss = max(anss, i - ans + 1);
	}
	cout << anss;
	return 0;
}


