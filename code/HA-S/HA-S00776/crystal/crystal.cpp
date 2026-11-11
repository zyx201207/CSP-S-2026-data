#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 5 * 1e5 + 5;
int n;
ll m;
ll a[N];
ll sum[N];

inline bool check(ll x){
	for(ll i = x;i <= n;i ++){
		ll cnt = sum[i - 1] - sum[i - x];
		ll ned = 1ll * a[i] * (x - 1);
		ll res = ned - cnt;
		if(res <= m) return true;
	}
	return false;
}

inline void solve(){
	cin >> n >> m;
	for(int i = 1;i <= n;i ++){
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for(int i = 1;i <= n;i ++){
		sum[i] = sum[i - 1] + a[i];
	}
	ll ans = 0;
	ll l = 1, r = n;
	while(l <= r){
		ll mid = (l + r) >> 1;
		if(check(mid)){
			ans = mid;
			l = mid + 1;
		}
		else{
			r = mid - 1;
		}
	}
	cout << ans << '\n';
}

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin.tie(0) -> ios::sync_with_stdio(0);
	int T = 1;
	while(T --)	solve();
	return 0;
}
