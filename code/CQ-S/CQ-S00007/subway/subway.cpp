#include<bits/stdc++.h>
using namespace std;
#define ll long long
int w[500005];
vector<pair<int,ll>> g[500005];
ll dis[505][505];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=m;i++){
		cin>>w[i];
	}	
	for (int i=1;i<=n;i++){
		int k;
		cin>>k;
		for (int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			g[a].push_back({i+m,t});
		}
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			dis[i][j]=1e18;
			if (i==j){
				dis[i][j]=0;
			}
		}
	}
	for (int i=1;i<=m;i++){
		for (int j=0;j<g[i].size();j++){
			for (int l=j+1;l<g[i].size();l++){
				int u=g[i][j].first-m,v=g[i][l].first-m;
				dis[u][v]=min(dis[u][v],g[i][j].second+g[i][l].second);
				dis[v][u]=min(dis[v][u],g[i][j].second+g[i][l].second);
			}
		}
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			for (int l=1;l<=n;l++){
				if (dis[j][i]==1e18||dis[i][l]==1e18)continue;
				dis[j][l]=min(dis[j][l],dis[j][i]+dis[i][l]);
			}
		}
	}
	while(q--){
		int u,v;
		cin>>u>>v;
		ll minn=1e18;
		for (pair<int,int> i:g[u]){
			for (pair<int,int> j:g[v]){
				minn=min(minn,dis[i.first-m][j.first-m]+i.second+j.second);
			}
		}
		cout<<minn+w[u]+w[v]<<endl;
	}
}
