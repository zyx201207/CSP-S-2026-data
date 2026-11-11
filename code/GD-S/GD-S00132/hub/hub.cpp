#include<bits/stdc++.h>
using namespace std;bool Mbe;
namespace MAOJUN{

typedef vector<int> vi;
#define eb emplace_back
const int N=1e6+5;
int cid,n,k;
const int E=N<<1;
int tt,hd[N],to[E],ns[E];
inline void Add(int u,int v){to[++tt]=v;ns[tt]=hd[u];hd[u]=tt;}
#define go(ck) for(int i=hd[u];i;i=ns[i])if(int v=to[i];ck)

int fa[N],in[N],ot[N],dc,dn[N],ed[N],bk[N],dp[N];
void df1(int u,int f){
	fa[u]=f;bk[dn[u]=++dc]=u;dp[u]=dp[f]+1;in[u]=0;
	go(v^f){df1(v,u);in[u]=max(in[u],in[v]+1);}
	ed[u]=dc;
}
int pr[N],sf[N];
void df2(int u){
	vi G;
	go(v^fa[u])G.eb(v);
	int k=G.size();
	pr[0]=fa[u]?ot[u]+1:0;sf[k]=0;
	for(int i=1;i<=k;i++)pr[i]=max(pr[i-1],in[G[i-1]]+1);
	for(int i=k;i>=1;i--)sf[i-1]=max(sf[i],in[G[i-1]]+1);
	for(int i=0;i<k;i++)ot[G[i]]=max(pr[i],sf[i+1]);
	for(int v:G)df2(v);
}
int D,f[N],g[N];
inline int W(int u,int v){return max(1,v==fa[u]?g[u]:f[v]);}	// u->v
struct Mx3{
	int M1,M2,M3,C1,C2;
	Mx3():M1(0),M2(0),M3(0),C1(0),C2(0){}
	void i(int v,int w){
		if(w>M1){M3=M2;M2=M1;C2=C1;M1=w;C1=v;}
		else if(w>M2){M3=M2;M2=w;C2=v;}
		else M3=max(M3,w);
	}
	int q(){return M1;}
	int q(int v){return v!=C1?M1:M2;}
	int q(int x,int y){return x!=C1&&y!=C1?M1:x!=C2&&y!=C2?M2:M3;}
}x3[N];

typedef vector<int> vi;
#define eb emplace_back
namespace Brute{

inline vi spl(int u,int v){
	vi A,B;
	for(;dp[u]>dp[v];u=fa[u])A.eb(u);
	for(;dp[v]>dp[u];v=fa[v])B.eb(v);
	for(;u^v;u=fa[u],v=fa[v])A.eb(u),B.eb(v);
	A.eb(u);reverse(B.begin(),B.end());
	for(int i:B)A.eb(i);return A;
}
inline bool brute(){
	for(int u=1;u<=n;u++)for(int v=u+1;v<=n;v++){
		vi p=spl(u,v);
		int d=p.size();
		if(W(p[1],p[0])+W(p[d-2],p[d-1])>k)continue;
		bool ok=1;
		for(int i=1;i+1<d;i++)
			ok&=x3[p[i]].q(p[i-1],p[i+1])+min(i,d-1-i)<=D;
		if(ok)return 1;
	}
	return 0;
}

}	// O(n^3)
inline bool ck(int d){
	D=d;
	for(int u=1;u<=n;u++)f[u]=in[u]>=D,g[u]=(ot[u]>=D)-(in[fa[u]]>=D);
	for(int i=n;i>=2;i--){int u=bk[i];f[fa[u]]+=f[u];}
	for(int i=2;i<=n;i++){int u=bk[i];g[u]+=g[fa[u]];}
	for(int u=1;u<=n;u++)g[u]+=f[1]-f[u];
	if(n<=100)return Brute::brute();
	return 0;
}
namespace SLV1{

inline bool chk(){return cid==13||cid==14;}
inline void slv(){
	int m=(n-1)/2;
	if(k>=m)puts("1");
	else printf("%d\n",2+(m-k-1)/4);
}

}	// A
namespace SLV2{

struct VL{
	int f,d;
	VL():f(0),d(0){}
	VL(int f,int d):f(f),d(d){}
	void operator+=(const VL&V){
		f=max({f,V.f,d+V.d+1});d=max(d,V.d+1);
	}
	friend VL operator*(const VL&A,const VL&B){
		return VL(max({A.f,B.f,A.d+B.d}),max(A.d,B.d));
	}
}f[N],g[N],pr[N],sf[N];int fa[N];
void df1(int u,int fat){
	f[u]=VL();fa[u]=fat;
	go(v^fat){df1(v,u);f[u]+=f[v];}
}
void df2(int u){
	vi G;go(v^fa[u])G.eb(v);
	int k=G.size();
	pr[0]=sf[k]=VL();if(fa[u])pr[0]+=g[u];
	for(int i=0;i<k;i++)pr[i+1]=pr[i],pr[i+1]+=f[G[i]];
	for(int i=k;i;i--)sf[i-1]=sf[i],sf[i-1]+=f[G[i-1]];
	for(int i=0;i<k;i++)g[G[i]]=pr[i]*sf[i+1];
	for(int v:G)df2(v);
}
inline void slv(){
	df1(1,0);df2(1);
	// for(int u=2;u<=n;u++)printf("%d,%d ",f[u].f,g[u].f);puts("");
	int As=N;
	for(int u=2;u<=n;u++)As=min(As,max(f[u].f,g[u].f)+1>>1);
	printf("%d\n",As);
}

}	// sub 7,11,12
inline void slv(){
	scanf("%d%d",&n,&k);
	tt=0;memset(hd+1,0,n<<2);
	for(int i=1,u,v;i<n;i++){scanf("%d%d",&u,&v);Add(u,v);Add(v,u);}
	if(k==n){puts("0");return;}
	if(SLV1::chk())return SLV1::slv();
	if(k==2)return SLV2::slv();
	dc=0;df1(1,0);df2(1);
	for(int u=1;u<=n;u++){
		x3[u]=Mx3();
		go(v^fa[u])x3[u].i(v,in[v]+1);
		if(fa[u])x3[u].i(fa[u],ot[u]+1);
	}
	int tl=1,tr=n/2,tm;
	while(tl<tr)ck(tm=tl+tr>>1)?tr=tm:tl=tm+1;
	printf("%d\n",tl);
}
inline void main(){int T;scanf("%d%d",&cid,&T);while(T--)slv();}

}bool Med;int main(){
#ifdef IO
	freopen("D/p.in","r",stdin);
	freopen(".out","w",stdout);
#endif
#ifdef TM
	atexit([]{fprintf(stderr,"%.lfms\n%lfMB\n",clock()*1000./CLOCKS_PER_SEC,(&Mbe-&Med)/1024./1024);});
#else
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
#endif
	MAOJUN::main();
	return 0;
}