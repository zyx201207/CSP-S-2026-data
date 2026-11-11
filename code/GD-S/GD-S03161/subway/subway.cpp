#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=507,M=5e5+7,K=20;
const ll INF=0x3f3f3f3f3f3f3f3fll;
int c,n,m,d,q,w[M],cnt=0,had[M];
ll dis[N][N];
struct node{int to,w,nxt;} edg[M*K];
void add(int u,int v,int w){
	edg[cnt].to=v;
	edg[cnt].w=w;
	edg[cnt].nxt=had[u];
	had[u]=cnt++;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(had,-1,sizeof(had));
	memset(dis,0x3f,sizeof(dis));
	scanf("%d %d %d %d %d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++) scanf("%d",w+i);
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=0;j<k;j++){
			int a,t;
			scanf("%d %d",&a,&t);
			add(a,i,t);
		}
		dis[i][i]=0;
	}
	
	for(int i=1;i<=m;i++)
		for(int j=had[i];edg[j].nxt!=-1;j=edg[j].nxt)
			for(int k=edg[j].nxt;k!=-1;k=edg[k].nxt){
				int u=edg[j].to,v=edg[k].to;
				ll wt=edg[j].w+edg[k].w;
				dis[u][v]=min(dis[u][v],wt);
				dis[v][u]=min(dis[v][u],wt);
			}
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=n;k++)
				if(dis[j][i]!=INF&&dis[i][k]!=INF)
					dis[j][k]=min(dis[j][k],dis[j][i]+dis[i][k]);
	
	while(q--){
		int x,y;
		cin>>x>>y;
		ll res=INF;
		for(int i=had[x];i!=-1;i=edg[i].nxt){
			for(int j=had[y];j!=-1;j=edg[j].nxt){
				int u=edg[i].to,v=edg[j].to;
				ll wt=edg[i].w+edg[j].w;
				res=min(res,dis[u][v]+wt);
			}
		}
		printf("%lld\n",res+w[x]+w[y]);
	}
	return 0;
}
