#include<bits/stdc++.h>
using namespace std;
const int N=1e3+100;
int x[N],sum[N],dp[N][N];
int vis[N][N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	scanf("%d%d",&c,&T);
	while(T--){
		memset(dp,0x3f,sizeof dp);
		memset(vis,0,sizeof vis);
		int n,d;
		scanf("%d%d",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%d",&sum[i]);
			sum[i]-=sum[1];
		}
		sum[1]=0;
		for(int d=1;d<n;d++){
			for(int i=1;i<=n;i++){
				dp[i][i]=0;
				if(sum[i+d]-sum[i-1]<=d){//如果能直接连过去那么最小值就是1 
					dp[i][i+d]=1;
					continue;
				}
				for(int j=1;j<=d;j++){
					int l=i,r=i+d;
					if(dp[l][r]==dp[l][j+i-1]+sum[j+i]-sum[j+i-1]+dp[j+i][r]){
						vis[l][r]++;
					}else if(dp[l][r]<dp[l][j+i-1]){
						vis[l][r]=1;
						dp[l][r]=dp[l][j+i-1]+sum[j+i]-sum[j+i-1]+dp[j+i][r];
					}
				}
			}
		}
		int res=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(vis[i][j]>=2)res++;
			}
		}
		printf("%d\n",res);
	}
	return 0;
}
