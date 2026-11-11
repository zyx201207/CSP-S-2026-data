#include<bits/stdc++.h>
constexpr int rSiz=1<<21;
char rBuf[rSiz],*p1=rBuf,*p2=rBuf;
#define gc() (p1==p2&&(p2=(p1=rBuf)+fread(rBuf,1,rSiz,stdin),p1==p2)?EOF:*p1++)
template<class T>void rd(T&x){
	char ch=gc();bool o=0;
	for(;ch<'0'||ch>'9';ch=gc())
		if(ch=='-')o=1;
	for(x=0;ch>='0'&&ch<='9';ch=gc())
		x=(x<<1)+(x<<3)+(ch^48);
	if(o)x=-x;
}
constexpr int _=1e6+5;
int O;
int n,k;
std::basic_string<int>e[_];
int A,B,dep[_],fat[_],siz[_];
void dfs0(int u,int fa){
	dep[u]=dep[fat[u]=fa]+1;siz[u]=1;
	if(dep[u]>dep[A])A=u;
	for(int v:e[u])if(v^fa)dfs0(v,u),siz[u]+=siz[v];
}
int pos[2],G[2];
void dfs1(int o,int u,int fa){
	dep[u]=dep[fat[u]=fa]+1;siz[u]=1;
	if(dep[u]>dep[A])A=u;
	for(int v:e[u])if(v^fa&&v^pos[o])dfs1(o,v,u),siz[u]+=siz[v];
}
int fa[20][_],dfn[_],nfd[_],dfscnt;
std::basic_string<int>h[2];
void dfs2(int o,int u,int Fa){
	int cnt=0;fat[u]=Fa;
	fa[0][u]=Fa;
	nfd[dfn[u]=++dfscnt]=u;
	for(int i=1;i<20;++i)fa[i][u]=fa[i-1][fa[i-1][u]];
	for(int v:e[u])if(v^Fa&&v^pos[o])dfs2(o,v,u),++cnt;
	if(!cnt)h[o]+=u;
}
int Fat(int u,int i){
	for(int j=19;~j;--j)if(i>>j&1)u=fa[j][u];
	return u;
}
int f[_];
bool chk(int x){
	int val=0;
	memset(f,0,sizeof f);
    for(int i=1;i<=n;++i)f[Fat(i,x)]=1;
	// for(int o=0;o<2;++o)for(int u:h[o])f[Fat(u,x)]=1;
	for(int i=n;i;--i){
		int u=nfd[i];
		if(f[u])++val,f[fat[u]]=1;
	}
	return val<=k;
}
void Diving1(){
	rd(n),rd(k);
	for(int i=1;i<=n;++i)e[i].clear();
	for(int i=1,u,v;i<n;++i)rd(u),rd(v),e[u]+=v,e[v]+=u;
	A=0;dfs0(1,0);
	B=A;A=0;dfs0(B,0);
	int dim=(dep[A]+1)/2;
	for(int i=1;i<dim;++i)A=fat[A];
	pos[0]=fat[A];pos[1]=A;
    for(int o=0;o<2;++o){
        B=pos[o^1];A=0;dfs1(o,B,0);
        B=A;A=0;dfs1(o,B,0);
        dim=(dep[A]+1)/2;
        for(int i=1;i<dim;++i)A=fat[A];
        G[o]=A;
    }
	dfscnt=0;
	for(int o=0;o<2;++o){
		h[o].clear();
		dfs2(o,G[o],0);
	}
	int l=0,r=n,mid,ans=0;
	for(;l<=r;){
		mid=(l+r)>>1;
		if(chk(mid))r=mid-1,ans=mid;
		else l=mid+1;
	}
	printf("%d\n",ans);
}
#define fio(x) freopen(x ".in","r",stdin);freopen(x ".out","w",stdout);
int main(){
	fio("hub");
	int T;rd(O),rd(T);
	for(;T;--T)Diving1();
}
// 16:55 17:30