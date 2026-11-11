#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 500005;
ll a[N];
ll s[N];
ll sum[N];

int main(){
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w" , stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n , m;
	cin >> n >> m;
	for (ll i = 1 ; i <= n ; ++ i){
		cin >> a[i];
	}
	sort (a + 1 , a + n + 1);
	ll tsum = 0;
	for (int i = 1 ; i <= n ; ++ i){
		tsum += a[i];
		sum[i] = tsum;
	}
	ll ans = 0;
	for (ll i = 2 ; i <= n ; ++ i){
		if (i > n) break;
		ll tmp = m , tmp_ans = 0;
		for (int j = 1 ; j <= i ; ++ j){
			ll tt = a[i] * j - sum[j];
			if (tt <= tmp) ++ tmp_ans;
			else{
				break;
			}
		}
		ans = max(tmp_ans , ans);
	}
	cout << ans << endl;
	return 0;
}
