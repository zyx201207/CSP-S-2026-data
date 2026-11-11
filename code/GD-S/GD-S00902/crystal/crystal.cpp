#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m;
ll a[1000010];
ll tot;
ll ans=0,cz,mx=INT_MIN;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i],mx=max(mx,a[i]);
	ll f1=1,f2=1;
	for(ll i=1;i<=n;i++){
		if(a[i]!=i) f1=0;
	}for(ll i=1;i<n;i++){
		ll cz=a[2]-a[1];
		if(cz!=a[i+1]-a[i]) f2=0;
	}for(ll i=1;i<=n;i++) tot+=mx-a[i];
	if(tot<m){
		cout<<n;
		return 0;
	}if(f1){
		for(ll i=1;i<=n;i++) a[i]=a[i-1]+i;
		for(ll i=1;i<=n;i++){
			if(a[i]>m){
				cout<<i;
				return 0;
			}
		}
	}if(f2){
		ll c=a[2]-a[1];
		m/=c;
		for(ll i=1;i<=n;i++) a[i]=a[i-1]+i;
		for(ll i=1;i<=n;i++){
			if(a[i]>m){
				cout<<i;
				return 0;
			}
		}
	}for(ll i=n;i>=1;i--){
		ll mx=0;
		ll ii=i-1;
		ll h=m;
		while(h){
			if(ii<1) break;
			if(a[i]-a[ii]<=h){
				h-=(a[i]-a[ii]);
				mx++;
				ans=max(ans,mx);
				ii--;
			}else{
				break;
			}
		}
	}cout<<ans+1;
	return 0;
}
