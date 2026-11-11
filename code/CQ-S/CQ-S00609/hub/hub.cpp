/*
我忘却了所有悲剧，所见皆是奇迹。 
*/
#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
/*
cirno /se /se
furina /se /se
yanami /se /se
yamada /se /se
sayaka /se /se
konata /se /se
蓝仙未未 /se /se 
*/
namespace Fast_io{
	#define IOSIZE 1000000
	char ibuf[IOSIZE],obuf[IOSIZE],*p1=ibuf,*p2=ibuf,*p3=obuf;
//	#ifndef Hazuki
	#define getchar() (p1==p2&&(p2=(p1=ibuf)+fread(ibuf,1,IOSIZE,stdin),p1==p2)?EOF:*p1++)
	#define putchar(x) (p3==obuf+IOSIZE&&(fwrite(obuf,p3-obuf,1,stdout),p3=obuf),*p3++=x)
//	#endif
	struct Fast_IO{inline~Fast_IO(){fwrite(obuf,p3-obuf,1,stdout);}}Furina;
}using namespace Fast_io;
namespace TYX_YNXK{
	#define il inline
	#define vd void
	#define bl bool
	#define ll long long
	#define ull unsigned ll
	#define db double
	#define ldb long db
	#define pii pair<int,int>
	#define fi first
	#define se second
	#define MP make_pair
	#define pb push_back
	#define N 1000005
	#define INF 0x3f3f3f3f
	#define DEBUG cerr<<"\tfurina begin:\n"
	#define END cerr<<"\tyanami end.\n"
	#define c ch=getchar()
	il unsigned read(){
		unsigned x=0;char c;
		for(;ch<48||ch>57;c);
		for(;ch>47&&ch<58;c)x=(x<<3)+(x<<1)+(ch^48);
		return x;
	}
	il vd write(unsigned x){
		static int st[21],top;top=0;
		do st[++top]=x%10,x/=10;while(x);
		while(top)putchar(st[top--]^48);
	}
	#undef c
	int ctype,Tim,RT,n,k,dep[N],mxd[N],fa[N],U,V,st[N],top,ans,id[N];vector<int>G[N];
	vd dfs(int u){
		dep[u]=dep[fa[u]]+1,mxd[u]=1;
		if(dep[u]>dep[RT])RT=u;
		for(int v:G[u])if(v^fa[u]){
			fa[v]=u,dfs(v);
			mxd[u]=max(mxd[u],mxd[v]+1);
		}
	}
	std::priority_queue<pii >q;
	int X,f[N];
	vd dfs1(int u){
		dep[u]=dep[fa[u]]+1,mxd[u]=1;
		f[u]=1;
		for(int v:G[u])if(v^fa[u]){
			fa[v]=u,dfs1(v);
			if(mxd[v]>X)f[u]+=f[v];
			mxd[u]=max(mxd[u],mxd[v]+1);
		}
	}
	bl flag=0;
	vd dfs2(int u,int pre,int k){
		if(flag)return;
		if(pre>X)return;
		if(f[u]<=k){flag=1;return;}
		int mx=0,semx=0;
		for(int v:G[u])if(v^fa[u]){
			if(mxd[v]>mx)semx=mx,mx=mxd[v];
			else if(mxd[v]>semx)semx=mxd[v];
		}
		for(int v:G[u])if(v^fa[u]){
			if(flag)return;
			if(mxd[v]==mx){
				int now=max(pre,semx);
				if(now+dep[u]-1<=X)dfs2(v,-INF,k);
				else dfs2(v,now+1,k);
			}else{
				int now=max(pre,mx);
				if(now+dep[u]-1<=X)dfs2(v,-INF,k);
				else dfs2(v,now+1,k);
			}
		}
	}
	il bl check(int mid){
		/*
		预处理 f[v] 表示以 v 为根的子树，要达到这个 mid 至少要多少个点。
		u 到 v 的路径上，快速处理是否合法。
		然后就做到 n^2 了。幸亏还算好写。 
		*/
		X=mid,flag=0;
		for(int I=1;I<=n&&!flag;I++){
			int rt=id[I];
//			cerr<<"rt "<<rt<<'\n';
			fa[rt]=0,dfs1(rt);
			int all=1;
			for(int v:G[rt])if(mxd[v]>X)all+=f[v];
			for(int v:G[rt])if(mxd[v]>X){
				if(flag)break;
//				cerr<<k<<' '<<k-(all-f[v])<<'\n';
				if(k>(all-f[v])){
//					DEBUG;
					dfs2(v,-INF,k-(all-f[v]));
				}
			}
		}
//		cerr<<"FLAG "<<flag<<'\n';
		return flag;
	}
	il vd solve(){
		n=read(),k=read();
		for(int i=1,u,v;i<n;i++){
			u=read(),v=read();
			G[u].pb(v),G[v].pb(u);
		}
		if(k==n){
			putchar('0'),putchar('\n');
			return;
		}
		RT=0,fa[1]=0,dfs(1);
		U=RT,RT=0,fa[U]=0,dfs(U);
		V=RT,top=0;
		for(int u=V;u;u=fa[u])st[++top]=u;
		U=st[(top+1)/2],fa[U]=0,dfs(U);
		for(int v:G[U])q.push(MP(mxd[v],v));
		for(int tk=k-1;tk--;){
			int u=q.top().se;q.pop();
			for(int v:G[u])if(v^fa[u])q.push(MP(mxd[v],v));
		}
		iota(id+1,id+1+n,1),sort(id+1,id+1+n,[&](int u,int v){return dep[u]<dep[v];});
		ans=q.top().fi;
//		cerr<<"ANS "<<ans<<'\n';
		int l=1,r=ans-1,mid,res=ans;
		while(l<=r){
			mid=l+r>>1;
			if(check(mid))res=mid,r=mid-1;
			else l=mid+1;
		}
		write(res),putchar('\n');
	}
	il vd clear(){
		for(int i=1;i<=n;i++)G[i].clear();
		while(!q.empty())q.pop();
		
	}
	signed main(){
		for(ctype=read(),Tim=read();Tim--;)solve(),clear();
		return 0;
	}
}signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	TYX_YNXK::main();
	return 0;
}/*
y^2=ax^3+bx+c 椭圆曲线保佑
TL: 3.0s
ML: 1GB
*/
/*
选 k 个点，不超过两个连通块，使得到合法点的距离最小值最大最小。

考虑先写个 nk 暴力。写出来了就可以有 60。

一个连通块是好做的：先选径心，然后每个子树类似超级钢琴的做。
两个连通块非常不好做啊。
二分答案，问题变成到两个连通块其中一个的距离不超过 mid。
问题变成了每个点都需要大小为 mid 的树上圆内至少选一个点。
或者说 k 个树上圆覆盖所有点？
我只会一个 n^3 log。先钦定两个点然后两边一起跑超级钢琴。
不对二分一个是不是就 n^2log 了？
把这个写了 290 也接受了。我可能就这么点实力。 
*/
