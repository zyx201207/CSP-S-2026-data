#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=5e5+5,M=505;
int w[N];
pair<int,int> p[N][22];
int len[N];
int dis[M][M];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0);cout.tie(0);
	ios::sync_with_stdio(false);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int _=1;_<=k;_++){
			int x,y;
			cin>>x>>y;
			p[x][++len[x]]=make_pair(i,y);
		}
	}
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;i++)dis[i][i]=0;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=len[i];j++)for(int k=j+1;k<=len[i];k++){
			int x=p[i][j].first,y=p[i][k].first;
			dis[x][y]=dis[y][x]=min(dis[x][y],p[i][j].second+p[i][k].second);
		}
	}
	for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	while(q--){
		int u,v;
		cin>>u>>v;
		int ans=1e18;
		for(int i=1;i<=len[u];i++)for(int j=1;j<=len[v];j++){
			int x=p[u][i].first,y=p[v][j].first;
			ans=min(ans,dis[x][y]+p[u][i].second+p[v][j].second);
		}
		cout<<ans+w[u]+w[v]<<endl;
	}
}
