#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N=2e6+7;
int c,t,n,d,res,a[N];
int cnt[N],mosl[N],dis[N],mosr[N],pre[N];
void solve(){
	scanf("%lld%lld",&n,&d);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++){
		mosl[i]=lower_bound(a+1,a+1+i,a[i]-d)-a;
	}
	res=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++) mosr[j]=-1,dis[j]=0,pre[j]=0,mosl[j]=max(mosl[j],i);
		dis[i]=0;
		pre[i-1]=0;
		cnt[i]=1;
		pre[i]=1;
		mosr[0]=i;
		for(int j=i+1;j<=n;j++){
			int tar=dis[mosl[j]]+1;
			int rat=mosr[tar-1];
			dis[j]=tar;
			cnt[j]=pre[rat]-pre[mosl[j]-1];
			pre[j]=pre[j-1]+cnt[j];
			mosr[dis[j]]=j;
			if(cnt[j]==2) res++;
		}
	}
	printf("%lld\n",res);

}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--) solve();
	return 0;
}

