#include<iostream>
#include<vector>
#define int long long
using namespace std;
int head[500005];
struct EDGE{
	int v,w,nxt;
}edge[500005];
int c,n,m,d,q,w[500005],dis[505][505],tot;
void add(int u,int v,int w){
	edge[++tot]={v,w,head[u]};
	head[u]=tot;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//freopen("/home/csps/Downloads/subway/subway7.in","r",stdin);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=m;i++) head[i]=-1;
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		while(k--){
			int x,y;
			cin>>x>>y;
			add(x,i,y);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis[i][j]=1e18;
		}
		dis[i][i]=0;
	}
	
	for(int i=1;i<=m;i++){
		for(int x=head[i];x!=-1;x=edge[x].nxt){
			for(int y=head[i];y!=-1;y=edge[y].nxt){
				if(edge[x].v==edge[y].v) continue;
				dis[edge[x].v][edge[y].v]=min(dis[edge[x].v][edge[y].v],edge[x].w+edge[y].w);
				dis[edge[y].v][edge[x].v]=min(dis[edge[y].v][edge[x].v],edge[x].w+edge[y].w);
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
		int x,y;
		cin>>x>>y;
		int ans=1e18;
		for(int i=head[x];i!=-1;i=edge[i].nxt){
			for(int j=head[y];j!=-1;j=edge[j].nxt){
				ans=min(ans,edge[i].w+edge[j].w+dis[edge[i].v][edge[j].v]);
			}
		}
		cout<<w[x]+w[y]+ans<<'\n';
	}
	return 0;
}
