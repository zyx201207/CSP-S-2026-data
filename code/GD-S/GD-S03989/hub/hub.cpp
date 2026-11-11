#include<bits/stdc++.h>
using namespace std;
#define pb push_back
typedef long long ll;
const int N(1e6+5);
vector<int>G[N];
int n,k;
int u[N],v[N];
int fa[N],dfn[N],siz[N],dep[N],id,rnk[N];
void dfs(int u,int f){
	fa[u]=f;
	siz[u]=1;
	dep[u]=dep[f]+1;
	dfn[u]=++id;
	rnk[id]=u;
	for(auto v:G[u]){
		if(v==f) continue ;
		dfs(v,u);
	}
}
int ans,tmp;
#define pii pair<int,int>
int deg[N],head,tail,del[N];
pii q[N];
int solve(){
	k=tmp;
	head=1; tail=0;
	for(int i(1);i<=n;++i){
		if(deg[i]==1){
			q[++tail]=make_pair(i,1);
			--k;
			del[i]=1;
		}
		if(k<=0) return q[tail].second;
	} 
	for(;head<=tail;){
		int u(q[head].first),d(q[head].second);
		++head;
		for(auto v:G[u]){
			--deg[v];
			if(deg[v]==1){
				q[++tail]=make_pair(v,d+1);
				del[v]=1;
				--k;
			}
			if(k<=0) return q[tail].second;
		}
	}
	if(k<=0) return q[tail].second;
	else return 2e9;
}
void sol(){
	cin>>n>>k;
	k=n-k;
	tmp=k;
	if(!k){
		cout<<0<<"\n";
		return ;
	}
	id=0;
	for(int i(1);i<=n;++i) G[i].clear(),deg[i]=0,del[i]=0;
	for(int i(1);i<n;++i){
		cin>>u[i]>>v[i];
		G[u[i]].pb(v[i]); ++deg[v[i]];
		G[v[i]].pb(u[i]); ++deg[u[i]];
	}
	dfs(1,0);
	for(int i(1);i<n;++i) if(dep[u[i]]>dep[v[i]]) swap(u[i],v[i]);
	ans=solve();
	for(int e(1);e<n;++e){
		for(int i(1);i<=n;++i) G[i].clear(),deg[i]=0,del[i]=0;
		for(int i(1);i<n;++i){
			if(i==e) continue ;
			G[u[i]].pb(v[i]); ++deg[v[i]];
			G[v[i]].pb(u[i]); ++deg[u[i]];
		}
		int tmp(solve()); 
		if(tmp==2e9) continue ;
		bool flag1(true),flag2(true);
		for(int i(dfn[v[e]]);i<=dfn[v[e]]+siz[v[e]]-1;++i) flag1&=(del[rnk[i]]==1);
		for(int i(1);i<dfn[v[e]];++i) flag2&=(del[rnk[i]]==1);
		for(int i(dfn[v[e]]+siz[v[e]]);i<=n;++i) flag2&=(del[rnk[i]]==1);
		if((flag1 || flag2) && (abs(siz[v[e]]-(n-siz[v[e]]))%2==0)) continue ;
		ans=min(ans,tmp);
	}cout<<ans<<"\n";
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int cs,T; cin>>cs>>T;
	for(;T;--T) sol();
	return 0;
}
