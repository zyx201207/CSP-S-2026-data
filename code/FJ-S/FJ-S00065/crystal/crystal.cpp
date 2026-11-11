#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=500005;
ll n,m,a[N],ans=1,l=1,sum;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for(ll i=2;i<=n;i++){
		ll x=a[i]-a[i-1];
		sum+=x*(i-l);
		while(sum>m){
			sum-=a[i]-a[l];
			++l;
		}
		ans=max(ans,i-l+1);
	}
	printf("%lld",ans);
	return 0;
}
