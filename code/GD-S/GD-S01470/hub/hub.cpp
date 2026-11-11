#include<bits/stdc++.h>
using namespace std;
struct edge{
	int to,nxt;
};
const int INF=1e9;
const int N=1e6+10;
int n,k;
edge e[N<<1];
int head[N],tot;
int fa[N],son[N],dep[N],siz[N],top[N],pre[N];
int dist[1010][1010];
void add(int u,int v){
	e[++tot]=edge{v,head[u]},head[u]=tot;
}
void dfs1(int x){
	dep[x]=dep[fa[x]]+1,siz[x]=1;
	for(int i=head[x];i;i=e[i].nxt){
		int t=e[i].to;
		if(t==fa[x]) continue;
		fa[t]=x,pre[t]=pre[x]+1;
		dfs1(t);
		siz[x]+=siz[t];
		if(!son[x]||siz[t]>siz[son[x]]) son[x]=t;
	}
}
void dfs2(int x,int tp){
	top[x]=tp;
	if(son[x]) dfs2(son[x],tp);
	for(int i=head[x];i;i=e[i].nxt){
		int t=e[i].to;
		if(t==fa[x]||t==son[x]) continue;
		dfs2(t,t);
	}
}
int LCA(int u,int v){
	while(top[u]!=top[v]) dep[top[u]]>=dep[top[v]] ? u=fa[top[u]] : v=fa[top[v]];
	return dep[u]<dep[v] ? u : v;
}
vector<int> vec;
bool invec[N];
bool vis[N];
void dfs(int x){
	vis[x]=true;
	for(int i=head[x];i;i=e[i].nxt){
		int t=e[i].to;
		if(!invec[t]) continue;
		if(vis[t]) continue;
		dfs(t);
	}
}
bool chk(){
	int cnt=0;
	for(int i=0;i<k;i++) vis[vec[i]]=false;
	for(int i=0;i<k;i++){
		if(!vis[vec[i]]){
			dfs(vec[i]);
			cnt++;
		}
	}
	return cnt<=2;
}
int ans;
void work(int x){
	if((int)vec.size()==k){
		if(!chk()) return;
//		for(int i=0;i<k;i++) cout<<vec[i]<<" ";cout<<"\n";
		int dmax=0;
		for(int u=1;u<=n;u++){
			int d=INF;
			for(int i=0;i<k;i++){
				int v=vec[i];
				d=min(d,dist[min(u,v)][max(u,v)]);
//				if(dist[min(u,v)][max(u,v)]==0) cout<<"d=0 "<<u<<" "<<v<<"\n";
			}
//			cout<<u<<" "<<d<<"\n";
			dmax=max(dmax,d);
		}
//		cout<<dmax<<"\n";
		ans=min(dmax,ans);
		return;
	}
	if(x==n+1) return;
	invec[x]=true,vec.emplace_back(x);
	work(x+1);
	invec[x]=false,vec.pop_back();
	work(x+1);
}
void Solve()
{
	cin>>n>>k;
	for(int i=1;i<=tot;i++) head[i]=0;
	tot=0;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		add(u,v),add(v,u);
	}
	for(int i=1;i<=n;i++) fa[i]=son[i]=dep[i]=siz[i]=top[i]=pre[i]=0;
	dfs1(1),dfs2(1,1);
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++) dist[i][j]=pre[i]+pre[j]-pre[LCA(i,j)]*2;
//	cout<<LCA(3,7)<<"\n";
	vec.clear();
	for(int i=1;i<=n;i++) invec[i]=false;
	ans=INF;
	work(1);
	cout<<ans<<"\n";
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int c,T=1;
	cin>>c>>T;
	while(T--){
		Solve();
	}
	return 0;
}
