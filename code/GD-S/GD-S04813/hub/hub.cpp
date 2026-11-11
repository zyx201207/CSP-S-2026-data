#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#ifdef DEBUG
void dbg(){cerr<<endl;}
template<typename A,typename...B>void dbg(A a,B...b){cerr<<a<<" ",dbg(b...);}
#define debug(x...) cerr<<"["<<#x<<"]: ", dbg(x)
#else
#define debug(...) (void)1
#endif

struct dsu{
	vector<int>p;
	int n;
	void init(int n1){
		n=n1+5;
		p.resize(n+1);
		iota(p.begin(),p.end(),0); 
	}
	
	int find(int x){
		while(p[x]!=x) x=p[x]=p[p[x]];
		return x;
	}
	bool unite(int x,int y){
		x=find(x),y=find(y);
		if(x==y) return 0;
		p[y]=x; return 1;
	}
	
};
vector<int>g[100];
int a[100],r,vis[100],dep[100],n,k;
int dfn[100],cnt,st[100][11];
void fl(int x,int pa=0){
	st[dfn[x]=++cnt][0]=pa;
	for(int y:g[x]) if(y!=pa) dep[y]=dep[x]+1,fl(y,x);
}
int get(int x,int y){return dfn[x]<dfn[y]?x:y;}
int lca(int x,int y){
	if(x==y) return x;
	x=dfn[x],y=dfn[y];
	if(x>y) swap(x,y);
	int k=__lg(y-x++);
	return get(st[x][k],st[y-(1<<k)+1][k]);
}
bool chk(){
	dsu p;
	p.init(n);
	for(int i=1; i<=n; i++){
		if(vis[i])
			for(int j:g[i]) if(vis[j]) p.unite(i,j);
	}
	set<int>s;
	for(int i=1; i<=n; i++) if(vis[i]) s.insert(p.p[i]);
	return s.size()==2;
}
int gt(){
	int tt=0;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			if(vis[i]&&vis[j]) tt=max(tt,dep[i]+dep[j]-dep[lca(i,j)]);
}
void dfs(int x){
	debug(x); 
	if(x>k){
		if(chk()) r=min(r,gt());
		return;
	}
	for(int i=a[x-1]+1; i<=n;i++){
		a[x]=i,vis[i]=1;
		dfs(x+1);
		vis[i]=0;
	}
	return;
}

void solve(){
	cin>>n>>k;
	for(int i=1,u,v;i<n;i++){
		cin>>u>>v,g[u].emplace_back(v),g[v].emplace_back(u);
	}
	fl(1);
	for(int i=1;i<=5;i++)
		for(int j=1;j+(1<<i)-1<=n;j++){
			st[j][i]=get(st[j][i-1],st[j+(1<<i-1)][i-1]);
		}
	r=n;
	dfs(1);

	cout<<r<<'\n';
}

int main(){
//	freopen("hub.in","r",stdin);
//	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(nullptr);
	int c,t; cin>>c>>t;
	while(t--) solve();
	return 0;
} 
