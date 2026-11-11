#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll m,n,a[2000202];
ll maxn=-1e18;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++){
		ll ans=a[i];
		for(ll j=i;j<=i+m-1;j++){
			ans=ll(ans&a[j]);
		}
		maxn=max(maxn,ans);
	}
	cout<<maxn;
	return 0;
}
