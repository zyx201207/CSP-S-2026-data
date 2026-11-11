#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[2000005],dp[2000005],ans=0;
int c1(int l,int r){
	int k = 0;
	int cut = 0;
	for(int i=l+1;i<r;i++){
		//printf("%d",k+x[i]-x[i-1]);
		if(k+x[i]-x[i-1]>=d){
			
			k=x[i]-x[i-1];
			cut++;
		}
		else {
			k+=x[i]-x[i-1];
		}
	}
	return cut;
}
void dfs(int l,int r){
	int mi = c1(l,r);
	for(int i=l;i<r;i++) dp[i]=0x3f3f3f3f;
	dp[l]=0;
	int sum = 0;
	for(int i=l+1;i<r;i++){
		for(int j=l;j<=i;j++){
			if(x[i]-x[j]<=d){
				//printf("%d\n",dp[j]+1);
				if(dp[j]+1==mi&&i==r-1) {
					sum++;
					//printf("%d%d\n",dp[j]+1,sum);
				}
				dp[i]=min(dp[j]+1,dp[i]);
			}
		}
	}
	//printf("%d\n",sum);
	if(sum>=2){
		ans++;
		//for(int i=l;i<r;i++) printf("%d\n",dp[i]);
		//printf("%d%d%d\n",l,r,sum);
	}
	//printf("-1");
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--){
		scanf("%lld%lld",&n,&d);
		for(int i=0;i<n;i++) scanf("%lld",&x[i]);
		for(int r=1;r<=n;r++){
			for(int l = 0;l<r;l++){
				dfs(l,r);
			}
		}
		printf("%lld",ans);
	}
	//printf("%d",c1(0,5));
	return 0;
} 
