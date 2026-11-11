//GZ-J00026 贵阳市白云区华师一学校 杨泊静 
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ll n,m;
	scanf("%lld%lld",&n,&m);
	ll f[m+1] = {0};
	for(ll i = 1; i <= n; i++) scanf("%lld",&a[i]);
	if(m == 1){
		ll maxn = -1;
		for(ll i = 1; i <= n; i++){
			if(a[i] >= maxn)
				maxn = a[i];
		}
		cout << maxn;
		return 0;
	}
	else if(m == n){
		ll ans = 1;
		for(ll i = 1; i <= n; i++){
			if(i == 1) ans = a[1];
			else ans = ans&a[i];
		}
		cout << ans;
		return 0;
	}
	else if(m == 2){
		ll ans[400005] = {0},k = 1,maxn = -1;
		for(ll i = 1; i <= n; i++){
			for(ll j = i+1; j <= n; j++){
				ans[k] = a[i]&a[j];
				k++;
			}
		}
		for(ll i = 1; i <= 400005; i++){
			if(ans[i] >= maxn) maxn = ans[i];
		}
		cout << maxn;
		return 0;
	}
	for(ll i = 1; i <= m; i++){
		for(ll j = 1; j <= n; j++){
			if(a[j] >= f[i]) f[i] = a[j];
		}
		for(ll j = 1; j <= n; j++){
			if(f[i] == a[j]) a[j] = -1;
		}
	}
	ll ans;
	for(ll i = 1; i <= m; i++){
		if(i == 1) ans = f[1];
		else ans = ans&f[i];
 	}
 	cout << ans;
	return 0;
}
