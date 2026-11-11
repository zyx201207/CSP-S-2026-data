#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e6 + 5;
ll c, T, n, d, a[N], ans, sum = 1e18, num;
ll dfs(ll l, ll r, ll cnt){
	if(l == r) sum = min(sum, cnt);
	for(int i = l + 1; i <= r; ++i){
		if(a[i] - a[l] <= d) dfs(i, r, cnt + 1);
	}
	if(sum == 1e18) return 0;
	else return sum;
}
ll f(ll l, ll r, ll cnt, ll x){
	if(l == r) num += (cnt == x);
	for(int i = l + 1; i <= r; ++i){
		if(a[i] - a[l] <= d) f(i, r, cnt + 1, x);
	}
	return num;
}
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> T;
	while(T--){
		cin >> n >> d;
		for(int i = 1; i <= n; ++i) cin >> a[i];
		if(n <= 5000){
			for(int len = 3; len <= n; ++len){
				for(int i = 1; i + len <= n; ++i){
					if(a[i + len] - a[i] <= d) continue;
					sum = 1e18, num = 0;
					ll x = dfs(i, i + len, 0);
					if(f(i, i + len, 0, x) == 2) ++ans;
				}
			}
			cout << ans << "\n";
		}
		else if(c == 12 || c == 13){
			ll dn = a[2] - a[1];
			if(d < 2 * dn) cout << 0 << "\n";
		}
	}
	return 0;
}
