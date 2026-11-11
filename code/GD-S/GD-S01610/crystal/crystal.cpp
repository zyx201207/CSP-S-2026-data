#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m,a[500005],b[500005],mx=1;
bool check(ll x,ll i){
	return a[i]*(i-x)-b[i-1]+b[x-1]<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++) b[i]=a[i]+b[i-1];
	for(ll i=1;i<=n;i++){
		ll l=1,r=i,ans=-1e18;
		while(l<=r){
			ll mid=(l+r)/2;
			if(check(mid,i)){
				r=mid-1;
				ans=mid;
			}else{
				l=mid+1;
			}
		}
		mx=max(mx,i-ans+1);
	}
	cout<<mx;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
