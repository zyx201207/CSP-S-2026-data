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
	#ifndef Hazuki
	#define getchar() (p1==p2&&(p2=(p1=ibuf)+fread(ibuf,1,IOSIZE,stdin),p1==p2)?EOF:*p1++)
	#define putchar(x) (p3==obuf+IOSIZE&&(fwrite(obuf,p3-obuf,1,stdout),p3=obuf),*p3++=x)
	#endif
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
	#define N 2000005
	#define INF
	#define DEBUG cerr<<"\tfurina begin:\n"
	#define END cerr<<"\tyanami end.\n"
	#define c ch=getchar()
	il ll read(){
		ll x=0;bl w=1;char c;
		for(;ch<48||ch>57;c)if(ch=='-')w=0;
		for(;ch>47&&ch<58;c)x=(x<<3)+(x<<1)+(ch^48);
		return w?x:-x;
	}
	il vd write(ull x){
		static int st[21],top;top=0;
		do st[++top]=x%10,x/=10;while(x);
		while(top)putchar(st[top--]^48);
	}
	#undef c
	int ctype,Tim;
	int n,fa[N],dep[N],pre[N];ll d,X[N],ans;bl tag0[N],tag1[N];
	il vd solve(){
		n=read(),d=read(),ans=0;
		for(int i=1;i<=n;i++)X[i]=read();
		pre[1]=1;
		for(int i=2;i<=n;i++){
			pre[i]=pre[i-1];
			while(X[i]-X[pre[i]]>d)++pre[i];
		}
		if(ctype==11||ctype==12){
			//当等差数列的时候，只算哪些对 n 贡献，然后直接平移即可。
			fa[n]=n,tag0[n]=tag1[n]=0,dep[n]=0;
			for(int i=n-1;i;i--){
				fa[i]=fa[i+1],tag0[i]=tag1[i]=0;
				while(X[fa[i]]-X[i]>d)--fa[i];
				if(i==fa[i])break;
				dep[i]=dep[fa[i]]+1;
				if(tag1[fa[i]]){tag1[i]=1;continue;}
				tag0[i]=tag0[fa[i]];
				if(fa[i]>i+1&&dep[fa[i]-1]==dep[fa[i]]){
					if(fa[fa[i]-1]!=fa[fa[i]])tag1[i]=1;
					else{
						if(fa[i]>i+2&&dep[fa[i]-2]==dep[fa[i]])tag1[i]=1;
						else if(tag0[i])tag1[i]=1;
						else tag0[i]=1;
					}
				}
				if(!tag1[i]&&tag0[i]){
					ans+=i;
				}
			}
			write(ans),putchar('\n');
		}else{
			for(int j=2;j<=n;j++)if(j!=pre[j]){
				fa[j]=j,tag0[j]=tag1[j]=0,dep[j]=0;
				for(int i=j-1;i;i--){
					fa[i]=fa[i+1],tag0[i]=tag1[i]=0;
					while(X[fa[i]]-X[i]>d)--fa[i];
					if(i==fa[i])break;
					dep[i]=dep[fa[i]]+1;
					if(tag1[fa[i]]){tag1[i]=1;continue;}
					tag0[i]=tag0[fa[i]];
					if(fa[i]>i+1&&dep[fa[i]-1]==dep[fa[i]]){
						if(fa[fa[i]-1]!=fa[fa[i]])tag1[i]=1;
						else{
							if(fa[i]>i+2&&dep[fa[i]-2]==dep[fa[i]])tag1[i]=1;
							else if(tag0[i])tag1[i]=1;
							else tag0[i]=1;
						}
					}
					if(!tag1[i]&&tag0[i]){
						++ans;
					}
				}
			}
			write(ans),putchar('\n');
		}
		
	}
	signed main(){
		for(ctype=read(),Tim=read();Tim--;)solve();
		return 0;
	}
}signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	TYX_YNXK::main();
	return 0;
}/*
y^2=ax^3+bx+c 椭圆曲线保佑
TL: 1.0s
ML: 1GB
*/
/*
这期拉了，1h 才过 T1T2。
求双路径岛对。
先固定右端点，对最大跳跃建树。
当一个点的次优和最优有相同深度时会多造路径。
并且它们必须是兄弟，不然就不合法。

综上，一个点如果没有深度相同次优就没有影响。
如果有且不是兄弟关系则子树内全部不合法。
如果是兄弟关系则标记为关键点。如果祖先链已经有关键点则子树内不合法。
额还有次次优。如果次次优存在深度相同也是直接不合法。
然后就有一个 n^2 做法。 
先写暴力。

能过第 3 个大样例。我想我应该信任它。
这玩意有半点能优化的意思吗？
先跳，搞 T4，有 300 再说。

T4 写了 n^2log，可能有 50。
补了下 A 性质。 

298 好像难有突破了。
再搓个 B 性质？
 
*/
