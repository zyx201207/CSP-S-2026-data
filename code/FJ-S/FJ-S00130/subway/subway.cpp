#include<bits/stdc++.h>
using namespace std;
struct edge
{
	int v,w;
};
int c,n,m,d,q;
int w[100005],dis[10005][10005];
void floyd()
{
	for(int i=1;i<=n+m;i++)
	{
		for(int j=1;j<=n+m;j++)
		{
			for(int k=1;k<=n+m;k++)
			{
				if(dis[i][j]>dis[i][k]+dis[j][k])
				{
					dis[i][j]=dis[j][i]=dis[i][k]+dis[j][k];
				}
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int a,t;
			cin>>a>>t;
			//cout<<a<<' '<<t<<' ';
			dis[a][m+i]=dis[m+i][a]=t;
		}
		//cout<<endl;
	}
	floyd();
	/*for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cout<<dis[i][j]<<' ';
		}
		cout<<endl;
	}*/
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		long long ans=w[x]+w[y]+dis[x][y];
		cout<<ans<<endl;
	}
	return 0;
}
