#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+7;
ll n,m,arr[N],b[N],sum[N];
ll qry(ll l,ll r){
	return sum[r]-sum[l-1]-(arr[r]-arr[l-1])*(l-1);
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&arr[i]);
	sort(arr+1,arr+n+1);
	for(int i=1;i<=n;i++)b[i]=arr[i]-arr[i-1];
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+b[i]*(i-1);
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		ll l=i,r=n;
		while(l<r){
			ll mid=(l+r+1)/2;
			if(qry(i,mid)<=m)l=mid;
			else r=mid-1; 
		}
		ans=max(ans,l-i+1);
	}
	printf("%lld",ans);
	return 0;
} 
