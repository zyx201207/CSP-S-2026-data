#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m;
ll a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	ll sum=0,l=1,ans=0;
	for(ll i=1;i<=n;i++){
		sum+=a[i];
		while((i-l+1)*a[i]-sum>m){
			sum-=a[l++];
		}
		ans=max(ans,i-l+1);
	}
	printf("%lld",ans);
	return 0;
}
