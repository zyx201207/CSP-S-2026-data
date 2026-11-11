#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 2e5 + 5;
ll n, m, a[N], ans;
bool checkA(){
	for(ll i = 1; i <= n; i++){
		ll x = a[i];
		while(x){
			if(!(x % 2)) return false;
			else x /= 2;
		}
	}
	return true;
}
bool checkB(){
	ll x = n;
	while(x > 1){
		if(x % 2) return false;
		else x /= 2;
	}
	for(ll i = 1; i <= n; i++){
		if(a[i] != (i - 1)) return false;
	}
	return true;
}
void dfs(ll k, ll cnt, ll sum){
	if(cnt == m && k == n){
		ans = max(ans, sum);
		return;
	}
	if(k == n){
		return;
	}
	if(cnt == 0) dfs(k + 1, cnt + 1, a[k]);
	else dfs(k + 1, cnt + 1, sum & a[k]);
	dfs(k + 1, cnt, sum);
}
int main(){
//	/*
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
//	*/
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	cin >> n >> m;
	for(ll i = 1; i <= n; i++) cin >> a[i];
	if(m == 1){
		for(ll i = 1; i <= n; i++){
			ans = max(ans, a[i]);
		}
		cout << ans;
	}else if(m == n){
		ans = a[1];
		for(ll i = 2; i <= n; i++){
			ans &= a[i];
		}
		cout << ans;
	}else if(m == 2){
		for(ll i = 1; i <= n; i++){
			for(ll j = 1; j <= n; j++){
				if(i != j){
					ans = max(ans, a[i] & a[j]);
				}
			}
		}
		cout << ans;
	}else if(checkA()){
		sort(a + 1, a + n + 1);
		cout << a[m];
	}else if(checkB()){
		ans = a[n];
		for(ll i = n - 1; i >= n - m + 1; i--){
			ans &= a[i];
		}
		cout << ans;
	}else{
		dfs(1, 0, 0);
		cout << ans;
	}
	return 0;
}
//¹À·Ö£º40·Ö 
