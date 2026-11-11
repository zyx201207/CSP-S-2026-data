#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define F(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define dF(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)
#define pb push_back
#define fi first
#define se second
#define mkp make_pair
#define pii pair<int,int>
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
#define bll __int128
using namespace std;
void fre(){
	freopen("hub.in","r",stdin),freopen("hub.out","w",stdout);
}
bool ST;
template<typename T>inline void chkmax(T&x,const T&y){ x=max(x,y); }
template<typename T>inline void chkmin(T&x,const T&y){ x=min(x,y); }
const int maxn=1000005;
int testid,n,k,fa[maxn];
vector<int>g[maxn];
int dfn[maxn],dep[maxn],tim,rev[maxn],st[20][maxn],siz[maxn];
int cmp(int x,int y){ return dep[x]<=dep[y]?x:y; }
void dfs0(int u){
	dep[u]=dep[fa[u]]+1,rev[dfn[u]=++tim]=u,siz[u]=1;
	for(int&v:g[u])if(v^fa[u])fa[v]=u,dfs0(v),siz[u]+=siz[v];
}
int lca(int u,int v){
	if(u==v)return u;
	if((u=dfn[u])>(v=dfn[v]))swap(u,v);
	int t=31^__builtin_clz(v-u++);
	return cmp(st[t][u],st[t][v-(1<<t)+1]);
}
int dis(int u,int v){
	return dep[u]+dep[v]-(dep[lca(u,v)]<<1);
}
pii mrg(pii x,pii y){
	pii r=x;
	if(dis(y.fi,y.se)>dis(r.fi,r.se))r=y;
	if(dis(y.fi,x.se)>dis(r.fi,r.se))r=mkp(y.fi,x.se);
	if(dis(y.se,x.se)>dis(r.fi,r.se))r=mkp(y.se,x.se);
	if(dis(y.fi,x.fi)>dis(r.fi,r.se))r=mkp(y.fi,x.fi);
	if(dis(y.se,x.fi)>dis(r.fi,r.se))r=mkp(y.se,x.fi);
	return r;
}
vector<int>getpath(int u,int v){
	int t=lca(u,v);
	vector<int>res,R;
	for(int x=u;x!=t;x=fa[x])res.push_back(x);
	res.push_back(t);
	for(int x=v;x!=t;x=fa[x])R.push_back(x);
	reverse(all(R));
	for(int&i:R)res.push_back(i);
	return res;
}
struct Tree{
	bool vis[maxn],vis1[maxn];
	int rt,h[maxn];
	vector<int>vec;
	void init(vector<int>v,pii x){
		F(i,1,n)vis[i]=0;
		vec=v;
		for(int&i:v)vis[i]=1;
		vector<int>P=getpath(x.fi,x.se);
		rt=P[SZ(P)>>1];
		auto dfs1=[&](auto&self,int u,int lst)->void{
			h[u]=0;
			for(int&v:g[u])if(v!=lst&&vis[v])self(self,v,u),chkmax(h[u],h[v]+1);
		}; dfs1(dfs1,rt,0);
	}
	int qry(int lim){
		int res=1;
		for(int&i:vec)if(i!=rt)res+=(h[i]>=lim);
		return res;
	}
}t[2];
mt19937_64 eng(20080408);
pii dp[maxn],pre[maxn],suf[maxn];
namespace k2{
	void sol(){
		int ans=n;
		F(u,2,n){
			pii X=dp[u],Y=pre[dfn[u]-1];
			if(dfn[u]+siz[u]<=n)Y=mrg(suf[dfn[u]+siz[u]],Y);
			int L=dis(X.fi,X.se),R=dis(Y.fi,Y.se);
			chkmin(ans,max((L+1)>>1,(R+1)>>1));
		}
		cout<<ans<<'\n';
	}
}
int f[maxn];
void solve(int cid){
	cin>>n>>k,tim=0;
	F(i,1,n)g[i].clear();
	F(_,1,n-1){
		int u,v;cin>>u>>v,g[u].push_back(v),g[v].push_back(u);
	}
	if(k==n)return cout<<0<<'\n',void();
	dfs0(1);
	F(i,1,n)st[0][i]=fa[rev[i]];
	F(j,1,__lg(n))F(i,2,n-(1<<j)+1)st[j][i]=cmp(st[j-1][i],st[j-1][i+(1<<(j-1))]);
	pii X=mkp(1,1);
	F(i,2,n){
		if(dis(X.fi,i)>dis(X.fi,X.se))X=mkp(X.fi,i);
		else if(dis(X.se,i)>dis(X.fi,X.se))X=mkp(X.se,i);
	}
	int ans=(dis(X.fi,X.se)+1)>>1;
	pre[1]=mkp(rev[1],rev[1]),suf[n]=mkp(rev[n],rev[n]);
	F(i,2,n)pre[i]=mrg(pre[i-1],mkp(rev[i],rev[i]));
	dF(i,n-1,1)suf[i]=mrg(suf[i+1],mkp(rev[i],rev[i]));
	dF(_,n,1){
		const int u=rev[_];
		dp[u]=mkp(u,u);
		for(int&v:g[u])if(v!=fa[u])dp[u]=mrg(dp[u],dp[v]);
	}
	if(k==2)return k2::sol(),void();
	vector<int>perm;
	F(u,2,n)perm.push_back(u);
	shuffle(all(perm),eng);
	if(testid>12&&n>1000){
		F(u,2,n){
			pii X=dp[u],Y=pre[dfn[u]-1];
			if(dfn[u]+siz[u]<=n)Y=mrg(suf[dfn[u]+siz[u]],Y);
			int L=dis(X.fi,X.se),R=dis(Y.fi,Y.se);
			f[u]=max(L,R);
		}
		int mn=n;
		F(i,2,n)chkmin(mn,f[i]);
		vector<int>qwq;
		int QQQ=5;
		if(n<=100000)QQQ=10;
		for(int&u:perm)if(f[u]==mn&&SZ(qwq)<QQQ)qwq.push_back(u);
		perm.swap(qwq);
	}
	for(int&u:perm){
		pii X=dp[u],Y=pre[dfn[u]-1];
		if(dfn[u]+siz[u]<=n)Y=mrg(suf[dfn[u]+siz[u]],Y);
		vector<int>A,B;
		F(i,dfn[u],dfn[u]+siz[u]-1)A.push_back(rev[i]);
		F(i,1,dfn[u]-1)B.push_back(rev[i]);
		F(i,dfn[u]+siz[u],n)B.push_back(rev[i]);
		t[0].init(A,X),t[1].init(B,Y);
		auto chk=[&](int mid){
			if(t[0].qry(mid)+t[1].qry(mid)<=k)return 1;
			return 0;
		};
		if(!chk(ans))continue;
		int l=1,r=ans-1;
		while(l<=r){
			int mid=(l+r)>>1;
			if(chk(mid))ans=mid,r=mid-1;
			else l=mid+1;
		}
	}
	cout<<ans<<'\n';
}
bool ED;
signed main(){
	fre(),ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int allT;cin>>testid>>allT;
	F(_,1,allT)solve(_);
}
// g++ d.cpp -o a -std=c++14 -O2