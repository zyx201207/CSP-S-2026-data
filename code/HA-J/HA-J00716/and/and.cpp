#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10; 
int n,m;
long long a[N],sum[N],ans;
long long dp[N][N];
long long dfs(int x,int y){
	if(dp[x][y]!=-1) return dp[x][y];
	if((!y)||x==n+1) return -1;
	return dp[x][y]=max(dfs(x+1,y-1)&a[x],dfs(x+1,y));
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	memset(dp,-1,sizeof(dp));
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) ans=max(dfs(i,m),ans);
	cout<<ans;
	return 0;
}

