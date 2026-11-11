#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m;
ll a[600000];
ll ans[600000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(ll i=1;i<=n;i++){
		cin >> a[i];
	}
	ll c[600000];
	for(ll i=1;i<=n;i++){
		for(ll j=i;j<=n;j++){
			c[j]=0;
		}
		for(ll j=i;j<=n;j++){
			c[a[j]]++;
			
		}
		ll b;
		for(ll j=n;j>=i;j--){
			if(c[a[j]]>1){
				b=j;
				break;
			}
		}
		for(ll j=b;j<=n;j++){
			ans[a[j]]++;
			
		}
	}
	for(ll j=1;j<=n;j++){
		cout << ans[j]<<" ";
			
	}
	return 0;
}


