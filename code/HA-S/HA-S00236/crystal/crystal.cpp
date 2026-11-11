#include<algorithm>
#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
ll n,m,a[500010],maxn;
ll ans(ll k,ll s){
	ll add=0;
	ll b=a[k];
	for(ll i=k;i>=1;i--){
		if(s>=b-a[i]){
			add++;
			s=s-(b-a[i]);
		}
		else break;
	}
	for(ll i=k+1;i<=n;i++){
		if(a[i]==b){
			add++;
		}
		else break;
	}
	return add;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	ll l=1,r=n;
	while(l<=r){
		ll mid=(l+r)/2;
		ll sum=ans(mid,m);
		if(sum>maxn){
			maxn=sum;
			l=mid+1;
		}
		else r=mid-1;
	}
	printf("%lld",maxn);
	return 0;
}
