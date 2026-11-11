#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500005],t[500005][505];
int dis[505][505];
bool ed[505][505];
int fn[505][505];//i到j的最短路一开始走的点 (地铁线路) 
struct Edge{
	int v,w;
};
vector<Edge> ve[500005];
void minway()
{
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(dis[i][j]>dis[i][k]+dis[k][j])
				{
					dis[i][j]=dis[i][k]+dis[k][j];
					if(ed[i][k])
						fn[i][j]=k;
					if(ed[k][j])
						fn[j][i]=k;
				}
			}
		}
	}
}
int main()
{
//	/*
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
//	*/
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		int k,a,tq;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>a>>tq;
			t[a][i]=tq;
			ve[a].push_back((Edge){i,tq});
			//a站过了i线，ta到线路距离为t 
		}
	}

	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			if(i==j)
				dis[i][j]=0;
			else
				dis[i][j]=INT_MAX;
		}

	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<ve[i].size();j++)
			for(int k=0;k<j;k++)
			{
				int u=ve[i][j].v,v=ve[i][k].v,wq=ve[i][j].w+ve[i][k].w;				
				ed[u][v]=true;
				ed[v][u]=true;
				dis[u][v]=wq;
				dis[v][u]=wq;
			}
	}
	minway();
	int x,y;
	for(int i=1;i<=q;i++)
	{
		cin>>x>>y;
		int ans=dis[x][y]+w[x]+w[y];
		ans+=t[x][fn[x][y]]+t[y][fn[y][x]];
		cout<<ans<<endl;
	}
	return 0;
}

//ccf makes human headache.
//T1
