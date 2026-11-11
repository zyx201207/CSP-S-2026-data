#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500005];
bool check(ll u){
	ll cnt=0;
	for(ll i=1;i<u;i++){
		cnt+=(a[u]-a[i]);
	}
	if(cnt<=m)return true;
	for(ll i=u+1;i<=n;i++){
		cnt-=(a[i-1]-a[i-u]);
		cnt+=(a[i]-a[i-1])*(u-1);
		if(cnt<=m)return true;
	}
	return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	ll l=0,r=n;
	while(l<r){
		ll mid=(l+r+1)/2;
		if(check(mid))l=mid;
		else r=mid-1;
	}
	printf("%lld\n",l);
	return 0;
}