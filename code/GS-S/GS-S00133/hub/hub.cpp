#include<bits/stdc++.h>
using namespace std;
struct abc{
	int v,w;
};
int c,n,m,d,q,dis[505][505],k,a,t,x,y,ans;
vector<abc>g[500005];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis[i][j]=1e9;
		}
	}		
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a>>t;
			g[a].push_back((abc){i,t});
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<g[i].size();j++){
			for(int k=0;k<g[i].size();k++){
				if(j==k)continue;
				dis[g[i][j].v][g[i][k].v]=g[i][j].w+g[i][k].w;
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--){
		cin>>x>>y;
		ans=1e9;
		for(int i=0;i<g[x].size();i++){
			for(int j=0;j<g[y].size();j++){
				if(i==j)continue;
				ans=min(ans,dis[g[x][i].v][g[y][j].v]);
			}
		}
		cout<<ans<<"\n";
	}			
	return 0;
}
