#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,maxn;
ll s[500005];
ll qzh[500005];
ll find(ll x){
	ll l=1,r=n,ans=0;
	while(l<=r){
		ll mid=(l+r)>>1;
		if((s[x]*(x-mid+1))-(qzh[x]-qzh[mid-1])<=m){
			r=mid-1;
			ans=mid;
		}else{
			l=mid+1;
		}
	}
	return x-ans+1;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=n;i++){
		scanf("%lld",&s[i]);
	}
	sort(s+1,s+n+1);
	for(ll i=1;i<=n;i++){
		qzh[i]=qzh[i-1]+s[i];
	}
	for(ll i=1;i<=n;i++){
		maxn=max(maxn,find(i));
	}
	printf("%lld",maxn);
	return 0;
}
