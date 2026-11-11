#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int c,n,m,d,q,w[N],zs[N],dt[505][N];
long long t[505][N],minx=2e9;
long long dis[N][N];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=1000;i++)
	{
		for(int j=1;j<=1000;j++) dis[i][j]=1e9;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>zs[i];
		for(int j=1;j<=zs[i];j++)
		{
			cin>>dt[i][j]>>t[i][j];
		}
		for(int j=1;j<zs[i];j++)
		{
			for(int k=j;k<=zs[i];k++)
			{
				if(j==k) 
				{
					dis[dt[i][j]][dt[i][k]]=min(dis[dt[i][j]][dt[i][k]],t[i][j]);
					continue;
				}
				dis[dt[i][j]][dt[i][k]]=min(dis[dt[i][j]][dt[i][k]],t[i][j]+t[i][k]);
				dis[dt[i][k]][dt[i][j]]=min(dis[dt[i][k]][dt[i][j]],t[i][j]+t[i][k]);
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=i+1;j<=m;j++)
		{
			for(int k=i+1;k<=m;k++)
			{
				if(j!=k)
				{
					dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
					dis[j][i]=min(dis[j][i],dis[i][k]+dis[k][j]);
				}
			}
		}
	}
	/*for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cout<<dis[i][j]<<" ";
		}
		cout<<endl;
	}*/
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		cout<<w[x]+dis[x][y]+w[y]<<"\n";
	}
	
}
