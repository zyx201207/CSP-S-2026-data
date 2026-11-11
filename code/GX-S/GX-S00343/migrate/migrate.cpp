#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>
using namespace std;
int arr[5140],n,d;
int cnt[5140][5140],dp[5140][5140];	// dp[i][j] : the shortest distance between i,j  cnt[i][j] : the number of shortest panths
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	scanf("%d%d",&c,&t);
	while(t--){int ans=0;
		memset(dp,0x3f,sizeof(dp));
		scanf("%d%d",&n,&d);
		for(int i=1;i<=n;i++){
			dp[i][i]=0;
			scanf("%d",arr+i);
			if(arr[i]<=arr[i-1]+d)dp[i-1][i]=1;
		}
		for(int i=2;i<=n;i++){
			for(int j=i-1;j>0;j--){
				if(arr[j]+d>=arr[i]){dp[j][i]=1;continue;}
				for(int k=j+1;k<i;k++){
					int dis=dp[j][k]+dp[k][i];
					if(dis<dp[j][i]){
						cnt[j][i]=1;dp[j][i]=dis;
					}else if(dis==dp[j][i])cnt[j][i]++;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans+=(cnt[i][j]==2);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
