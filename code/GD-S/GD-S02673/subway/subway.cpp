#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,k;
const long long INF=1e18;
struct node{
	int v;
	long long w;
};
vector<node> to[500005];
long long g[505][505];
long long w[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	for(int i=1;i<=500;i++){
		for(int j=1;j<=500;j++){
			g[i][j]=INF;
		} 
	}
	for(int i=1;i<=500;i++) g[i][i]=0;
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	//cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		//cin>>w[i];
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&k);
		//cin>>k;
		for(int j=1,v,w;j<=k;j++){
			//cin>>v>>w;
			scanf("%d%d",&v,&w);
			to[v].push_back({i,w});
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<to[i].size();j++){
			int u=to[i][j].v;
			long long w1=to[i][j].w;
			for(int k=j+1;k<to[i].size();k++){
				int v=to[i][k].v;
				long long w2=to[i][k].w;
				g[u][v]=min(g[u][v],w1+w2);
				g[v][u]=min(g[v][u],w1+w2);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<k;i++){
			for(int j=k+1;j<=n;j++){
				g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
				//cout<<i<<" "<<j<<" "<<g[i][j]<<endl; 
			}
		}
	}
	for(int i=1,x,y;i<=q;i++){
		scanf("%d%d",&x,&y);
		long long ans=INF;
		for(int i=0;i<to[x].size();i++){
			for(int j=0;j<to[y].size();j++){
				int u=to[x][i].v;
				int v=to[y][j].v;
				if(u>v) swap(u,v);
				long long ws=to[x][i].w+to[y][j].w;
				if(u==v){
					ans=min(ans,ws);
				}
				ans=min(ans,g[u][v]+ws);
				//cout<<u<<" "<<v<<endl;
			}
		}
		//cout<<to[x].size()<<" "<<to[y].size()<<endl;
		printf("%lld\n",ans+w[x]+w[y]);
	}
	return 0;
} 
