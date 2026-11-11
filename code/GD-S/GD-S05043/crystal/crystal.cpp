#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 500005;
ll n, m, ans, a[N], sum[N];
ll find(ll i){
	ll l = i, r = n, anss = 0;
	while(l <= r){
		ll mid = (l + r) / 2;
		if(a[mid] * (mid - i + 1) - (sum[mid] - sum[i - 1]) <= m){
			anss = mid;
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	return anss;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(ll i = 1;i <= n;++i)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	for(ll i = 1;i <= n;++i)
		sum[i] = sum[i - 1] + a[i];
	for(ll i = 1;i <= n;++i){
		ll j = find(i);
		ans = max(j - i + 1, ans);
	}
	cout << ans;
	return 0;
}
