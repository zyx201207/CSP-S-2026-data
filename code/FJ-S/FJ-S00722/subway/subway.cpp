#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q,dis[505][505],w[500005];
typedef pair<int,int> PII;
vector<PII> G[500005];
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	//system("fc subway7.ans subway.out");kskbl,zdjd
	memset(dis,0x3f,sizeof(dis));
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++) dis[i][i]=0;
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		while(k--){
			int d,x;cin>>d>>x;
			G[d].push_back({i,x});
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<G[i].size();j++){
			for(int k=0;k<G[i].size();k++){
				if(j==k) continue;
				int to1=G[i][j].first,to2=G[i][k].first,v1=G[i][j].second,v2=G[i][k].second;
				dis[to1][to2]=(v1+v2<dis[to1][to2]?v1+v2:dis[to1][to2]);
				dis[to2][to1]=(v1+v2<dis[to2][to1]?v1+v2:dis[to2][to1]);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=(dis[i][k]+dis[k][j]<dis[i][j]?dis[i][k]+dis[k][j]:dis[i][j]);
			}
		}
	}
	while(q--){
		int x,y,ans=0x3f3f3f3f3f3f3f3f;cin>>x>>y;
		for(int i=0;i<G[x].size();i++){
			for(int j=0;j<G[y].size();j++){
				int to1=G[x][i].first,to2=G[y][j].first,v1=G[x][i].second,v2=G[y][j].second;
				ans=min(ans,v1+v2+dis[to1][to2]);
			}
		}
		cout<<ans+w[x]+w[y]<<"\n";
	}
}
