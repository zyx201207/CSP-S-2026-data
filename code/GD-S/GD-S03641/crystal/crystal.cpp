#include<bits/stdc++.h>
#define N 500009
#define ll long long
using namespace std;
ll a[N],n,m;
ll check(ll len){
	ll sum=0; 
	for(ll i=1;i<=n;i++){
		sum+=a[i];
		if(i-len>0)sum-=a[i-len];
		if(i>=len){
			ll val=len*a[i]-sum;
			if(val<=m)return 1;	
		}
	}
	return 0;	
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
//	freopen("crystal3.in","r",stdin);
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	ll l=1,r=n,ans=0;
	while(l<=r){
		ll mid=(l+r)/2ll;
		if(check(mid))ans=mid,l=mid+1;
		else r=mid-1;
	}
	cout<<ans; 
	return 0;
}
