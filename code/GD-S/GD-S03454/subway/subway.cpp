#include<bits/stdc++.h>
using namespace std;
int g[2010][2010];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(g,0x3f,sizeof(g));
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		int x;
		cin>>x;
		g[i][i]=x;
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int x,y;
			cin>>x>>y;
			
			g[i][x]=y;
			g[x][i]=y;
		}
	}
	for(int t=1;t<=n;t++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(i!=j&&i!=t&&j!=t)
					g[i][j]=min(g[i][j],g[i][t]+g[t][j]);
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		cout<<g[x][y]<<endl;
	}
	return 0;
}
