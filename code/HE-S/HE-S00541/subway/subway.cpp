#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q,head[500005],dis[505][505],w[500005],len;
struct node{
	int nex,x,t;
}edge[1000006];
void add(int x,int y,int t){
	edge[++len].nex=head[x];
	edge[len].x=y;
	edge[len].t=t;
	head[x]=len;
} 
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	for(int i=0;i<=501;i++)for(int j=0;j<=501;j++)dis[i][j]=1e16;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1,k;i<=n;i++){
		cin>>k;
		for(int j=1,x,t;j<=k;j++){
			cin>>x>>t;
			for(int z=head[x];z;z=edge[z].nex){
				dis[edge[z].x][i]=min(dis[edge[z].x][i],edge[z].t+t);
				dis[i][edge[z].x]=min(dis[i][edge[z].x],edge[z].t+t);
			}
			add(x,i,t);
		}
	}
	for(int i=1;i<=n;i++)dis[i][i]=0;
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)for(int k=1;k<=n;k++)dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	//for(int i=1;i<=n;i++){for(int j=1;j<=n;j++)cout<<dis[i][j]<<" ";cout<<endl;}
	//for(int i=1;i<=n;i++){for(int j=head[i];j;j=edge[j].nex)cout<<edge[j].x<<" ";cout<<endl;}
	while(q--){
		int u,v,ans=1e16;
		cin>>u>>v;
		for(int i=head[u];i;i=edge[i].nex){
			for(int j=head[v];j;j=edge[j].nex){
				ans=min(ans,dis[edge[i].x][edge[j].x]+edge[i].t+edge[j].t);
			}
		}
		cout<<ans+w[u]+w[v]<<"\n";
	}
}
