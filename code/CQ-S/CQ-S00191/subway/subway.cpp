#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+10;
using PII=pair<int,int>;
int c,n,m,d,q,tot,w[N],f[N],dis[N],dep[N],fa[N];
int siz[N],son[N],top[N];
struct node{
	int u,v,w;
	bool operator<(const node& o){
		return w<o.w;
	}
};vector<node>p;
int find(int x){
	if(x==f[x]) return x;
	return f[x]=find(f[x]);
}
vector<PII>tree[N];
void dfs1(int u,int father){
	siz[u]=1;
	dep[u]=dep[father]+1;
	fa[u]=father;
	for(PII v:tree[u]){
		if(v.first==father) continue;
		dis[v.first]=dis[u]+v.second;
		dfs1(v.first,u);
		siz[u]+=siz[v.first];
		if(siz[son[u]]<siz[v.first]){
			son[u]=v.first;
		}
	}
}
void dfs2(int u,int father,int head){
	top[u]=head;
	if(son[u]) dfs2(son[u],u,head);
	for(PII v:tree[u]){
		if(v.first==father||v.first==son[u]) continue;
		dfs2(v.first,u,v.first);
	}
}
int LCA(int x,int y){
	while(dep[top[x]]!=dep[top[y]]){
		if(dep[top[x]]<dep[top[y]]) swap(x,y);
		x=fa[top[x]];
	}
	if(dep[x]>dep[y]) swap(x,y);
	return x;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	tot=m;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		int y=tot+1;
		for(int j=1;j<=k;j++){
			int a,t;
			tot++;
			cin>>a>>t;
			p.push_back({a,tot,t});
		}
		for(int j=y;j<tot;j++){
			p.push_back({j,j+1,0});
		}
	}
	for(int i=1;i<=tot;i++) f[i]=i;
	sort(p.begin(),p.end());
	for(node i:p){
		int u=i.u,v=i.v,w=i.w;
		int ru=find(u),rv=find(v);
		if(ru!=rv){
			f[ru]=rv;
			tree[u].push_back({v,w});
			tree[v].push_back({u,w});
		}
	}
	dfs1(1,0);
	dfs2(1,0,0);
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		int ans=w[x]+w[y];
		int lca=LCA(x,y);
		ans+=dis[x]+dis[y]-2*dis[lca];
		cout<<ans<<'\n';
	}
	return 0;
}
