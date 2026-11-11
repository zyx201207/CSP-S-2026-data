#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define FILE(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout);
int main(){
	FILE("crystal")
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	ll n,m;
	cin>>n>>m;
	ll a[n];
	for(ll& i:a)cin>>i;
	sort(a,a+n);
	ll sum[n]{},ans=1;
	for(ll i=1;i<n;i++)sum[i]=sum[i-1]+(a[i]-a[i-1])*i;
	for(ll i=0;i<n;i++){
		if(sum[i]<=m){
			ans=max(ans,i+1);
			continue;
		}
		ll l=0,r=i-1;
		while(l<r){
			ll mid=(l+r)/2;
			if(sum[i]-sum[mid]-(mid+1)*(a[i]-a[mid])>m)l=mid+1;
			else r=mid;
		}ans=max(ans,i-l);
	}cout<<ans;
}
