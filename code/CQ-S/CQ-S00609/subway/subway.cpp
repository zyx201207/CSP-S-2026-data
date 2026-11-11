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
	#define M 500005
	#define N 505
	#define MXD 25
	#define MXQ 100005
	#define INF 0x3f3f3f3f3f3f3f3fll
	#define DEBUG cerr<<"\tfurina begin:\n"
	#define END cerr<<"\tyanami end.\n"
	#define c ch=getchar()
	il unsigned read(){
		unsigned x=0;char c;
		for(;ch<48||ch>57;c);
		for(;ch>47&&ch<58;c)x=(x<<3)+(x<<1)+(ch^48);
		return x;
	}
	il vd write(ull x){
		static int st[21],top;top=0;
		do st[++top]=x%10,x/=10;while(x);
		while(top)putchar(st[top--]^48);
	}
	#undef c
	int ctype,n,m,D,q,W[M];vector<pii >BE[M];ll dis[N][N];
	signed main(){
		ctype=read(),n=read(),m=read(),D=read(),q=read();
		for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)dis[i][j]=i==j?0:INF;
		for(int i=1;i<=m;i++)W[i]=read();
		for(int i=1;i<=n;i++){
			int k=read();
			while(k--){
				int x,y;x=read(),y=read();
				BE[x].pb(MP(i,y));
			}
		}
		for(int u=1;u<=m;u++){
			for(int i=0;i<BE[u].size();i++){
				for(int j=i+1;j<BE[u].size();j++){
					dis[BE[u][i].fi][BE[u][j].fi]=dis[BE[u][j].fi][BE[u][i].fi]=min(dis[BE[u][i].fi][BE[u][j].fi],1ll*BE[u][i].se+BE[u][j].se);
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int k=1;k<=n;k++){
					dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
				}
			}
		}
		while(q--){
			int x,y;ll res=INF;
			x=read(),y=read();
			for(pii posx:BE[x]){
				for(pii posy:BE[y]){
					res=min(res,posx.se+posy.se+dis[posx.fi][posy.fi]);
				}
			}
			res+=W[x]+W[y];
			write(res),putchar('\n');
		}
		return 0;
	}
}signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	TYX_YNXK::main();
	return 0;
}/*
y^2=ax^3+bx+c 椭圆曲线保佑
TL: 1.0s
ML: 1GB
*/
/*
T1 做 20min 有感觉吗。看完还有手感的直接集训队了。
题目这么长。感觉一堆完全没必要的东西，打磨你是吧。
这个过程似乎有三个东西：地铁口、站厅、站台。
还要记得最小话的是步行时间。
地铁口屁用没有。
所以就是换乘有代价。
多源最短路。
然后 MXD 只有 20，即度数只有 20。
线路本身也只有 500。

神了，地铁双向通行。
那还说啥了。原本想连一条链的现在直接连一个点就行。
现在就是中心有 500 个点，其余点以一定代价连至多 20 个点。
考虑预处理每个点到 500 个站台的最短距离，查询枚举 500 个站台。
有点吃操作。
哦。求站台到站台的最短距离。
复杂度 500^3 * q*20^2 
神了。20min 才想出 T2。 
*/
