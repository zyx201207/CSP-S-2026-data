#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10,M=2e6+10;
int n,d,x[M],dp[N],pre[M],dis[N],fd[M],sum[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	scanf("%lld%lld",&c,&t);
	if(c==13||c==14){
while(t--){scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++) scanf("%lld",x+i),pre[i]=fd[i]=0;
		int lst=1;
		for(int i=1;i<=n;i++){
			while(x[i]-x[lst]>d) lst++;
			pre[lst]++;
		}
		lst=n;
		for(int i=n;i>=1;i--){
			while(x[lst]-x[i]>d) lst--;
			fd[lst]++;
		}
		int ans=0;
		for(int i=1;i<=n-1;i++) ans+=pre[i]*fd[i+1];
		printf("%lld\n",ans);
	}	
	return 0;}
	while(t--){
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++) scanf("%lld",x+i);
		int lst=1;
		for(int i=1;i<=n;i++){
			while(x[i]-x[lst]>d) lst++;
			pre[i]=lst;
		}
		int ans=0;
		for(int st=1;st<=n;st++){
			for(int i=st-1;i<=n;i++) dp[i]=sum[i]=0;
			int www=st;
			while(pre[www]<=st&&www<=n) dp[www]=dis[www]=1,sum[www]=sum[www-1]+1,www++;
			for(int i=www;i<=n;i++) dis[i]=dis[pre[i]]+1;
			lst=n;
			for(int i=n;i>=st;i--) {
				if(dis[lst]!=dis[i]) lst=i;
				fd[i]=lst;
			} 
			for(int i=www;i<=n;i++) {
				dp[i]=sum[min(i-1,fd[pre[i]])]-sum[pre[i]-1];
				sum[i]=sum[i-1]+dp[i];
			}
			for(int i=st;i<=n;i++) ans+=(dp[i]==2);
		}
		printf("%lld\n",ans);
	}
}
