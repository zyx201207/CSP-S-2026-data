#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll n,m;
ll a[1000100];

void solve(){
	cin >> n >> m;
	for(ll i = 1;i<=n;i++){
		cin >> a[i];
	}
	if(m == 1){
		ll mx = -1;
		for(ll i = 1;i<=n;i++)mx = max(mx,a[i]);
		cout << mx;
		return ;
	}
	else if(m == n){
		ll ans = a[1];
		for(ll i = 2;i<=n;i++)ans &= a[i];
		cout << ans;
		return ;
	}
	else if(m==2){
		ll mx = -1;
		for(ll i = 1;i<=n;i++){
			for(ll j = i+1;j<=n;j++){
				mx = max(mx,a[i]&a[j]);
			}
		}
		cout << mx;
		return ;
	}
	else{
		cout << a[n];
		return ;
	}
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	solve();
	return 0;
} 
