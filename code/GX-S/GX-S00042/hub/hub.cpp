//Game Over
#include<cstdio>
#include<cstring>
#include<vector>

using std::vector;

constexpr int N=2e6+1;

int n,T;
int maxn;
int d[N],fa[N],son[N];
vector<vector<int>> edge;
bool vis[N];

int  dfs1(int u);
int  dfs(int u);

int main()
{	
	scanf("%d",&T);

	while(T--)
	{
		scanf("%d",&n);
		edge.resize(n+1);
		for(int i=1;i<n;++i)
		{
			int u,v;
			scanf("%d %d",&u,&v);
			edge[u].push_back(v);
			edge[v].push_back(u);
		}

		d[1]=1;
		maxn=dfs(dfs1(1));

		int l=0,r=n;
		while(l<r)
		{
			mid=(l+r)>>1;
			if(3*mid+k>=maxn)
				r=mid;
			else l=mid+1;
		}

		printf("%d\n",l);
		edge.clear();
	}
}

int dfs1(int u)
{
	vis[u]=true;
	int	res=u,ans=d[u],x=u;
	for(auto v:edge[u])
		if(!vis[v])
		{
			d[v]=d[u]+1;
			x=dfs1(v);
			if(d[x]>d[res])
		res=x;
		}
return res;
}

int dfs(int u,int d)
{
	


