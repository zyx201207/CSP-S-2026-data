#include<bits/stdc++.h>
#define N 1000005
#define db double
#define ul unsigned long long
#define fo(i,l,r) for(int i=(l);i<=(r);i++)
#define rf(i,r,l) for(int i=(r);i>=(l);i--)
using namespace std;
int T,n,m,K,h[N],cnt,op,x,y,z,ans,lst;
int a[N],p[N],d[N],deg[N],f[N],fat[N],g[N],s,t,ma;
bool b[N],vis[N];
struct edge{int v,n;}e[N<<1];
void ad(int u,int v){e[++cnt]={v,h[u]};h[u]=cnt;}
void ckmax(int &x,int y){if(y>x)x=y;}
void ckmin(int &x,int y){if(y<x)x=y;}
void getrt(int u,int fa,int dis,int &s){
	p[u]=fa;
	if(dis>ma)ma=dis,s=u;
	for(int i=h[u];i;i=e[i].n){
		int v=e[i].v;
		if(v^fa)getrt(v,u,dis+1,s);
	}
}
void dfs1(int u,int fa,int k){
	d[u]=0;f[u]=0;
	for(int i=h[u];i;i=e[i].n){
		int v=e[i].v;
		if(v==fa||b[v])continue;
		dfs1(v,u,k);
		f[u]+=f[v];
		ckmax(d[u],d[v]+1);
	}
	if(d[u]>=k)f[u]++;
}
void dfs2(int u,int fa,int k,int &rt){
	deg[u]=deg[fat[u]=fa]+1;
	g[u]=0;
	if(d[u]==k){g[u]=1;rt=u;return;}
	for(int i=h[u];i;i=e[i].n){
		int v=e[i].v;
		if(v==fa||b[v])continue;
		dfs2(v,u,k,rt);
		if(g[v])g[u]++;
	}
	if(g[u]>=2)rt=u;
}
void dfs3(int u,int k,int &ans){
	if(!g[u])return;
	ans++;
	if(d[u]==k)return;
	for(int i=h[u];i;i=e[i].n){
		int v=e[i].v;
		if(v==fat[u]||b[v])continue;
		dfs3(v,k,ans);
	}
}
int solve(int u,int k){
	if(h[u]<k)return 0;
	int sum=0,rt;
	dfs2(u,0,k,rt);
	dfs3(rt,k,sum);
	if(deg[rt]<=k)return sum;
	sum+=deg[rt];
	vis[rt]=1;
	stack<int>s;
	for(int i=rt;i!=u;i=fat[i])s.push(fat[i]),vis[fat[i]]=1;
	int now=0;
	while(!s.empty()){
		int x=s.top();s.pop();
		vis[x]=0;
		ckmax(now,deg[x]);
		for(int i=h[x];i;i=e[i].n){
			int v=e[i].v;
			if(v==fat[x]||vis[v]||b[v])continue;
			ckmax(now,d[v]);
		}
		if(now<=k)sum--;
		else break;
	}
	vis[rt]=0;
	return sum;
}
bool ck(int k){
	s=k+1;t=m-k;
	if(s>=t)return 1;
	int sum=m,ans;
	fo(i,s,t){
		f[a[i]]=0;
		for(int j=h[a[i]];j;j=e[j].n){
			int v=e[j].v;
			if(b[v])continue;
			dfs1(v,0,k);
			f[a[i]]+=f[v];
		}
		sum+=f[a[i]];
	}
	ans=sum;
	for(int x=s,i=s;i<=t;i++){
		if(i-x<=K)ckmin(ans,sum-(i-x-1));
		if(f[a[i]])x=i;
	}
	fo(i,s,t)
		for(int j=h[a[i]];j;j=e[j].n){
			int v=e[j].v;
			if(b[v])continue;
			ckmin(ans,sum-f[v]+solve(v,k));
		}
	return ans<=K;
}
int read(){
	int sum=0;bool f=0;char c=getchar();
	for(;c<48||c>57;c=getchar())if(c==45)f=1;
	for(;c>=48&&c<=57;c=getchar())sum=sum*10+(c&15);
	return f?-sum:sum; 
}
signed main(){
	freopen("hub.in","r",stdin);freopen("hub.out","w",stdout);
	read();T=read();
	while(T--){
		n=read();K=read();
		fo(i,1,n)h[i]=0,b[i]=0;cnt=0;
		fo(i,1,n-1)x=read(),y=read(),ad(x,y),ad(y,x);
		ma=0;getrt(1,0,0,s);
		ma=0;getrt(s,0,0,t);
		a[m=1]=t;
		for(int i=t;i^s;i=p[i])a[++m]=p[i];
		fo(i,1,m)b[a[i]]=1;
		int l=0,r=m-1,mid;
		while(l<r){
			mid=l+r>>1;
			if(ck(mid))r=mid;
			else l=mid+1;
		}
		printf("%lld\n",l);
	}
	return 0;
}
