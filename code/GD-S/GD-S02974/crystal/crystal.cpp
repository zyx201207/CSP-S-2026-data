#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll const maxn=5e5;
ll n,m;
ll a[maxn+1];
ll s[maxn+1];
ll chk(ll l,ll r,ll c){
	return c*(r-l+1)-(s[r]-s[l-1]);
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	ll ans=0;
	for(ll i=1;i<=n;i++){
		ll al=1,ar=i;
		while(al<ar){
			ll mid=(al+ar)>>1;
			if(chk(mid,i,a[i])<=m){
				ar=mid;
			}
			else{
				al=mid+1;
			}
		}
		ans=max(ans,i-al+1);
	}
	cout<<ans;
	
	return 0;
}
