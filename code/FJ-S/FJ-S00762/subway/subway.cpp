#include<bits/stdc++.h>
using namespace std;

int c,d,n,m,q;
long long w[500005],dp[505][505],f[505],ans;
vector<pair<int,long long> >V1[500005],V[505];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	int u,t;
	long long v;
	for(int i=1;i<=n;i++){
		cin>>t;
		while(t--){
			cin>>u>>v;
			V1[u].push_back({i,v});
		}
	}
	for(int i=1;i<=m;i++)
		for(int j=0;j<V1[i].size();j++)
			for(int k=0;k<V1[i].size();k++){
				int x=V1[i][j].first;
				int y=V1[i][k].first;
				v=V1[i][j].second+V1[i][k].second;
				if(x==y)
					continue;
				V[x].push_back({y,v});
				V[y].push_back({x,v});
			}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(i!=j)
				dp[i][j]=LONG_LONG_MAX;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			if(i==j)
				f[j]=0;
			else
				f[j]=LONG_LONG_MAX;
		for(int j=0;j<V[i].size();j++){
			int x=V[i][j].first;
			v=V[i][j].second;
			for(int k=1;k<=n;k++)
				if(dp[k][x]!=LONG_LONG_MAX)
					f[k]=min(f[k],dp[k][x]+v);	
			}
		for(int j=1;j<=n;j++)
			for(int k=1;k<=n;k++)
				if(f[j]!=LONG_LONG_MAX && f[k]!=LONG_LONG_MAX){
					dp[j][k]=min(dp[j][k],f[j]+f[k]);
					dp[k][j]=dp[j][k];
				}				
		}	
	while(q--){
		cin>>u>>v;
		ans=LONG_LONG_MAX;
		for(int i=0;i<V1[u].size();i++)
			for(int j=0;j<V1[v].size();j++){
				int x=V1[u][i].first;
				int y=V1[v][j].first;
				long long sum=V1[u][i].second+V1[v][j].second;
				ans=min(ans,dp[x][y]+sum+w[u]+w[v]);
			}
		cout<<ans<<"\n";
	}
	return 0;
}
