#include<bits/stdc++.h>
using namespace std;
int c,t,n,d;
//void dfs(int st,int ed,int l){
//	if(ed>n) return;
//	for(int i=1;i<=xb;i++){
//		
//	}
//	for(int i=1;i<=d;i++){
//		dfs(st,st+i,l+1);
//	}
//}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%d%d",&n,&d);
		bool dch=1;
		
//		memset(dp,0x3f3f,sizeof(b));
		int x[n+1]={0},M,dp[n+1][n+1]={},b[n+1][n+1]={},cnt=0;
		memset(dp,0x3f3f,sizeof(dp));
		int fr[n+1]={0};
		for(int i=1;i<=n;i++){//终点 
			scanf("%d",&x[i]);
			fr[i]=x[i]-x[i-1];
			if(i>=3 && fr[i]!=fr[i-1]) dch=0;
			for(int j=i-1;j>=1;j--){//起点 
				if(abs(x[i]-x[j])<=d){
					dp[j][i]=1;
				}else{
					for(int k=1;k<=d;k++){
						int dis=max(0,i-k);
						if(dp[j][dis]!=0x3f3f && dp[dis][i]!=0x3f3f){
//							printf("从%d到%d最少走%d步 = %d ~ %d的%d步 + %d ~ %d的%d步\n",j,i,dp[j][i],j,dis,dp[j][dis],dis,i,dp[dis][i]);
							if(dp[j][i]>dp[j][dis]+dp[dis][i]){
								dp[j][i]=dp[j][dis]+dp[dis][i];
								b[j][i]=1;
							}else if(dp[j][i]==dp[j][dis]+dp[dis][i]){
								b[j][i]++;
							}
						}
					}
				}
			}
			
		}
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
//				if(dp[i][j]!=0x3f3f){
//					printf("从%d到%d最少走%d步,共有%d种方案\n",i,j,dp[i][j],b[i][j]);
//				}
				if(b[i][j]==2) cnt++;
			}
		}printf("%d\n",cnt);
		if(dch && d<2*fr[2]){
			printf("0\n");
		}

	}
	return 0;
}

