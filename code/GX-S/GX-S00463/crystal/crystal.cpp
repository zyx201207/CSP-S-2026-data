#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
ll a[500005];
ll sum[500005];
bool cmp(ll aa,ll bb){
	return aa<bb;
}
bool check(ll x){
	for(int i=x;i<=n;i++){
		ll mx=a[i];
		ll cnt=mx*x-(sum[i]-sum[i-x]);
		if(cnt<=m) return 1;
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	ll l=1,r=n,mid,ans;
	while(l<=r){
		mid=(l+r)/2;
		if(check(mid)){
			l=mid+1;
			ans=mid;
		}
		else{
			r=mid-1;
		}
	}
	printf("%lld",ans);
	
	


	return 0;
}
