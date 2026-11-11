#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int f[600][600],g[600],b[600];
bool vis[600];
vector<int> G[600];
int dfs(int x,int y)
{
	int ans=INF;
	memset(vis,0,sizeof(0));
	queue<pair<int,int> > q;
	q.push({x,g[x]});
	while(!q.empty())
	{
		int u=q.front().first;
		int s=q.front().second;
		if(u==y)
		{
			ans=min(ans,s);
		}
		q.pop();
		for(int v : G[u])
		{
			if(vis[v]==0)
			{
				q.push({v,s+g[v]}); 
				vis[v]=1;
			}
		} 
	}
	return ans;
} 
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q; 
	for(int i=1;i<=m;i++)
	{
		cin>>b[i];
		f[i][i]=0;
	}	
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		int a=0,t;
		for(int j=1;j<=k;j++)
		{	
			int ne=a;
			cin>>a>>t;
			if(ne!=0)
			{
				G[ne].push_back(a);
				G[a].push_back(ne);
			}
			
			g[a]+=t;
		}	
	}
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		cout<<dfs(x,y)+b[x]+b[y]<<endl;
	}
	return 0;
}

