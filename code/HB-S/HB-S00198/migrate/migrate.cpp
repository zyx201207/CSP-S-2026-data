#include<bits/stdc++.h>
using namespace std;
#define int long long
int dp[305][305],fs[305][305],a[2000005];
int n,ans,c,t,d;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--){
		ans=0;
		scanf("%lld%lld",&n,&d);
		memset(dp,0x3f,sizeof(dp));
		for(int i=1;i<=n;i++)dp[i][i]=0;
		for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
		memset(fs,0,sizeof(fs));
		for(int i=1;i<n;i++)
			for(int j=i+1;j<=n;j++){
				for(int k=j-1;k>=i&&a[j]-a[k]<=d;k--){
					if(dp[i][j]>dp[i][k]+1)dp[i][j]=dp[i][k]+1,fs[i][j]=0;
					if(dp[i][j]==dp[i][k]+1) fs[i][j]++;
				}
			}
		for(int i=1;i<n;i++)
			for(int j=i+1;j<=n;j++)
				if(fs[i][j]==2){ans++;cout<<i<<" "<<j<<"\n";}
		printf("%lld\n",ans);
	}
	return 0;
}
