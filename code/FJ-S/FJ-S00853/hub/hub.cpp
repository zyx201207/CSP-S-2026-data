#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int x=0;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar());
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+(ch^48);
	return x;
}
constexpr int N=1005,M=12;
int C,T,n,K,dep[N],vis[N],fa[N][M],num;
vector<int> e[N];
void insert(int u,int v){e[u].emplace_back(v);e[v].emplace_back(u);}
void dfs(int x,int Fa)
{
	fa[x][0]=Fa;
	for(int i=1;i<=10;i++) fa[x][i]=fa[fa[x][i-1]][i-1];
	for(auto y:e[x])
		if(y!=Fa) dep[y]=dep[x]+1,dfs(y,x);
}
int LCA(int u,int v)
{
	if(dep[u]<dep[v]) swap(u,v);
	for(int i=10;i>=1;i--)
		if(dep[fa[u][i]]>=dep[v]) u=fa[u][i];
	if(u==v) return u;
	for(int i=10;i>=1;i--)
		if(fa[u][i]!=fa[v][i]) u=fa[u][i],v=fa[v][i];
	return fa[u][0];
}
int jump(int x,int d)
{
	for(int i=7;i>=1;i--)
		if(d>=1<<i) x=fa[x][i],d-=1<<i;
	return x;
}
void dfs2(int x,int j,int fa)
{
	for(auto y:e[x])
		if(y!=fa&&y!=j) dfs2(y,j,x),vis[x]|=vis[y];
	if(vis[x]) num++;
}
int check(int i,int j,int d)
{
	for(int k=1;k<=n;k++) vis[k]=0;
	for(int k=1;k<=n;k++)
		if(dep[k]-dep[i]>d&&dep[j]+dep[k]-dep[LCA(j,k)]*2>d) vis[jump(k,d)]=1;
	num=0;dfs2(i,j,0);dfs2(j,j,fa[j][0]);
	return num;
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	C=read();T=read();
	for(;T--;)
	{
		n=read();K=read();
		for(int i=1,u,v;i<n;i++) u=read(),v=read(),insert(u,v);
		int res=n;
		for(int i=1;i<=n;i++)
		{
			dep[i]=1;dfs(i,0);
			for(int j=i+1;j<=n;j++)
			{
				int l=1,r=n;
				for(;l<r;)
				{
					int mid=(l+r)>>1;
					if(check(i,j,mid)>K) l=mid+1;
					else r=mid;
				}
				res=min(res,l);
			}
		}
		printf("%d\n",res);
		for(int i=1;i<=n;i++) e[i].clear();
	}
	return 0;
}
