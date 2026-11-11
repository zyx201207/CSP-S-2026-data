#include<cstdio>
#include<iostream>
#include<cmath>
#include<string>
#include<algorithm>
#include<cstring>
#include<stack>
#include<queue>
#include<map>
#include<iomanip>
#include<vector>
#include<set>
#include<deque>
#include<bitset>
using namespace std;
#define int long long
#define ll long long
#define ull unsigned ll
#define db double
#define ld long db
#define ui unsigned
#define eb push_back
#define pb pop_back
#define mk make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define ls i<<1
#define rs i<<1|1
#define fir first
#define sec second
#define wls(x) output(x),putchar(32)
#define wln(x) output(x),putchar(10)

template<class T>void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;!isdigit(c);c=getchar())f|=c==45;
	for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
	x=f?-x:x;
}
template<class T>void output(T x)
{
	if(!x)return putchar(48),void();
	if(x<0)putchar(45),x=-x;
	int sta[50]={},tot=0;
	while(x)sta[++tot]=x%10,x/=10;
	for(int i=tot;i;--i)putchar(sta[i]|48);
}
const int N=1000007;
int n,c,T,k,f[N];
bool v[N];
int head[N],tot,dep[N],ndep[N];
int siz[N],son[N],top[N];
int t1,t2,mxdep1,mxdep2,len;
struct sch{int to,next;}a[N<<1];
void add(int u,int v){a[++tot]=(sch){v,head[u]};head[u]=tot;}
void dfs(int x,int fa,int depth,int &maxd,int &r)
{
	if(depth>maxd)
	{
		maxd=depth;
		r=x;
	}
	f[x]=fa;
	dep[x]=depth;
	for(int i=head[x],to;i;i=a[i].next)
		if((to=a[i].to)!=fa)
			dfs(to,x,depth+1,maxd,r);
}
void dfs1(int x,int fa,int depth)
{
	f[x]=fa,siz[x]=1,dep[x]=depth;
	for(int to,i=head[x];i;i=a[i].next)
		if((to=a[i].to)!=fa)
		{
			dfs1(to,x,depth+1);
			siz[x]+=siz[to];
			if(siz[son[x]]<siz[to])son[x]=to;
		}
}
void dfs2(int x,int tp)
{
	top[x]=tp;
	if(!son[x])return;
	dfs2(son[x],tp);
	for(int to,i=head[x];i;i=a[i].next)
		if((to=a[i].to)!=f[x] && to!=son[x])
			dfs2(to,to);
}
int lca(int l,int r)
{
	while(top[l]!=top[r])
	{
		if(dep[top[l]]<dep[top[r]])swap(l,r);
		l=f[top[l]];
	}
	return dep[l]>dep[r]?r:l;
}
void solve(int x)
{
	if(!f[x])return;
	v[x]=1;
	ndep[dep[x]]=x;
	solve(f[x]);
}
bool check(int x)
{
	if(x*2>=len)return 1;
	int r1=ndep[x],r2=ndep[len-x];
	if(k==2)
	{
		for(int i=1;i<=n;++i)
		{
			int dis1=dep[i]+dep[r1]-2*dep[lca(i,r1)];
			int dis2=dep[i]+dep[r2]-2*dep[lca(i,r2)];
			if(min(dis1,dis2)>k)return 0;
		}
		return 1;
	}
	return 0;
}
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	read(c),read(T);
	while(T--)
	{
		read(n),read(k);
		memset(head,0,sizeof head);
		memset(v,0,sizeof v);
		mxdep1=mxdep2=t1=t2=len=tot=0;
		for(int u,v,i=1;i<n;++i)
		{
			read(u),read(v);
			add(u,v),add(v,u);
		}
		dfs(1,0,0,mxdep1,t1);
		dfs(t1,0,0,mxdep2,t2);
		solve(t2);
		len=dep[t2];
		memset(dep,0,sizeof dep);
		memset(son,0,sizeof son);
		memset(f,0,sizeof f);
		memset(siz,0,sizeof siz);
		memset(top,0,sizeof top);
		dfs1(1,0,1);
		dfs2(1,1);
		int l=0,r=n,ans=0;
		while(l<=r)
		{
			int mid=l+r>>1;
			if(check(mid))ans=mid,r=mid-1;
			else l=mid+1;
		}
		wln(ans);
	}
	return 0;
}
