#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=12;
int n,k;
namespace Graph{
	int hd[maxn],cnt=0;
	inline void ini(){for(int i=1;i<=n;i++) hd[i]=0;cnt=0;}
	struct edge{int to,nxt;}e[maxn<<1];
	inline void ade(int from,int to){e[++cnt]={to,hd[from]},hd[from]=cnt;}
}using namespace Graph;
int dep[maxn],fr[maxn];
inline int lca(int x,int y){
	if(dep[x]<dep[y]) swap(x,y);
	while(dep[x]>dep[y]) x=fr[x];
	if(x==y) return x;
	while(fr[x]!=fr[y]) x=fr[x],y=fr[y];
	return fr[x];
}
void pre(int u){
	for(int i=hd[u];i;i=e[i].nxt){
		int v=e[i].to;
		if(v==fr[u]) continue;
		fr[v]=u,dep[v]=dep[u]+1,pre(v);
	}
}
namespace DSU{
	int fa[maxn];
	void Ini(){for(int i=1;i<=n;i++) fa[i]=i;}
	int fd(int x){return fa[x]==x?x:fa[x]=fd(fa[x]);}
	void mge(int x,int y){x=fd(x),y=fd(y),fa[x]=y;}
}using namespace DSU;
inline int des(int x,int y){return dep[x]+dep[y]-(dep[lca(x,y)]<<1);}
int stk[maxn],tt=0,bk[maxn];
void Doru(){
	cin>>n>>k;
	ini();
	for(int i=1,u,v;i<n;i++){
		cin>>u>>v;
		ade(u,v),ade(v,u);
	}
	pre(1);
	int sta=(1<<n)-1,ans=n;
	for(int s=0;s<=sta;s++){
		while(tt) bk[stk[tt--]]=0;
		for(int i=0;i<n;i++) if((s>>i)&1) stk[++tt]=i+1,bk[i+1]=1;
		Ini();
		if(tt>k) continue;
		for(int i=1;i<=n;i++) if(bk[i]&&bk[fr[i]]) mge(i,fr[i]);
		int scc=0;
		for(int i=1;i<=n;i++) if(bk[i]&&fa[i]==i) scc++;
		if(scc>2) continue;
		int qwq=0;
		for(int u=1;u<=n;u++){
			int res=n;
			for(int i=1;i<=tt;i++){
				int v=stk[i];
				res=min(res,des(u,v));
			}
			qwq=max(qwq,res);
		}
		ans=min(ans,qwq);
	}
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,T;
	cin>>c>>T;
	if(c<=3) while(T--) Doru();
	return 0;
}
/*
0 1
6 5
1 2
2 5
4 5
5 3
3 6

*/
