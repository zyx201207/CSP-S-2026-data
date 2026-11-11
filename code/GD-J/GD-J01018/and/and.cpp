#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll n,m;
ll a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(ll i = 1;i<=n;i++){
	    cin >> a[i];
	}
	if(n==m){
		ll sum = a[1];
		for(ll i = 2;i<=n;i++){
			sum = sum&a[i];
		}cout << sum;
	}
	else if(n<=2000&&m==2){
		ll mx = 0;
			for(ll i = 1;i<=n;i++){
				for(ll j = 1;j<=n;j++){
					ll s = a[i]&a[j];
					if(i!=j&&s>mx)mx=s;
				}
			}
			cout << mx;
	}
	else if(n<=2000&&m==1){
		ll mx = 0;
			for(ll i = 1;i<=n;i++){
				ll s = a[i]&a[i];
				if(s>mx)mx=s;
			}
			cout << mx;
	}
	else if(n<=20){
		
	}else if(n<=200000){
		
	}
	return 0;
}
