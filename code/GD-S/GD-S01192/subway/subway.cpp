#include<bits/stdc++.h>
using namespace std;
void file(string x){
	freopen((x+".in").data(),"r",stdin);
	freopen((x+".out").data(),"w",stdout);
} 
#define int long long
const int maxn=510,maxm=5e5+10;
int g[maxn][maxn],c,n,m,d,q,w[maxm];
struct gasu{
	int s,t;
};
vector<gasu>to[maxm];
signed main(){
	file("subway");
	cin.tie(0)->sync_with_stdio(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i)cin>>w[i];
	for(int i=1;i<=n;++i){
		int k;cin>>k;
		for(int j=1;j<=k;++j){
			int a,t;cin>>a>>t;
			to[a].push_back({i,t});
		}
	}
	memset(g,31,sizeof g);
	for(int i=1;i<=n;++i)g[i][i]=0;
	for(int i=1;i<=m;++i)
		for(int j=0;j<to[i].size();++j)
		for(int k=j+1;k<to[i].size();++k)
			g[to[i][j].s][to[i][k].s]=g[to[i][k].s][to[i][j].s]=min(g[to[i][j].s][to[i][k].s],to[i][j].t+to[i][k].t);
	for(int k=1;k<=n;++k)
	for(int i=1;i<=n;++i)
	if(i!=k)for(int j=i+1;j<=n;++j)
	if(j!=k)g[j][i]=g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
	while(q--){
		int x,y;cin>>x>>y;
		int ans=LLONG_MAX;
		for(int i=0;i<to[x].size();++i)
		for(int j=0;j<to[y].size();++j)
		ans=min(ans,to[x][i].t+g[to[x][i].s][to[y][j].s]+to[y][j].t);
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;
}
