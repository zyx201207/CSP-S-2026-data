#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define il inline
const ll P=998244353;
const int N=1e6+10, M=5e3+10;
ll qp(ll a,ll b=P-2){
	ll res=1;
	for(;b;b>>=1,a=(a*a)%P) if(b&1) res=res*a%P;
	return res;
}
// ------------------------------------------------- //
int test_id,n,k,fa[N],tans;
int find(int x){ return x==fa[x]?x:fa[x]=find(fa[x]); }
vector<int>e[N];
vector<pair<int,int>> g;
queue<int>q;
bool a[N]; int box[N],d[N]; 
void dfs(int p,int c){
	if(p>n){
		for(int i=1;i<=n;++i) fa[i]=i,box[i]=0,d[i]=n+1;
		for(auto edges:g){
			int u=edges.fi, v=edges.se;
			if(a[u]&&a[v]){
				u=find(u), v=find(v);
				if(u^v) fa[u]=v;
			}
		}	
		for(int i=1;i<=n;++i) if(a[i]) box[find(i)]=1, d[i]=0;
		int cnt=0;
		for(int i=1;i<=n;++i) cnt+=box[i];
		if(cnt>2) return;
		while(q.size()) q.pop();
		for(int i=1;i<=n;++i) if(a[i]) q.push(i);
		int ans=0;
		while(q.size()){
			int u=q.front(); q.pop();
			for(auto v:e[u]) if(d[v]==n+1){
				d[v]=d[u]+1;
				q.push(v);
			}
		}
		for(int i=1;i<=n;++i) ans=max(ans,d[i]);
		tans=min(tans,ans);
		return;
	}
	if(c<k){ a[p]=1; dfs(p+1,c+1); }
	a[p]=0; dfs(p+1,  c);
}
// ------------------------------------------------- //
il void solve(){
	for(int i=1;i<=n;++i) e[i].clear();
	g.clear();
	cin>>n>>k;
	for(int i=1;i<n;++i){
		int u,v; cin>>u>>v;
		e[u].push_back(v);
		e[v].push_back(u);
		g.push_back({u,v});
	}
	tans=n+1;
	dfs(1,0);
	cout<<tans<<"\n";
	return;
}
// ------------------------------------------------- //
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T=1; cin>>test_id>>T;
	while(T--) solve(); 
	return 0;
}
