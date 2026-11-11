#include<bits/stdc++.h>
using namespace std;
#define int long long
int dp[505][505];
int w[545141];
struct node{
	int tp,zhi;
};
vector<node>g[545141];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<=500;i++){
		for(int j=0;j<=500;j++){
			dp[i][j]=11451419198102333ll;
		}
		dp[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int u,w;
			cin>>u>>w;
			g[u].push_back({i,w});
		}
	}for(int i=1;i<=m;i++){
		int p=g[i].size();
		for(int j=0;j<p;j++){
			for(int k=j+1;k<p;k++){
				int u=g[i][j].tp,v=g[i][k].tp;
				int uw=g[i][j].zhi,vw=g[i][k].zhi;
				dp[u][v]=min(dp[u][v],uw+vw);
				dp[v][u]=min(dp[v][u],uw+vw);
			}
		}
	}for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(j==i){
				continue;
			}
			for(int k=1;k<=n;k++){
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
	}while(q--){
		int x,y;
		cin>>x>>y;
		int anss=0;
		anss+=w[x]+w[y];
		int minn=11451419198102333ll;
		for(int i=0;i<g[x].size();i++){
			for(int j=0;j<g[y].size();j++){
				int u=g[x][i].tp,v=g[y][j].tp;
				minn=min(minn,dp[u][v]+g[x][i].zhi+g[y][j].zhi);
			}
		}
		cout<<anss+minn<<"\n";
	}
}
