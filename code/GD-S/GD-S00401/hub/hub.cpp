#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pb push_back
const int N=5e5+10;
const ll inf=0x3f3f3f3f3f3f3f3f;
const ll MOD=998244353;
ll n,k;
vector<ll> e[N];
ll fa[N],siz[N],son[N],dep[N];
void dfs1(ll u,ll f,ll deep){
	fa[u]=f,dep[u]=deep,siz[u]=1;
	for(auto v:e[u]){
		if(v==f)continue;
		dfs1(v,u,deep+1);
		siz[u]+=siz[v];
		if(siz[son[u]]<siz[v])son[u]=v;
	}
}
ll top[N];
void dfs2(ll u,ll topf){
	top[u]=topf;
	if(son[u])dfs2(son[u],topf);
	for(auto v:e[u])if(v!=fa[u]&&v!=son[u])dfs2(v,v);
}
ll dis(ll u,ll v){
	ll ans=dep[u]+dep[v];
	while(top[u]!=top[v]){
		if(dep[top[u]]<dep[top[v]])swap(u,v);
		u=fa[top[u]];
	}
	if(dep[u]>dep[v])swap(u,v);
	return ans-(dep[u]<<1);
}
struct edge{
	ll u,v;
}e2[N];
struct DSU{
	ll fa[N];
	void init(){for(int i=1;i<=n;i++)fa[i]=i;}
	ll find(ll x){
		if(fa[x]==x)return x;
		return fa[x]=find(fa[x]);
	}
	void merge(ll x,ll y){fa[find(x)]=find(y);}
}d;
void solve(){
	cin>>n>>k;
	for(int i=1;i<=n;i++)e[i].clear(),son[i]=0;
	for(int i=1;i<n;i++){
		cin>>e2[i].u>>e2[i].v;
		e[e2[i].u].pb(e2[i].v),e[e2[i].v].pb(e2[i].u);
	}
	dfs1(1,0,0),dfs2(1,1);
	ll ans=inf;
	for(int i=1;i<(1<<n);i++){
		if(__builtin_popcount(i)!=k)continue;
		d.init();
		for(int j=1;j<n;j++){
			if((i>>(e2[j].u-1))&(i>>(e2[j].v-1))&1)d.merge(e2[j].u,e2[j].v);
		}
		ll cnt=0;
		for(int j=1;j<=n;j++){
			if(((i>>(j-1))&1)&&d.find(j)==j)cnt++;
		}
		if(cnt>2)continue;
		ll ma=0;
		for(int j=1;j<=n;j++){
			ll mi=inf;
			for(int l=1;l<=n;l++){
				if((i>>(l-1))&1)mi=min(mi,dis(j,l));
			}
			ma=max(ma,mi);
		}
		ans=min(ans,ma);
	}
	cout<<ans<<"\n";
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	ll T;
	cin>>T>>T;
	while(T--)solve();
	return 0;
} 
