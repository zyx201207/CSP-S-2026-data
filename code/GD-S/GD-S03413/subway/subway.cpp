#include<bits/stdc++.h>
const int NM=500+5e5+3;
using namespace std;
typedef long long ll;
int c,n,m,d,q;
int bc[NM];
ll a[NM];
struct node{
	int u,v;
	ll t;
	bool operator <(const node& x)const{
		return this->t<x.t;
	}
};
vector<node> g;
struct node2{
	int v;ll t;
};
vector<node2> h[NM];
struct node3{
	int fa,d;//ll t;
}lt[NM];
struct node4{
	int fa;ll t;
}f[NM][21];
int in(){
	int f=1,ans=0;
	char c=getchar();
	while(!isdigit(c)){
		if(c==45)
			f=-1;
		c=getchar();
	}
	while(isdigit(c)){
		ans=ans*10+c-48;
		c=getchar();
	}
	return f*ans;
}
int bj(int x){
	if(bc[x]==x)
		return x;
	return bc[x]=bj(bc[x]);
}
void dfs(int u,int d,int fa){
	for(node2 t:h[u]){
		if(t.v==fa)
			continue;
		lt[t.v]={u,d+1};//,t.t};
		f[t.v][0]={u,t.t};
		dfs(t.v,d+1,u);
	}
}
ll lca(int x,int y){
	if(lt[x].d>lt[y].d)
		swap(x,y);
	int k=20;ll s=0;
	while(lt[y].d>=lt[x].d){
		while(k>=0&&lt[f[y][k].fa].d<lt[x].d)
			--k;
		if(k<0)
			break;
		s+=f[y][k].t;
		y=f[y][k].fa;
	}
	if(x==y)
		return s;
	k=20;
	while(x!=y){
		while(k>=0&&f[y][k].fa==f[x][k].fa)
			--k;
		if(k<0)
			break;
		s+=f[x][k].t;
		x=f[x][k].fa;
		s+=f[y][k].t;
		y=f[y][k].fa;
	}
	return s+f[x][0].t+f[y][0].t;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=in(),n=in(),m=in();
	d=in(),q=in();
	for(int i=1;i<=m;++i)
		a[i]=in();
	for(int i=1;i<=n;++i){
		int k=in(),u,v=i+m;ll t;
		for(int j=0;j<k;++j){
			u=in(),t=in();
			g.push_back({u,v,t});
		}
	}
	sort(g.begin(),g.end());
//	for(node t:g)
//		printf("%d %d %lld\n",t.u,t.v,t.t);
	for(int i=1;i<=n+m;++i)
		bc[i]=i;
	int s=0,u,v;
	for(node t:g){
		if(s>=n+m-1)
			break;
		u=bj(t.u),v=bj(t.v);
		if(u==v)
			continue;
		bc[u]=v;++s;
		h[t.u].push_back({t.v,t.t});
		h[t.v].push_back({t.u,t.t});
	}
	lt[1].d=1;
	dfs(1,1,0);
//	for(int i=1;i<=n+m;++i)
//		printf("%d %d %d %lld\n",i,lt[i].fa,lt[i].d,lt[i].t);
//	for(int i=1;i<=n+m;++i)
//		printf("%d %lld\n",i,f[i][0].fa);
	for(int k=1;k<21;++k){
		for(int i=2;i<=n+m;++i){
			f[i][k].fa=f[f[i][k-1].fa][k-1].fa;
			f[i][k].t=f[i][k-1].t+f[f[i][k-1].fa][k-1].t;
		}
	}//cout<<f[5][2].fa;
	while(q--){
		u=in(),v=in();
		printf("%lld\n",a[u]+a[v]+lca(u,v));
	}
	return 0;
}
