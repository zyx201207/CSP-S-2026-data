#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
const int N=2e6+5;
int c,t,n,k,fa[N][31],dep[N];
bool vis[N];
vector<int>G[N];
void init1()
{
	for(int i=1;i<=n;i++)
	{
		G[i].clear();
		memset(fa[i],0,sizeof fa[i]);
		dep[i]=0;
	}
}
void dfs(int u,int f)
{
	for(int v:G[u])
	{
		if(v==f)continue;
		dep[v]=dep[u]+1;
		fa[v][0]=u;
		dfs(v,u);
	}
}
void init2()
{
	for(int i=1;i<31;i++)
		for(int j=1;j<=n;j++)
			fa[j][i]=fa[fa[j][i-1]][i-1];
}
int LCA(int a,int b)
{
	if(dep[a]<dep[b])swap(a,b);
	for(int i=30;i>=0;i--)
		if(dep[fa[a][i]]>=dep[b])a=fa[a][i];
	if(a==b)return a;
	for(int i=30;i>=0;i--)
		if(fa[a][i]!=fa[b][i])a=fa[a][i],b=fa[b][i];
	return fa[a][0];
}
int dist(int a,int b)
{
	return dep[a]+dep[b]-2*dep[LCA(a,b)];
}
void add(int u,int v)
{
	G[u].push_back(v);
	G[v].push_back(u);
}
bool chk(int base)
{
	int pos=0,cnt=0;
	for(int i=1;i<=n;i++)vis[i]=0;
	while(base)
	{
		++pos;
		bool flg=base&1;
		base>>=1;
		if(!flg)continue;
		bool nw=1;
		for(int v:G[pos])
		{
			if(vis[v])
			{
				nw=0;
				vis[pos]=1;
				break;
			}
		}
		if(nw)cnt++,vis[pos]=1;
	}
	return cnt<=2;
}
int d(int base)
{
	vector<int>ops;
	int pos=0,res=0;
	while(base)
	{
		++pos;
		if(base&1)ops.push_back(pos);
		base>>=1;
	}
	for(int i=1;i<=n;i++)
	{
		int tmp=inf;
		for(int v:ops)tmp=min(tmp,dist(i,v));
		res=max(res,tmp);
	}
	return res;
}
void Main()
{
	int ans=inf;
	scanf("%d%d",&n,&k);
	init1();
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
	}
	dep[1]=1;
	dfs(1,0);
	init2();
	for(int base=0;base<1<<n;base++)
	{
		if(__builtin_popcount(base)!=k)continue;
		else if(chk(base))ans=min(d(base),ans);
	}
	printf("%d\n",ans);
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--)Main();
	return 0;
}
