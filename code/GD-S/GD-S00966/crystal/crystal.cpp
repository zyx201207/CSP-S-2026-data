#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N = 5e5 + 10;
ll n, m, a[N], cnt;
bool check(ll k){
	ll sum = 0;
	for(ll i = 1;i <= n;i++){
		if(a[i] < k)sum += k - a[i];
	}
	return sum <= m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(ll i = 1;i <= n;i++)cin >> a[i];
	sort(a + 1,a + n + 1);
	ll l = 0, r = 1e18, ans = 0;
	while(l <= r){
		ll mid = (l + r) / 2;
		if(check(mid)){
			l = mid + 1;
			ans = mid;
		}
		else r = mid - 1;
		//cout << l << " " << r << " " << ans << "\n";
	}
	for(ll i = 1;i <= n;i++){
		if(a[i] <= ans)cnt++;
	}
	cout << cnt;
	return 0;
}
