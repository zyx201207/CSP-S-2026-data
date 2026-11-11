#include<algorithm>
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#define INF 0x3F3F3F3F3F3F3F3F
#define LL long long
#define MXN 505 
#define MXM 500005
using namespace std;
struct Edge{
	int v;
	LL w;
	bool operator<(const Edge&t)const{
		return w>t.w;
	}
};
LL A,g2[MXN][MXN];
bool V[MXM+500];
int c,d,m,n,q,w[MXM],xr,yr;
vector<Edge>G[MXN];
vector<vector<Edge>>g;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(g2,INF,sizeof(g2)),scanf("%d %d %d %d %d",&c,&n,&m,&d,&q),g.resize(m+n+1);
	for(int i=1;i<=m;i++)scanf("%d",w+i);
	for(int aij,i=1,ki,tij;i<=n;i++){
		scanf("%d",&ki);
		while(ki--){
			scanf("%d %d",&aij,&tij),g[aij].push_back({i,tij});
			for(Edge v:g[aij])if(v.v!=i)g2[v.v][i]=g2[i][v.v]=min(g2[v.v][i],v.w+tij);
		}
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(g2[i][j]<INF)G[i].push_back({j,g2[i][j]}),G[j].push_back({i,g2[i][j]});
	for(int i=1;i<=n;i++)sort(G[i].begin(),G[i].end());
	while(q--){
		memset(V,0,sizeof(V)),A=(1LL<<63)-1;
		scanf("%d %d",&xr,&yr);
		for(Edge line1:g[xr]){
			for(Edge line2:g[yr]){
				priority_queue<Edge>bfs;
				bfs.push({line1.v,w[xr]+w[yr]+line1.w+line2.w}),V[line1.v]=1;
				while(!bfs.empty()){
					Edge u=bfs.top();
					bfs.pop();
					if(u.v==line2.v){
						A=min(A,u.w);
						continue;
					}
					for(Edge v:G[u.v]){
						if(V[v.v])continue;
						if(v.v!=line2.v)V[v.v]=1;
						bfs.push({v.v,u.w+v.w});
					}
				}
			}
		}
		printf("%lld\n",A);
	}
	return 0;
}
