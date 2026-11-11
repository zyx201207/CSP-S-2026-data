//GZ-S00317
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define eb emplace_back 
#define lowbit(x) ((x)&(-x))
random_device rnd;
mt19937 rd(rnd());
const ll N=1e6+9,INF=0x3f3f3f3f3f3f3f3f;
ll c,n,k,dep[N],mx[N],w,pr[N],siz[N],tp[N],hson[N],val[N],dfn[N],sum,cnt;
vector<ll> G[N],grd;
inline ll dfs(ll cur,ll fa){
//	cout<<cur<<" "<<fa<<" "<<dep[cur]<<" **\n";
	ll mn=INF;
	for(auto i:G[cur]){
		if(i==fa) continue;
		ll ls=dfs(i,cur);
		if(ls<mn){
			mn=ls;
		}
		mx[cur]=max(mx[cur],mx[i]);
	}
	mn++;
	if(mn>w){
		mx[cur]=max(mx[cur],dep[cur]);
	}
	if(mx[cur]>dep[cur]&&mx[cur]-dep[cur]+mn>w&&(cur==1||mx[cur]-dep[cur]==w)){
		mn=0;
//		cout<<cur<<" %%\n";
		grd.eb(cur); 
		mx[cur]=dep[cur]-w;
	}
	return mn;
}
inline void dfs0(ll cur,ll fa){
	siz[cur]=1;
	pr[cur]=fa;
	dep[cur]=dep[fa]+1;
	for(auto i:G[cur]){
		if(i==fa) continue;
		dfs0(i,cur);
		siz[cur]+=siz[i];
		if(siz[i]>siz[hson[cur]]) hson[cur]=i;
	}
}
inline void dfs1(ll cur,ll fa){
	dfn[cur]=++cnt;
	if(hson[cur]) tp[hson[cur]]=tp[cur],dfs1(hson[cur],cur);
	for(auto i:G[cur]){
		if(i==fa||i==hson[cur]) continue;
		tp[i]=i,dfs1(i,cur);
	}
}
struct BIT{
	ll c[N],si;
	inline void init(ll ze){
		si=ze;
		for(int i=1;i<=n;i++) c[i]=0;
	}
	inline void add(ll x,ll y){
		for(;x<=si;x+=lowbit(x)) c[x]+=y;
	}
	inline ll askx(ll x){
		ll res=0;
		for(;x;x-=lowbit(x)) res+=c[x];
		return res;
	}
	inline ll ask(ll l,ll r){
		if(l>r) return 0;
		return askx(r)-askx(l-1);
	}
}tr;
inline void dfs2(ll cur,ll fa){
	for(auto i:G[cur]){
		if(i==fa) continue;
		dfs2(i,cur);
		val[cur]+=val[i];
	}
	if(val[cur]){
		if(val[cur]==1) tr.add(dfn[cur],1);
		sum++;
	}
}
inline ll lca(ll u,ll v){
	while(tp[u]!=tp[v]){
		if(dep[tp[u]]>=dep[tp[v]]) u=pr[tp[u]];
		else v=pr[tp[v]];
	}
	return (dfn[u]<dfn[v]?u:v);
}
inline ll query(ll u,ll v){
	ll res=0;
	while(tp[u]!=tp[v]){
		if(dep[tp[u]]>=dep[tp[v]]){
			res+=tr.ask(dfn[tp[u]],dfn[u]);
			u=pr[tp[u]];
		}
		else{
			res+=tr.ask(dfn[tp[v]],dfn[v]);
			v=pr[tp[v]];
		}
	}
	if(dfn[v]<dfn[u]) swap(u,v);
	res+=tr.ask(dfn[u],dfn[v]);
	return res;
}
inline bool chk(ll x){
//	cout<<x<<" $$"<<endl;
	sum=0;
	grd.clear();
	tr.init(n);
	for(int i=1;i<=n;i++) val[i]=0,mx[i]=0;
	w=x;
	dfs(1,0);
	sort(grd.begin(),grd.end(),[](ll u,ll v){
		return dfn[u]<dfn[v];	
	});
//	cout<<grd.size()<<"??\n";
	ll sz=grd.size();
	if((int)sz>k) return 0;
	if((int)sz<=2) return 1;
	val[grd[0]]++;
	val[grd[sz-1]]++;
	for(int i=0;i+1<sz;i++){
		ll rt=lca(grd[i],grd[i+1]);
		val[grd[i]]++;
		val[grd[i+1]]++;
		val[rt]--;
		val[pr[rt]]--;
	}
	dfs2(1,0);
	for(int i=0;i+1<sz;i++){
		ll ls=query(grd[i],grd[i+1]);
//		cout<<grd[i]<<" "<<grd[i+1]<<"\n";
//		cout<<sum<<" "<<ls<<" ^^"<<endl; 
		if(sum-ls<=k){
			return 1;
		}
	}
	return 0;
}
inline void solve(){
	cnt=0;
	for(int i=1;i<=n;i++){
		G[i].clear();
		hson[i]=0;
	}
	cin>>n>>k;
	for(int i=1;i<n;i++){
		ll u,v;
		cin>>u>>v;
		G[u].eb(v);
		G[v].eb(u);
	}
	if(k==n){
		cout<<0<<"\n";
		return ;
	}
//	cout<<"cin"<<endl;
	dfs0(1,0);
	tp[1]=1;
	dfs1(1,0);
//	cout<<"init"<<endl;
	ll l=1,r=n,ans=n;
	while(l<=r){
		ll mid=(l+r)>>1;
		if(chk(mid)){
			ans=mid;
			r=mid-1;
		}
		else{
			l=mid+1;
		}
	}
	cout<<ans<<"\n";
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int T=1;
	cin>>c>>T;
	while(T--) solve();
	return 0;
}
/*
0 1
9 3
1 2
2 8
4 7
6 5
7 9
8 5
5 3
3 9
*/

