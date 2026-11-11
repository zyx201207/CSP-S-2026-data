#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
int c_,T_;
const int maxn=1000004,maxl=20;
int n,m;
struct Edge{int to,nxt;}edg[maxn<<1];
int fr[maxn],tt;
inline void add(int u,int v){edg[++tt]={v,fr[u]},fr[u]=tt;}
int tim,dfn[maxn],st[maxl][maxn],dep[maxn];
void dfs0(int u,int fa){
	dfn[u]=++tim,st[0][tim]=fa,dep[u]=dep[fa]+1;
	for(int e=fr[u],v;e;e=edg[e].nxt){
		v=edg[e].to;if(v==fa) continue;
		dfs0(v,u); 
	}
}
inline int Max(int x,int y){return (dfn[x]<dfn[y]?x:y);}
int pw[maxl],lg[maxn];
void Sinit(){
	pw[0]=1;for(int i=1;i<maxl;i++) pw[i]=(pw[i-1]<<1);
	for(int i=2;i<=n;i++) lg[i]=lg[i>>1]+1;
	for(int j=1;j<maxl;j++) for(int i=1;i+pw[j]-1<=n;i++) st[j][i]=Max(st[j-1][i],st[j-1][i+pw[j-1]]);
}
inline int lca(int x,int y){
	if(x==y) return x;
	x=dfn[x],y=dfn[y];
	if(x>y) swap(x,y);
	return Max(st[lg[y-x]][x+1],st[lg[y-x]][y-pw[lg[y-x]]+1]);
}
inline int odis(int x,int y){return (dep[x]+dep[y]-(dep[lca(x,y)]<<1));}
int ban;
priority_queue <pii> pq;
vector <int> dot;
void dfs1(int u,int fa){
	dot.emplace_back(u);
	for(int e=fr[u],v;e;e=edg[e].nxt){
		v=edg[e].to;if(v==fa||e==ban||e==(ban^1)) continue;
		dfs1(v,u);
	}
}
int num[maxn],fath[maxn];
void dfs2(int u,int fa){
	fath[u]=fa,num[u]=0;
	for(int e=fr[u],v;e;e=edg[e].nxt){
		v=edg[e].to;if(v==fa||e==ban||e==(ban^1)) continue;
		dfs2(v,u),num[u]=max(num[u],num[v]+1);
	}
}
void sol(int u){
	dot.clear();
	dfs1(u,0);
	int S=u,T=u;
	for(int i:dot) if(odis(u,i)>odis(u,T)) T=i;
	for(int i:dot) if(odis(T,i)>odis(T,S)) S=i;
	int Rt=0,val=n;
	for(int i:dot){
		const int len=max(odis(i,S),odis(i,T));
		if(len<val) Rt=i,val=len;
	} 
	dfs2(Rt,0);
	for(int e=fr[Rt],v;e;e=edg[e].nxt){
		if(e==ban||e==(ban^1)) continue;
		v=edg[e].to,pq.emplace(num[v],v);
	}
}
void init(){
	tt=1,tim=0;
	for(int i=1;i<=n;i++) fr[i]=0;
}
void Solve(){
	cin>>n>>m;
	init();
	for(int i=1,u,v;i<n;i++) cin>>u>>v,add(u,v),add(v,u);
	dfs0(1,0);Sinit();
	int ans=n;
	for(int i=1;i<n;i++){
		while(!pq.empty()) pq.pop();
		ban=(i<<1),sol(edg[ban].to),sol(edg[ban^1].to);
		for(int j=2;j<m;j++){
			int u=pq.top().se;pq.pop();
			for(int e=fr[u],v;e;e=edg[e].nxt){
				v=edg[e].to;if(v==fath[u]||e==ban||e==(ban^1)) continue;
				pq.emplace(num[v],v);
			}
		}
		ans=min(ans,pq.top().fi);
	}ans++;
	cout<<ans<<'\n';
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c_>>T_;
	while(T_--) Solve();
	return 0;
}
