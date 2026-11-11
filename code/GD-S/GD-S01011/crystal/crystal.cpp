#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m;
ll a[500010];
bool isa(){
	for(ll i=1;i<=n;i++){
		if(a[i]!=i)return false;
	}
	return 1;
}
bool isb(){
	ll pos=a[2]-a[1];
	for(ll i=3;i<=n;i++){
		if(a[i]-a[i-1]!=pos)return false;
	}
	return 1;
}
bool isc(){
	ll cc=0;
	for(ll i=2;i<=n;i++){
		cc+=abs(a[i]-a[1]);
	}
	return cc<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	ll mm=m;
	for(ll i=1;i<=n;i++)cin>>a[i];
	if(isa()){
		ll ans=1;
		for(ll i=1;i<=n/2;i++){
			if(mm-i<0)break;
			mm-=i;
			ans++;
			if(mm-i<0)break;
			mm-=i;
			ans++;
		}
		cout<<ans;
	}
	else if(isb()){
		mm=m;
		ll pos=abs(a[2]-a[1]);
		ll ans=1;
		for(ll i=1;i<=n/2;i++){
			if(mm-pos*i<0)break;
			mm-=pos*i;
			ans++;
			if(mm-pos*i<0)break;
			mm-=pos*i;
			ans++;
		}
		cout<<ans;
	}
	else if(isc()){
		cout<<n;
	}
	else{
		sort(a+1,a+n+1);
		ll mx=0,sum=0;
		for(ll i=1;i<=n;i++){
			sum=0;
			for(ll j=1;j<=n;j++){
				if(i==j)continue;
				if(i<=n/2){
					if(sum+(abs(a[i]-a[j]))>mm){
						mx=max(mx,j-1);
						break;
					}
					if(sum==mm)break;
					else sum+=abs(a[i]-a[j]);
				}
				else{
					if(sum+(abs(a[i]-a[n-j]))>mm){
						mx=max(mx,j-1);
						break;
					}
					if(sum==mm)break;
					else sum+=abs(a[i]-a[n-j]);
				}
			}
		}
		cout<<mx;
	}
	return 0;
}
