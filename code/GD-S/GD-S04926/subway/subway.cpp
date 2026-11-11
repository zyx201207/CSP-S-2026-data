#include<bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;
const int N=505,M=5e5+5;
int n,m,q,w[M],l[N],x,y,dis[N][N],ans;
struct vv{
	int id,c;
};
vector<vv> g[M];
void ckm(int &x,int y){
	x=min(x,y);
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%*lld%lld%lld%*lld%lld",&n,&m,&q);
	for(int i=1;i<=m;i++) scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++){
		scanf("%lld",&l[i]);
		for(int j=1;j<=l[i];j++){
			scanf("%lld%lld",&x,&y);
			g[x].pb({i,y});
		}
	}
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=n;i++) dis[i][i]=0;
	for(int i=1;i<=m;i++){
		for(int j=0;j<g[i].size();j++){
			int id1=g[i][j].id,c1=g[i][j].c;
			for(int k=j+1;k<g[i].size();k++){
				int id2=g[i][k].id,c2=g[i][k].c;
				ckm(dis[id1][id2],c1+c2);
				ckm(dis[id2][id1],c1+c2);
			}
		}
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				ckm(dis[i][j],dis[i][k]+dis[k][j]);
	while(q--){
		scanf("%lld%lld",&x,&y); ans=1e18;
		for(int i=0;i<g[x].size();i++)
			for(int j=0;j<g[y].size();j++)
				ckm(ans,g[x][i].c+dis[g[x][i].id][g[y][j].id]+g[y][j].c);
		printf("%lld\n",ans+w[x]+w[y]);
	}
	return 0;
}

