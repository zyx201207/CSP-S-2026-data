#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=5e5+10;
struct edge{
	int u,v; ll w;
}E[maxn*2];
bool cmp(edge a,edge b){
	return a.w<b.w;
}
int c,n,m,d,q,tot,k[505],nm;
ll w[maxn];
vector<edge> to[maxn*2];
int fa[maxn*2];
void build(){
	for(int i=1;i<=tot;i++) fa[i]=i;
}
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
int up[maxn*2][22],dep[maxn*2];
ll dis[maxn*2];
void init(int u,int fa){
	up[u][0]=fa; dep[u]=dep[fa]+1;
	for(int i=1;i<=20;i++) up[u][i]=up[up[u][i-1]][i-1];
	for(edge tmp:to[u]){
		int v=tmp.v; ll w=tmp.w;
		if(v==fa) continue;
		dis[v]=dis[u]+w;
		init(v,u);
	}
}
int get_lca(int u,int v){
	if(dep[u]<dep[v]) swap(u,v);
	int df=dep[u]-dep[v];
	for(int i=20;i>=0;i--){
		if(df&(1<<i)) u=up[u][i];
	}
	if(u==v) return u;
	for(int i=20;i>=0;i--){
		if(up[u][i]!=up[v][i]) u=up[u][i],v=up[v][i];
	}
	return up[u][0];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false); cin.tie(nullptr); 
	cin>>c>>n>>m>>d>>q; tot=m;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int u; ll w; cin>>u>>w;
			++tot;
			E[++nm]=edge{u,tot,w};
			if(j!=1){
				E[++nm]=edge{tot,tot-1,0};
			}
		}
	}
	sort(E+1,E+nm+1,cmp);
	/*for(int i=1;i<=nm;i++){
		int u=E[i].u,v=E[i].v,w=E[i].w;
		cout<<u<<' '<<v<<' '<<w<<'\n';
	}*/
	build(); int cnt=0;
	for(int i=1;i<=nm;i++){
		int u=E[i].u,v=E[i].v; ll w=E[i].w;
		int fu=find(u),fv=find(v);
		if(fu!=fv){
			fa[fu]=fv; cnt++;
			to[u].push_back({u,v,w});
			to[v].push_back({v,u,w});
		}
		if(cnt==tot-1) break;
	}
	/*for(int i=1;i<=tot;i++){
		for(int j=0;j<to[i].size();j++){
			edge tmp=to[i][j];
			cout<<tmp.v<<' '<<tmp.w<<"  ";
		}
		cout<<'\n';
	}*/
	init(1,0);
	while(q--){
		int u,v; cin>>u>>v;
		int lca=get_lca(u,v);
		cout<<w[u]+w[v]+dis[u]+dis[v]-2*dis[lca]<<'\n';
	}
	fclose(stdin); fclose(stdout);
	return 0;
}
