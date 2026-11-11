#include "bits/stdc++.h"
using namespace std;
typedef long long ll1;
const ll1 inf=1e18;
const int N=2e6+5;
ll1 X[N],Dis=0,Ans=0;
int n;
ll1 d[N],c[N];
void work(int st){
	for(int i=st;i<=n;i++)d[i]=inf,c[i]=0;
	d[st]=0,c[st]=1;
	for(int i=st;i<=n;i++){
		if(d[i]==inf)break;
		if(c[i]==2){
			Ans++;
		}
		for(int j=i+1;j<=n&&X[j]-X[i]<=Dis;j++){
			if(d[j]>d[i]+1){
				d[j]=d[i]+1,c[j]=c[i];
			}else if(d[j]==d[i]+1)c[j]+=c[i];
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int Tid=0,T;
	scanf("%d%d",&Tid,&T);
	while(T--){
		scanf("%d%lld",&n,&Dis);
		for(int i=1;i<=n;i++)
			scanf("%lld",&X[i]);
		Ans=0;
		for(int i=1;i<=n;i++)work(i);
		printf("%lld\n",Ans);
	}
	return 0;
}
/*
#include "bits/stdc++.h"ff
using namespace std;
typedef long long ll1;
const ll1 inf=1e18;
const int N=2e6+5;
ll1 X[N],Dis=0,Ans=0;
int n;
int fa[N],ff[N],dfn[N],mxd[N],dfns[N],tdfn=0;//老爸到了
int dep[N],root[N];
//每个点的父亲：最靠前的可以到达点
vector<int>ch[N];
vector<int>cf[N];
//fake ch，当这个点的老爸到了的时候
//如果他的 fake ch 最终深度和他一样就撤销贡献
//反之其深度为 d[u]+1，不撤销
void dfs(int u,int D,int RT){
	dep[u]=D,root[u]=RT;
	dfn[u]=++tdfn,dfns[tdfn]=u;
	for(auto v:ch[u])dfs(v,D+1,RT);
	mxd[u]=tdfn;
}
namespace sgt{
#define ls (o<<1)
#define rs (ls|1)
#define mid ((l+r)>>1)
	int L[N<<2],R[N<<2];
	int cnt[N<<2],tg[N<<2];
	void build(int o,int l,int r){
		L[o]=l,R[o]=r,cnt[o]=0,tg[o]=0;
		if(l==r)return;
		build(ls,l,mid),build(rs,mid+1,r);
	}
	void upd(int o){
		if(L[o]==R[o]){
			cnt[o]=(tg[o]==0?0:1);
			return;
		}
		cnt[o]=cnt[ls]+cnt[rs];
		if(tg[o]>0)cnt[o]=R[o]-L[o]+1;
	}
	void Add(int o,int x){tg[o]+=x,upd(o);}
	void add(int o,int lt,int rt,int x){
		int l=L[o],r=R[o];
		if(l>=lt&&r<=rt)return Add(o,x);
		if(lt<=mid)add(ls,lt,rt,x);
		if(rt> mid)add(rs,lt,rt,x);
		upd(o);
	}
	int qry(int o,int lt,int rt){
		int l=L[o],r=R[o];
		if(tg[o]>0)return min(r,rt)-max(l,lt)+1;
		if(l>=lt&&r<=rt)return cnt[o];
		int res=0;
		if(lt<=mid)res+=qry(ls,lt,rt);
		if(rt> mid)res+=qry(rs,lt,rt);
		return res;
	}
#undef ls
#undef rs
#undef mid
}
void work(){
	Ans=0;
	for(int i=n;i;i--){
		for(auto u:ch[i+1]){//这些点路边了
			//1. 撤销自己的 fake ch
			for(auto v:cf[u]){
				if(dep[u]==dep[v])sgt::add(1,dfn[v],mxd[v],-1);
				else assert(dep[u]==dep[v]-1);
			}
			//2. 添加自己的 fake father
			if(ff[u]!=0){
				if(X[ff[u]]-X[i]<=Dis){
					sgt::add(1,dfn[u],mxd[u],1);
					cf[ff[u]].emplace_back(u);
				}
			}
		}
		Ans+=sgt::qry(1,dfn[root[i]],mxd[root[i]]);
	}
}
int main(){
	int Tid=0,T;
	scanf("%d%d",&Tid,&T);
	while(T--){
		scanf("%d%lld",&n,&Dis);
		for(int i=1;i<=n;i++)
			scanf("%lld",&X[i]);
		int lst=1;
		for(int i=1;i<=n;i++){
			ch[i].clear(),cf[i].clear();
		}
		for(int i=1;i<=n;i++){
			while(X[i]-X[lst]>Dis)lst++;
			fa[i]=lst,ff[i]=0;
			if(lst<i-1){
				ff[i]=fa[i]+1;
			}
			if(fa[i]!=i){
				ch[fa[i]].emplace_back(i);
			}
		}
		tdfn=0;
		for(int i=1;i<=n;i++)if(fa[i]==i)dfs(i,1,i);
		sgt::build(1,1,n);
		Ans=0,work();
		printf("%lld\n",Ans);
	}
	return 0;
}
*/