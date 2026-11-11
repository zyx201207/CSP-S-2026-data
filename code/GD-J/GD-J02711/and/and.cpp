#include <iostream>
using namespace std;
using ll = long long;
const ll N = 2e5 + 10, INF = 2147483847;
ll a[N];
ll ans;
ll n, m;

void dfs(ll k, ll cnt, ll l, ll r){
	if(k == m + 1){
		ans = max(ans, cnt);
		return ;
	}
	if(k >= 1e5) exit(1);
	for(ll i = l; i <= r; i++){
		if(k == 1) dfs(k + 1, a[i], i + 1, r + 1);
		else dfs(k + 1, cnt & a[i], i + 1, r + 1);
	}
	return ;
}

int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(ll i = 1; i <= n; i++) cin >> a[i];
	if(m == n){
		ll ans = a[1];
		for(ll i = 2; i <= n; i++) ans &= a[i];
		cout << ans << '\n';
		return 0;
	}
	dfs(1, 0, 1, n - m + 1);
	cout << ans << '\n';
	return 0;
} 
