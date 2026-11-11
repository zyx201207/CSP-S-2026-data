#include<bits/stdc++.h>
using namespace std;
const int N=510;
int c,n,m,d,q,ans=0x3f3f3f3f,y;
int dp[N][N],xianlu[N][20010],a[N],vis[N];

void dfs(int xl,int time,int jian){
	for(int i=1;i<=n;i++){
		if(xianlu[xl][y]){
			ans=min(ans,time+xianlu[xl][y]);
			return ;
		}
	}
	if(vis[xl]&&time>vis[xl]){
		return ;
	}
	vis[xl]=time;
	for(int i=1;i<=n;i++){
		if(dp[xl][i]!=0x3f3f3f3f&&i!=xl){
			dfs(i,time+dp[i][xl],jian);
		}
	}
	return ;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int l;
		cin>>l;
		for(int j=1;j<=l;j++){
			int x,y;
			cin>>x>>y;
			xianlu[i][x]=y;
		//	G[i].push_back({x,y});
			//xil[x].push_back(i);
		//	G[x].push_back({i,y});
		//  
		}
	}
//	cout<<"yes"<<endl;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			dp[i][j]=0x3f3f3f3f;
			for(int x=1;x<=m;x++){
				if(xianlu[i][x]&&xianlu[j][x]){
					dp[i][j]=min(dp[i][j],xianlu[i][x]+xianlu[j][x]);
				}
			}
			dp[j][i]=dp[i][j];
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<dp[i][j]<<" ";
//		}
//		cout<<endl;
//	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++){
//			cout<<xianlu[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	while(q--){
		ans=0x3f3f3f3f;
		int x;
		cin>>x>>y;
		for(int i=1;i<=n;i++){
			if(xianlu[i][x]){
				memset(vis,0,sizeof(vis));
				dfs(i,xianlu[i][x],xianlu[i][x]);
				
			}
		}
		//dfs(x,0);
		
		cout<<ans+a[x]+a[y]<<endl;
	}
	return 0;
}