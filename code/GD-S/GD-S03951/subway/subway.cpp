#include<bits/stdc++.h>
using namespace std;
const int N=505;
int dp[N][N],c,m,w[N],n,t[N][N],d,q,k[N],a,x,y,vis[N][N],cost,b,ans=1e8;
void dfs(int x,int cost){
	if(x==y){
		ans=min(cost,ans);
		return;
	}
	for(int i=1;i<=m;i++){
		if(dp[x][i]==1&&vis[i][x]!=1){
			vis[x][i]=1;
			dfs(i,cost+t[x][i]+t[i][x]);
			vis[x][i]=0;
		}
	}return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a;
			dp[i][a]=1;
			cin>>t[i][a];
			b=t[a][i];
			t[a][i]=t[i][a];
		}
	}
	while(q--){
	    cost=0;
		cin>>x>>y;
		cost=w[x]+w[y];
		
		cout<<cost+t;
		
		ans=1e8;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
