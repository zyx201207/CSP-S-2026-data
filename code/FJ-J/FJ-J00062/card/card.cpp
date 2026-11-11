#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=500005,M=300005;
ll n,m,a[N],Pre[N],cnt[M],ans[M],cntt[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(ll i=n;i>=1;i--){
		Pre[i]=cnt[a[i]];
		cnt[a[i]]=i;
	}
	for(ll i=n;i>=1;i--) if(Pre[Pre[i]]!=0) Pre[i]=Pre[Pre[i]];
	for(ll i=1;i<=n;i++) if(Pre[i]==0) Pre[i]=i;
	for(ll i=1;i<=n;i++){
		ll x=Pre[i]+1,Add=cntt[i]+1;
		ans[a[i]]+=Add;
		if(x<=n) cntt[x]+=Add;
		/*ll x=i;
		while(x<=n){
			++ans[a[x]];
			x=Pre[x]+1;
		}*/
	}
	for(ll i=1;i<=m;i++) printf("%lld ",ans[i]);
	return 0;
}
