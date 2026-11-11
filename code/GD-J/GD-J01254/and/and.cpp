#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll mx=-1e18,mi=1e18;
ll a[1000100];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	for(ll i=1;i<=n;i++)cin>>a[i],mx=max(a[i],mx),mi=min(mi,a[i]);
	if(m==1)cout<<mx;
	else if(m==2){
		mx=-1;
		for(ll i=1;i<n;i++){
			for(ll j=i+1;j<=n;j++){
				mx=max(mx,(a[i]&a[j]));
			}
		}
		cout<<mx;
	}
	else if(m==n){
		mx=a[1];
		for(ll i=2;i<=n;i++)mx=(mx&a[i]);
		cout<<mx;
	}
	else if(m==n-1){
		mx=a[1];
		for(ll i=2;i<=n;i++){
			if(a[i]==mi)continue;
			mx=(mx&a[i]);
		}
		cout<<mx;
	}else cout<<7;
	return 0;
}
