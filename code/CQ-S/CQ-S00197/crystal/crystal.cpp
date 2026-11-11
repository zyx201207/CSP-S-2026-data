#include<bits/stdc++.h>

using namespace std;
#define ll long long
ll n,m;
ll a[5000050];
bool check(ll mid) {
	for(ll i = 1;i <= n; i++) {
		ll sum = 0;
		if(i + mid - 1 > n) break;
		ll t = a[i + mid - 1];
		for(ll j = i;j <= i + mid - 1 && (i + mid - 1 <= n); j++){
			sum += t - a[j];
			if(sum > m) break;
		}
		//cout << sum << " ";
		i += mid - 1;
		if(sum <= m) return 1;
	}
	return 0;
}
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(ll i = 1;i <= n; i++) 
		cin >> a[i];
	sort(a + 1,a + 1 + n);
	ll l = 0,r = n,ans = 0;
	while(l <= r) {
		ll mid = (l + r) / 2;
		//cout << mid << '\n';
		if(check(mid)) {
			l = mid + 1;
			ans = mid;
		}else{
			r = mid - 1;
		}
		//cout << '\n';
	}
	cout << ans;
	return 0;
} 
