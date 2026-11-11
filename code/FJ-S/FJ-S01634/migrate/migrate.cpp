#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
using ll=long long;
ll meiyong[2000005];
ll a[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	scanf("%d%d",&c,&T); 
	while(T--){
		ll n,d;
		ll ans=0;
		int f=1;
		scanf("%lld%lld",&n,&d);
		a[0]=0;
		meiyong[0]=0;
		for(ll i=1;i<=n;++i){
			scanf("%lld",&meiyong[i]);
			a[i]=a[i-1]+meiyong[i]-meiyong[i-1];
		}
		for(ll i=1;i<=n;++i){
			if(a[i]+d>=a[n])break;
			ll o_1=upper_bound(a+1,a+1+n,a[i]+d)-a-1;
			o_1--;
			ll o_2=upper_bound(a+1,a+1+n,a[o_1]+d)-a-1;
			if(a[o_1-1]+d>=a[o_2])continue;
			//printf("*%lld %lld %lld \n",i,o_1,o_2);
			++ans;
		}
		printf("%lld\n",ans);
	}
	return 0;
} 
