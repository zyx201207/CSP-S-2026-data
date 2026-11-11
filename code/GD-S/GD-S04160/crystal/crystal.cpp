#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n, m, a[500005], s[500005];
ll gt(ll j, ll i){
	ll sum =  s[i] - s[j - 1] - (ll)(a[i] - a[j - 1]) * (ll)(j - 1);
	return sum;
}
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a + 1, a + n + 1); 
	for(int i = 1;i <= n;i++){
		s[i] = s[i - 1] + (ll)(a[i] - a[i - 1]) * (ll)(i - 1);
	}
	ll ans = 1;
	for(int i = 1;i <= n;i++){
		ll l = i, r = n, res = 0;
		while(l <= r){
			ll mid = (l + r) >> 1;
			if(gt(i, mid) <= m){
				l = mid + 1;
				res = mid;
			}
			else{
				r = mid - 1;
			}
		}
		ans = max(ans, res - i + 1);
	}
	cout << ans;
	return 0;
} 
