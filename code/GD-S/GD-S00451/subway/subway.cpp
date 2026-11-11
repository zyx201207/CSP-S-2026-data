#include<bits/stdc++.h>
using namespace std;

int t[500005][505];
int c,n,m,d,q;
bool vis[500005][505];
int w[500005];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

long long dfs(int x,int y,int v,long long tol)
{
	if(v==x)return tol;
	for(int i=0;i<4;i++)
	{
		if(vis[x+dx[i]][y+dy[i]]==0&&x>=1&&x<=v&&y>=1&&y<=n&&t[x+dx[i]][y+dy[i]]!=0)
		{
			vis[x+dx[i]][y+dy[i]]=1;
			return dfs(x+dx[i],y+dy[i],v,tol+t[x+dx[i]][y+dy[i]]);
		}
		
	}
}

int main()
{
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];

	for(int i=1;i<=n;i++)
	{
		
		int x;
		cin>>x;
		for(int j=1;j<=x;j++)
		{
			int y;
			cin>>y;
			cin>>t[y][i];
		}
	}
	while(q--)
	{
		int u,v;
		cin>>u>>v;
		for(int i=u;i<=v;i++)
		{
			for(int j=1;j<=n;j++)vis[i][j]=0;
		}
		long long tol=1000000;
		for(int i=1;i<=n;i++)
		{
			if(t[u][i]!=0)
			{
				tol=min(tol,w[u]+w[v]+dfs(u,i,v,t[u][i]));
			}
		}
		
		cout<<tol;
	}
	
	return 0;
 } 
