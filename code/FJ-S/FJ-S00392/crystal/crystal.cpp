#include <bits/stdc++.h>
using namespace std;
#define rt return
typedef long long ll;
const int N=500100;
ll n,m,a[N],s[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	ll ans=1;
	for(ll i=1;i<=n;i++){
		ll l=i,r=n,res=i;
		for(;l<=r;){
			ll M=(l+r)/2;
			if((M-i+1)*a[M]-(s[M]-s[i-1])<=m) l=M+1,res=M;
			else r=M-1;
		}ans=max(ans,res-i+1);
	}printf("%lld\n",ans);
	rt 0;
}
