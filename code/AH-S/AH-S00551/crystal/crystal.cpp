#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=5e5+5;
LL n,m;
LL a[N],sum[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	sum[0]=0;
	for(LL i=1;i<=n;i++){
		scanf("%lld",a+i);
	}
	sort(a+1,a+n+1);
	for(LL i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	LL pos=1,ans=1;
	for(LL i=2;i<=n;i++){
		while((pos<i)&&((i-pos)*a[i]-(sum[i-1]-sum[pos-1])>m)){
			pos++;
		}
		ans=max(ans,i-pos+1);
	}
	printf("%lld\n",ans);
	return 0;
}
