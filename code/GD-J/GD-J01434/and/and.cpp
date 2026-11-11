#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll n, m, a[200005], ans = 0;
void dfs(ll pos, ll sum, ll t){
	if(t == m){
		ans = max(ans, sum);
		return;
	}
	if(pos == n + 1) return;
	dfs(pos + 1, sum, t);
	dfs(pos + 1, (sum & a[pos]), t + 1);
}
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(ll i = 1; i <= n; ++i) cin >> a[i];
	if(m == 1){
		for(int i = 1; i <= n; ++i) ans = max(ans, a[i]);
		cout << ans << endl;
		return 0;
	}
	if(m == n){
		for(int i = 1; i <= n; ++i) ans = ans & a[i];
		cout << ans << endl;
		return 0;
	}
	if(m == 2){
		for(int i = 1; i <= n; ++i){
			for(int j = i + 1; j <= n; ++j){
				ans = max(ans, a[i] & a[j]);
			}
		}
		cout << ans << endl;
		return 0;
	}

	for(ll i = 1; i <= n - m + 1; ++i){
		dfs(i + 1, a[i], 1);
	}
	cout << ans << endl;
	return 0;
}
