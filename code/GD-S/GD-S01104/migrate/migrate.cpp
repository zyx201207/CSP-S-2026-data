#include<iostream>
#include<stdio.h>
#define LL long long
using namespace std;

int c,t,n;
unsigned LL d;
LL x[2000004];
LL dp[5004][5004];
LL cnt[5004][5004];
void dfs(LL start,LL k,LL cost,LL end){
	if(cost>dp[start][end]||k>end)return;
	if(k==end&&cost<=dp[start][end]){
		if(cost<dp[start][end]){
			dp[start][end]=cost;
			cnt[start][end]=1;
		}else{
			cnt[start][end]++;
		}
		return;
	}
	for(int i=k+1;i<=end;i++){
		if(x[i]-x[k]<=d)dfs(start,i,cost+1,end);
	}
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%d%d",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",&x[i]);
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dp[i][j]=1e18;
				cnt[i][j]=0;
			}
		} 
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				dfs(i,i,0,j);
				if(cnt[i][j]==2){
//					cout<<i<<' '<<j<<'\n';
					ans++;
				}
			}
		}
		printf("%d\n",ans);
		
	}

	return 0;
}
