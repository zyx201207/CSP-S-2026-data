#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
ll n,m,a[500010];
bool vis[500010];
ll c(ll x,ll xx){
	ll qq = 0;
	for (ll i = 1;i <= n;i++){
		if (a[i] == x && i != xx && vis[i] == false){
			return i;
		}
	}return -1;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> n >> m;
	for (ll i = 1;i <= n;i++){
		cin >> a[i];
	}a[1] += 1;
	ll cs = 1;
	for(ll i = 1;i <= n && cs <= m;i++){
		if (vis[i] == false && vis[i + 1] == false){
			cs++;
			a[i] += 1;
			vis[i] = true;
			ll s = a[i],ss = i;
			while (c(s,ss) != -1){
				ll o = c(s,ss);
				vis[ss] = true;
				vis[o] = true;
				a[o] *= 2;
				s = a[o];
				ss = o;
			}
		}
	}ll ans = 0;
	for (ll i = 1;i <= n;i++){
		if (vis[i] == true){
			ans++;
		}
	}cout << ans;
	
	return 0;
}
