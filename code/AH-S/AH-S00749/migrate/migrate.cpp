#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d;
int x[200020],dp[200020],fa[200020];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--){
		int ans=0;
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++)scanf("%lld",&x[i]);
		for(int i=1;i<n;i++){
			memset(dp,0x3f,sizeof(dp));
			memset(fa,0,sizeof(fa));
			dp[i]=0;
			fa[i]=1;
			for(int j=i+1;j<=n;j++)
				for(int ij=j-1;ij>=i;ij--){
					if(x[j]-x[ij]>d) break;
					int bs=dp[ij]+1;
					if(bs<dp[j]) dp[j]=bs,fa[j]=fa[ij];
					else if(bs==dp[j]) fa[j]+=fa[ij];
				}
			for(int j=i+1;j<=n;j++) if(fa[j]>=2) ans++;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
