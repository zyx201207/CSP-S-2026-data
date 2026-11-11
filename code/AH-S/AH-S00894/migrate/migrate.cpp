#include<bits/stdc++.h>
#define int long long
using namespace std;
const int oo=0x7FFFFFFFFFFFll;
const int N=5005;
int x[N],dp[N][N],num[N][N];
void BF(int t){
	while(t--){
		int n,d;
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++)scanf("%lld",x+i);
		for(int i=0;i<=n;i++)for(int j=0;j<=n;j++)dp[i][j]=oo,num[i][j]=0;
		for(int i=1;i<=n;i++)dp[i][i]=0,num[i][i]=1;
		int ans=0;
		for(int i=2;i<=n;i++){
			for(int j=i-1;j>=1;j--){
				if(x[i]-x[j]>d)break;
				for(int k=1;k<=j;k++){
					if(dp[j][k]+1<dp[i][k])dp[i][k]=dp[j][k]+1,num[i][k]=num[j][k];
					else if(dp[j][k]+1==dp[i][k])num[i][k]+=num[j][k];
				}
			}
			for(int j=1;j<i;j++)ans+=(num[i][j]==2);
		}
		printf("%lld\n",ans);
	}
	return;	
}
void BF_B(int t){
	while(t--){
		int n,d,spot=0,ans=0;
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++)scanf("%lld",x+i);
		for(int i=1;i<=n;i++)if(x[i]-x[1]<=d&&x[n]-x[i]<=d){spot=i;break;}
		for(int i=max(spot-2,1ll);i<=min(spot+2,n);i++){
			for(int j=i+1;j<=min(spot+2,n);j++){
				if(x[j]-x[i]<=d)continue;
				int cnt=0;
				for(int k=i+1;k<j;k++)cnt+=(x[k]-x[i]<=d&&x[j]-x[k]<=d);
				ans+=(cnt==2);
			}
		}
		printf("%lld\n",ans);
	}
	return;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	scanf("%lld%lld",&c,&t);
	if(c>=13&&c<=14)BF_B(t);
	else BF(t);
	return 0;
}
