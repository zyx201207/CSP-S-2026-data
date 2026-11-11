#include <bits/stdc++.h>
#define int long long
using namespace std;
int read()
{
	int res = 0,f = 1;
	char ch = getchar();
	while (ch<'0'||ch>'9') f = (ch=='-'?-f:f),ch = getchar();
	while (ch>='0'&&ch<='9') res = (res<<3)+(res<<1)+(ch^48),ch = getchar();
	return res*f;
}
void write(int x)
{
	if (x<0) putchar('-'),x=-x;
	if (x>9) write(x/10);
	putchar(x%10+'0');
}
void writech(int x,char ch){write(x),putchar(ch);}
const int N = 1e6+5;
int C,T;
int n,K;
vector<int> a[N];
int b[N];
int bf[N],bsz[N];
int findroot(int x){return bf[x]==x?x:bf[x]=findroot(bf[x]);}
void merge(int x,int y)
{
	x = findroot(x),y = findroot(y);
	if (x==y) return ;
	if (bsz[x]<bsz[y]) swap(x,y);
	bf[y]=x;
	bsz[x]+=bsz[y];
}
void dfs3(int x,int p)
{
	if (p!=0&&b[x]&&b[p]) merge(x,p);
	for (int i = 0; i < a[x].size(); i++)
	{
		int y = a[x][i];
		if (y==p) continue;
		dfs3(y,x);
	}
}
int f[N],dep[N],sz[N],son[N];
void dfs(int x,int p,int deep)
{
	f[x]=p,dep[x]=deep,sz[x]=1;son[x]=0;
	for (int i = 0; i < a[x].size(); i++)
	{
		int y = a[x][i];
		if (y==p) continue;
		dfs(y,x,deep+1);
		sz[x]+=sz[y];
		if (sz[y]>sz[son[x]]) son[x]=y;
	}
}
int top[N];
void dfs2(int x,int p,int topf)
{
	top[x]=topf;
	if (!son[x]) return ;
	dfs2(son[x],x,topf);
	for (int i = 0; i < a[x].size(); i++)
	{
		int y = a[x][i];
		if (y==p||y==son[x]) continue;
		dfs2(y,x,y);
	}
}
int lca(int x,int y)
{
	while (top[x]!=top[y])
	{
		if (dep[top[x]]<dep[top[y]]) swap(x,y);
		x=f[top[x]];
	}
	if (dep[x]>dep[y]) swap(x,y);
	return x;
}
int dist(int x,int y){return dep[x]+dep[y]-2*dep[lca(x,y)];}
int ans = 2e18;
void dfs4(int x,int z)
{
	if (z==K)
	{
		for (int i = 1; i <= n; i++) bf[i]=i,bsz[i]=1;
		dfs3(1,0);
		int cnt = 0;
		for (int i = 1; i <= n; i++) if (b[i]&&findroot(i)==i) cnt++;
		if (cnt>2) return ;
		int t = 0;
		for (int i = 1; i <= n; i++)
		{
			int tt = 2e18;
			for (int j = 1; j <= n; j++)
			{
				if (b[j]) tt=min(tt,dist(i,j));
			}
			t=max(t,tt);
		}
		ans=min(ans,t);
		return ;
	}
	if (n-x+1==K-z)
	{
		b[x]=1;dfs4(x+1,z+1);b[x]=0;
	}
	else
	{
		b[x]=1,dfs4(x+1,z+1);
		b[x]=0;dfs4(x+1,z);
	}
}
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	C=read(),T=read();
	while (T--)
	{
		n=read(),K=read();
		for (int i = 1; i <= n; i++) a[i].clear();
		for (int i = 1; i < n; i++)
		{
			int x=read(),y=read();
			a[x].push_back(y);
			a[y].push_back(x);
		}
		dfs(1,0,1);
		dfs2(1,0,1);
		ans=2e18;
		dfs4(1,0);
		writech(ans,'\n');
	}
	return 0;
}

