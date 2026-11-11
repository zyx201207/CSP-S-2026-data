#include <iostream> 
using namespace std;

struct Edge
{
	int u;
	int v;
}edge[1000005];
int parent[1000005];
int sz[1000005];
int find(int x)
{
	if(parent[x]==x)
	{
		return x;
	}
	return parent[x]=find(parent[x]);
}
int dis[5005][5005];
int n;
void floyd()
{
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
}
void merge(int i,int j)
{
	int a=find(i);
	int b=find(j);
	if(a==b)
	{
		return;
	}
	if(sz[a]>sz[b])
	{
		swap(a,b);
	}
	parent[a]=b;
	sz[b]+=sz[a];
}
bool vis[2000005];
int check()
{
	for(int i=1;i<=n;i++)
	{
		parent[i]=i;
		sz[i]=1;
	}
	for(int i=1;i<n;i++)
	{
		int u=edge[i].u,v=edge[i].v;
		if(vis[u] && vis[v])
		{
			merge(u,v);
		}
	}
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		cnt+=vis[i] && find(i)==i;
	}
	if(cnt>2)
	{
		return 1e9;
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int minn=1e9;
		for(int j=1;j<=n;j++)
		{
			if(vis[j])
			{
				minn=min(minn,dis[i][j]);
			}
		}
		ans=max(ans,minn);
	}
	return ans;
}
int ans;
void dfs(int k,int sum)
{
	if(sum<0 ||(n-k+1)<sum)
	{
		return;
	}
	if(k>n)
	{
		if(sum==0)
		{
			ans=min(ans,check());
		}
		return;
	}
	vis[k]=false;
	dfs(k+1,sum);
	vis[k]=true;
	dfs(k+1,sum-1);
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		int m;
		cin>>n>>m;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				dis[i][j]=1e9;
			}
			dis[i][i]=0;
		}
		for(int i=1;i<n;i++)
		{
			cin>>edge[i].u>>edge[i].v;
			dis[edge[i].u][edge[i].v]=dis[edge[i].v][edge[i].u]=1;
		}
		floyd();
		ans=1e9;
		dfs(1,m);
		cout<<ans<<'\n';
	}
	return 0;
}
