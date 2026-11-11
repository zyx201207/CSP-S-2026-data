#include <bits/stdc++.h>
#define ll long long
using namespace std;
int c,t;
int n,k;
int x,y;
int vis[25];
int dp[25][25];
int minn=2e9;
vector<int> s[25];
void dfs(int x,int sum){
	if(x>n || sum==k){
		if(sum!=k) return;
		int ans=0,minn2=2e9;
		for(int i=1;i<=n;i++){
			if(vis[i]==0){
				for(auto j:s[i]){
					if(vis[j]==1 && i>j){
						ans++;
					}
				}
			}
		}
		if(ans>2) return;
		for(int i=1;i<=n;i++){
			if(vis[i]==0){
				for(int j=1;j<=n;j++){
					if(vis[j]==1) minn2=min(minn2,dp[i][j]);
				}
			}
		}
		minn=min(minn,minn2);
		return;
	}
	vis[x]=1;
	dfs(x+1,sum+1);
	vis[x]=0;
	dfs(x+1,sum);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		minn=2e9;
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dp[i][j]=1e9;
			}
			s[i].clear();
			dp[i][i]=0;
		}
		for(int i=1;i<n;i++){
			scanf("%d%d",&x,&y);
			s[x].push_back(y);
			s[y].push_back(x);
			dp[x][y]=dp[y][x]=1;
		}
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
				}
			}
		}
		dfs(1,0);
		printf("%d\n",minn);
	}
	return 0;
}
