#include<bits/stdc++.h> 
#define maxn 1000005
using namespace std;
int n,k,c;
vector<int> g[maxn];
int fa[maxn],dep[maxn],dfn[maxn*2],st[maxn*2][30],pos[maxn],dfnc;
void dfs1(int u,int p){
	dfn[++dfnc]=u;dep[u]=dep[p]+1;
	fa[u]=p;pos[u]=dfnc;
	for(int v:g[u]){
		if(v==p)continue;
		dfs1(v,u);
		dfn[++dfnc]=u;
	}
}
void init(){
	for(int i=1;i<=dfnc;i++){
		st[i][0]=dfn[i];
	}
	for(int j=1;j<=log2(dfnc)+1;j++){
		for(int i=1;i+(1<<j)-1<=dfnc;i++){
			if(dep[st[i][j-1]]<dep[st[i+(1<<(j-1))][j-1]]){
				st[i][j]=st[i][j-1];
			}else{
				st[i][j]=st[i+(1<<(j-1))][j-1];
			}
		}
	}
}
int lca(int u,int v){
	int l=min(pos[u],pos[v]),r=max(pos[u],pos[v]);
	int len=log2(r-l+1);
	if(dep[st[l][len]]<dep[st[r-(1<<len)+1][len]]){
		return st[l][len];
	}else{
		return st[r-(1<<len)+1][len];
	}
}
int dist(int u,int v){
	return dep[u]+dep[v]-2*dep[lca(u,v)];
}
int f[maxn],sz[maxn];
int find(int u){
	return f[u]==u?u:f[u]=find(f[u]);
}
void merge(int u,int v){
	u=find(u),v=find(v);
	if(u==v)return;
	if(sz[u]>sz[v])swap(u,v);
	sz[v]+=sz[u];
	f[u]=v;
}
void solve(){
	cin>>n>>k;
	dfnc=0;
	for(int i=1;i<=n;i++){
		g[i].clear();
	}
	for(int i=1,u,v;i<=n-1;i++){
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs1(1,0);init();
	int res=maxn;
	if(k==2&&n>10){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int dr=0;
				for(int p=1;p<=n;p++){
					if(p==i||p==j)continue;
					int dx=maxn;
					dx=min(dx,dist(i,p));
					dx=min(dx,dist(j,p));
					dr=max(dr,dx);
				}
				res=min(res,dr);
			}
		}
		cout<<res<<"\n";
		return;
	}
	for(int t=0;t<(1<<n);t++){
		unordered_set<int> st;
		bool flag=1;
		for(int i=1;i<=n;i++){
			if((t>>(i-1))&1){
				st.insert(i);
			}
			if(st.size()>k){
				flag=0;break;
			}
		}
		if(!flag)continue;
		for(int i=1;i<=n;i++){
			f[i]=i,sz[i]=1;
		} 
		for(int x:st){
			for(int v:g[x]){
				if(st.count(v)){
					merge(x,v);
				}
			}
		}
		unordered_set<int> tp;
		for(int x:st){
			tp.insert(find(x));
			if(tp.size()>2){
				flag=0;break;	
			}
		}
		if(!flag)continue;
		int dr=0;
		for(int i=1;i<=n;i++){
			if(st.count(i))continue;
			int dx=maxn;
			for(int x:st)dx=min(dx,dist(i,x));
			dr=max(dr,dx);
		}
		res=min(res,dr);
	}
	cout<<res<<"\n";
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int t;cin>>c>>t;
	while(t--)solve();
	return 0;
}
