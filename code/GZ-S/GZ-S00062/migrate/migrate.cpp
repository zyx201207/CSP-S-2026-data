//GZ-S00062 ∏∂Í¿‘Û 
#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define vec vector
#define str string
#define fi first
#define se second
using namespace std;

const ll N = 2e6 + 5;

ll x[N], dp[N];

void Solve() {
	ll n, d;
	cin >> n >> d;
	fill(x + 1, x + n + 1, 0);
	for(ll i = 1;i <= n;i++)
	    cin >> x[i];
	    
	fill(dp + 1 , dp + n + 1, 1);
	for(ll i = 1;i <= n;i++) {
		ll j = i + 1;
		while(x[j] - x[i] <= d && j <= n)
		    dp[j] *= (j - i + 1), j++;
	}
	
	ll ans = 0;
	for(ll i = 1;i <= n;i++)
	    ans += (dp[i] == 2);
	ll res = ans;
	for(ll i = 2;i <= n;i++) {
		ll j = i;
		while(x[j] - x[i-1] <= d && j <= n) {
			bool is = (dp[j] == 2);
		    dp[j] /= (j - i + 1), j++;
		    if(is && dp[j] != 2) ans--;
		    if(!is && dp[j] == 2) ans++;
		}
		res += ans; 
	}
	cout << res << endl;
	return ;
} 

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	ll c, t;
	cin >> c >> t;
	while(t--) Solve(); 
	
	return 0;
}
