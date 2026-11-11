#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define endl '\n'
const int maxn = 2e5 + 5;
ll n , m;
ll a[maxn];
ll res,ma;
bool vis[21];
void dfs(ll now , ll used){
	if (used == m) {
		res = max(res,now);
		return;
	}
	
	for(ll i = 1; i <= n; i++){
		if (!vis[i]){
			vis[i] = true;
			dfs((now & a[i]) , used + 1);
			vis[i] = false;
		}
	}
	
	return;
}
void solve(){
	cin >> n >> m;
	for (ll i = 1; i <= n; i++){
		cin >> a[i];
		ma = max(ma , a[i]);
	}
	
	if (n <= 20){
		for (ll i = 1; i <= n; i++){
			dfs(a[i] , 0);
		}
		cout << res << endl;
	}else if (m == 1){
		cout << ma << endl;
	}else if (m == n){
		ll ad = a[1];
		for (ll i = 2; i <= n; i++){
			ad = (ad & a[i]);
		}
		cout << ad << endl;
	}else if (m == 2){
		for (ll i = 1; i <= n; i++){
			for (ll j = 1; j <= n; j++){
				if (i != j){
					res = max(res , (a[i] & a[j]));
				}
			}
		}
		cout << res << endl;
	}else if (m == n - 1){
		ll mn = (1 << 20) + 1 , mnw = 0;
		for (ll i = 1; i <= n; i++){
			if (a[i] < mn){
				mn = a[i];
				mnw = i;
			}
		}
		if (mnw == 1) res = a[2];
		else res = a[1];
		for (ll i = 1; i <= n; i++){
			if (i != mnw){
				res = (res & a[i]);
			}
		}
		cout << res << endl;
	}else {
		cout << 0 << endl;
	}
	return;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
	return 0;
}

