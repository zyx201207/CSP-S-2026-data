#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
const int M=3e5+10;
int n,m,a[N],ans[M];
int last[N],fa[N],sz[N];
int cnt,head[N];
struct Edge
{
	int to,next;
}edge[N];
void add(int u,int v)
{
	edge[++cnt]={v,head[u]};
	head[u]=cnt;
	fa[v]=u;
}
void dfs(int u)
{
	sz[u]=1;
	for(int i=head[u];i;i=edge[i].next)
	{
		int v=edge[i].to;
		dfs(v);sz[u]+=sz[v];
	}
	ans[a[u]]+=sz[u];
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL),cout.tie(NULL);
	srand(time(nullptr));
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=n;i>0;i--)
	{
		if(last[a[i]])
		{
			add(fa[last[a[i]]],i);
			fa[i]=fa[last[a[i]]];
		}
		else
		{
			add(i+1,i);
			fa[i]=i+1;
		}
		last[a[i]]=i;
	}
	dfs(n+1);
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
}
