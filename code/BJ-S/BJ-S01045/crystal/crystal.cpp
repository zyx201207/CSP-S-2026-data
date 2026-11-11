#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m;
ll a[500010];
ll sum[500010];
ll ans;
bool check(ll x,ll e){
	if((e-x)*a[e]-(sum[e-1]-sum[x-1])<=m)return true;
	else return false;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++)
		sum[i]=sum[i-1]+a[i];
	for(ll i=1;i<=n;i++){
		ll l=1,r=i;
		while(l<r){
			ll mid=(l+r)>>1;
			if(check(mid,i))r=mid;
			else l=mid+1;
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	
    return 0;
}
