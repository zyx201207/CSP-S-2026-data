#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=5e5+10;
ll a[N],sum[N]; 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	ll n,m;
	ll ans=1;
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(ll i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	for(ll i=1;i<=n;i++){
		if(a[i]==a[i+1]) continue;
		ll l=1,r=i,res=i;
		while(l<=r){
			ll mid=(l+r)>>1;
			if(a[i]*(i-mid+1)-(sum[i]-sum[mid-1])<=m) res=mid,r=mid-1;
			else l=mid+1;
		}
		ans=max(ans,i-res+1);
	}
	cout<<ans<<"\n";
	return 0;
}/*
5 5
1 2 4 8 9
*/
