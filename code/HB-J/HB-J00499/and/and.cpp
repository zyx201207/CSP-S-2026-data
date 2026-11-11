#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m;
ll a[300000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >>n >> m;
	
	for(ll i=1;i<=n;i++){
		cin >> a[i];
	}
	ll ans;
	if(n==m){
		ans=a[1];
		for(ll i=2;i<=n;i++){
			ans=(ans & a[i]);
		}
		cout << ans;
		return 0;
	}
	if(m==1){
		ans = -1e17;
		for(ll i=1;i<=n;i++){
			ans=max(ans , a[i]);
		}
		cout << ans;
		return 0;
	}
	if(m==2){
		ans = -1e17;
		for(ll i=1;i<=n;i++){
			for(ll j=i+1;j<=n;j++){
				ans=max(ans , (a[i] & a[j]) );
			}
		}
		cout << ans;
		return 0;
	}
	
	return 0;
}


