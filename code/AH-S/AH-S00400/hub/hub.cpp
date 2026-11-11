#include<bits/stdc++.h>
#define ll long long
#define db double
#define pb push_back
#define bint __int128
#define pii pair<int,int>
#define fi first
#define se second
#define mkp make_pair
#define gc getchar
#define chkmax(a,b) a=max(a,b)
#define chkmin(a,b) a=min(a,b)
#define debug(x) cerr<<#x<<" = "<<x<<endl
using namespace std;
mt19937 rng(time(0));
int ret(); bool vst;
db tst,ted;
const int N=1e6+5,M=N<<1,mod=998244353;
int n,k,T,Tid;
int h[N],e[M],ne[M],idx;
void add(int u,int v){
	e[idx]=v,ne[idx]=h[u],h[u]=idx++;
	e[idx]=u,ne[idx]=h[v],h[v]=idx++;
}
void read(){
	cin>>n>>k;
	for(int i=1;i<=n;i++)h[i]=-1;
	idx=0;
	for(int i=1;i< n;i++){
		int u,v; cin>>u>>v;
		add(u,v);
	}
}
int dep[N],las[N],dn[N];
int limx,limy;
void dfs0(int u,int fa,int& mx){
	if(dep[u]>dep[mx])mx=u;
	for(int i=h[u],v=e[i];~i;i=ne[i],v=e[i])if(v!=fa){
		if(v==limx&&u==limy)continue;
		if(v==limy&&u==limx)continue;
		dep[v]=dep[u]+1,las[v]=u;
		dfs0(v,u,mx);
	}
}
void getd(int u,int fa){
	dn[u]=0;
	for(int i=h[u],v=e[i];~i;i=ne[i],v=e[i])if(v!=fa){
		if(v==limx&&u==limy)continue;
		if(v==limy&&u==limx)continue;
		getd(v,u);
		chkmax(dn[u],dn[v]+1);
	}
}
inline int center(int u){
	int S=u,T; dep[u]=las[u]=0;
	dfs0(u,-1,S),T=S;
	dep[S]=las[S]=0,dfs0(S,-1,T);
	int d=dep[T]/2;
	while(d--)T=las[T];
	getd(T,-1);
	return T;
}
pii benter(int u){
	int S=u,T; dep[u]=las[u]=0;
	dfs0(u,-1,S),T=S;
	dep[S]=las[S]=0,dfs0(S,-1,T);
	int d=dep[T]/2,z=dep[T];
	while(d--)T=las[T];
	return (z&1)?mkp(T,las[T]):mkp(T,T);
}
int ct[N],seq[N];
int cut(int x,int y){
	if(ne[h[x]]==-1||ne[h[y]]==-1)return n;
	limx=x,limy=y;
	int rx=center(x),ry=center(y);
	for(int i=0;i<=n;i++)ct[i]=0;
	for(int i=1;i<=n;i++)if(i!=rx && i!=ry)ct[dn[i]]++;
	int idx=0;
	for(int i=n;i>=0;i--)
		while(ct[i]--)seq[++idx]=i;
	return seq[k-1]+1;
}
void sol1(){
	read();
	int ans=n;
	if(k==n)ans=0;
	else{
		for(int u=1;u<=n;u++)
			for(int i=h[u],v=e[i];~i;i=ne[i],v=e[i])if(v<u){
				chkmin(ans,cut(u,v));
			}
	}
	cout<<ans<<endl;
}
void sol2(){
	read();
	int ans=n;
	if(k==n)ans=0;
	else{
		auto t=benter(1);
		if(t.fi==t.se){
			for(int i=h[t.fi];~i;i=ne[i])
				chkmin(ans,cut(t.fi,e[i]));
		}
		else{
			for(int i=h[t.se];~i;i=ne[i])
				chkmin(ans,cut(t.se,e[i]));
			for(int i=h[t.fi];~i;i=ne[i])if(e[i]!=t.se)
				chkmin(ans,cut(t.fi,e[i]));
		}
	}
	cout<<ans<<endl;
}
int f[N],g[N];
void dfs1(int u,int fa){
	g[u]=f[u]=0;
	for(int i=h[u],v=e[i];~i;i=ne[i],v=e[i])if(v!=fa){
		dfs1(v,u);
		chkmax(f[u],max(f[v],g[u]+g[v]+1));
		chkmax(g[u],g[v]+1);
	}
}
int _f[N],_g[N];
struct Info{
	int mx,sum;
	Info(int v,int vv){sum=vv,mx=v;}
	Info(int v){sum=0,mx=v;}
	Info(){mx=sum=0;}
};
Info operator+(Info a,Info b){
	Info c;
	c.sum=max({a.sum,b.sum,a.mx+b.mx});
	c.mx=max(a.mx,b.mx);
	return c;
}
Info val[N];
void dfs2(int u,int fa){
	vector<int> seq;
	Info pre,suf;
	for(int i=h[u],v=e[i];~i;i=ne[i],v=e[i])if(v!=fa){
		seq.pb(v);
		val[v]=Info(_g[u],_f[u]);
	}
	for(int v:seq){
		val[v]=val[v]+pre;
		pre=pre+Info(g[v]+1,f[v]);
	}
	reverse(seq.begin(),seq.end());
	for(int v:seq){
		val[v]=val[v]+suf;
		suf=suf+Info(g[v]+1,f[v]);
	}
	seq.clear(),seq.shrink_to_fit();
	for(int i=h[u],v=e[i];~i;i=ne[i],v=e[i])if(v!=fa){
		_g[v]=val[v].mx+1,_f[v]=val[v].sum;
		dfs2(v,u);
	}
}
void sol3(){
	read(),dfs1(1,-1),_f[1]=_g[1]=0,dfs2(1,-1);
	int ans=n;
	for(int i=1;i<=n;i++)
		chkmin(ans,max((f[i]+1)/2,(_f[i]+1)/2));
	cout<<ans<<endl;
}
bool ved; int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>Tid>>T;
	tst=clock();
	while(T--){
		if(Tid<=10)sol1();
		else if(Tid>13)sol2();
		else sol3();
	}
	ted=clock();
	return ret();
}
int ret(){cerr<<"Time used: "<<abs(tst-ted)/1000000<<" s."<<endl; cerr<<"Space used: "<<abs((&vst)-(&ved))/1024.0/1024.0<<" MB."<<endl; return 0;}
//  Oct31==Dec25?

//  最后一年 CSP 了，开摆了
//  感觉这个 T3 很难写啊，反正我不写，哈哈
//  这个 T4 的 70 应该挺好写的啊，我怎么写了这么依托，码力太菜了
//  如果不挂分应该是 100+100+48+70 了，感觉今年前两个题超级弱智啊，这个分感觉要垫底了呜呜呜
//  每次正赛感觉都做不出来非平凡分啊，这好失败
//  应该是唯一一次正赛能上 300 把，去年 CSP 非常简单但是发挥的依托，NOIP 又直接被 tree 创飞，与 300 擦肩而过

//  预测一下 一等线 240 WC 线 380
//  估计这场一万个人 AK 吧，我太菜了

//  whk 真的好累，能抽出几天出来比赛真的好开心
