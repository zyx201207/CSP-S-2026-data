#include<bits/stdc++.h>
using namespace std;
#define us unsigned
#define ll long long
#define pb emplace_back
#define il inline
#define For(i,a,b) for(ll i=(a);i<=(b);++i)
#define Rep(i,a,b) for(ll i=(a);i>=(b);--i)
inline ll read(){
	ll num=0;bool f=1;char c=getchar();
	while(c<'0' || c>'9'){if(c=='-')f=0;c=getchar();}
	while(c>='0' && c<='9')num=num*10+(c^48),c=getchar();
	return f?num:-num;
}
const ll N=105;
ll C,_,n,k,fa[20][N],dep[N],ans;
bool vis[N];
vector<ll> tr[N];
il void dfs(ll u,ll fu,ll du){
	fa[0][u]=fu,dep[u]=du;
	for(auto x:tr[u])if(x!=fu)dfs(x,u,du+1); 
}
il ll lca(ll u,ll v){
	if(dep[u]<dep[v])swap(u,v);
	For(i,0,10)if((dep[u]-dep[v])&(1<<i))u=fa[i][u];
	if(u==v)return u;
	Rep(i,10,0){
		if(fa[u][i]!=fa[v][i])u=fa[u][i],v=fa[v][i];
	}
	return fa[u][0];
}
#define d(u,v) (dep[u]+dep[v]-(dep[lca(u,v)]*2))
il void dfs1(ll u,vector<ll>& S){
	if(vis[u])return;
	vis[u]=1;
	for(auto x:tr[u])if(binary_search(S.begin(),S.end(),x))dfs1(x,S);
}
il bool sumt(vector<ll>& S){
	For(i,1,n)vis[i]=0;
	dfs1(S.front(),S);
	ll sum0=0;
	for(auto x:S)if(!vis[x])++sum0;
	if(!sum0)return true;
	for(auto x:S){
		if(!vis[x]){
			dfs1(x,S);
			break;
		}
	}
	sum0=0;
	for(auto x:S)if(!vis[x])++sum0;
	return sum0?true:false;
}
il void solve(){
	ans=1e18;
	n=read(),k=read();
	For(i,1,n)tr[i].clear();
	for(ll i=1,u,v;i<n;++i){
		u=read(),v=read();
		tr[u].pb(v),tr[v].pb(u);
	}
	dfs(1,1,1);
	For(i,1,10)For(j,1,n)fa[i][j]=fa[i-1][fa[i-1][j]];
	for(ll i=0;i<(1<<n);++i){
		vector<ll> S;
		for(ll j=0;j<n;++j)if(i&(1<<j))S.pb(j+1);
		if((ll)S.size()!=k || sumt(S))continue;
		ll mx=0;
		For(j,1,n){
			ll mi=1e18;
			for(auto x:S)mi=min(mi,d(x,j));
			mx=max(mx,mi);
		}
		ans=min(ans,mx);
	}
	printf("%lld\n",ans);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	C=read(),_=read();while(_--)solve();
	return 0;
}

