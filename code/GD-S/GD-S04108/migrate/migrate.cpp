#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
vector<int> e[N];
int n,m,c,t,vis[N],a[N],sum=0,dis[N][N];
inline void dfs(int root,int u,int fa,int d)
{
	//cout<<"访问点"<<u<<"父节点："<<fa<<"\n";
	vis[u]++;
	for(auto ed:e[u])
	{
		if(ed!=fa&&d+dis[fa][ed]==dis[root][ed])
		{
			dfs(root,ed,u,d+dis[fa][ed]);
		}
	}
}

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		sum=0;
		cin>>n>>m;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				dis[i][j]=a[j]-a[i];
				dis[j][i]=dis[i][j];
				//cout<<i<<"-"<<j<<":"<<dis[i][j]<<"\n";
				if(dis[i][j]<=m)
				{
					//cout<<i<<" "<<j<<"\n";
					e[i].push_back(j);
					e[j].push_back(i);
				}
			}
		}
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
		for(int i=1;i<=n;i++)
		{
			memset(vis,0,sizeof(vis));
			//cout<<"从点"<<i<<"出发\n";
			dfs(1,1,-1,0);
			for(int j=i+1;j<=n;j++)
			{
				if(vis[j]==2)
				{
					sum++;
				}
			}
		}
		cout<<sum<<endl;
	}
}
