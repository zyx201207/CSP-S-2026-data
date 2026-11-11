#include <bits/stdc++.h>
using namespace std;

int c,n,m,d,q,w[200005],k[505],x,y,a[505][200005],t[505][200005];

int dfs(int x,int y)
{
	if(x==y)
	{
		return 0;
	}
	int rt=1e9;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=k[i];j++)
		{
			if(a[i][j]==x)
			{
				for(int l=j+1;l<=k[i];l++)
				{
					rt=min(rt,t[i][j]+t[i][l]+dfs(a[i][l],y));
				}
			}
		}
	}
	return rt;
}

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[i][j]>>t[i][j];
		}
	}
	while(q--)
	{
		cin>>x>>y;
		cout<<w[x]+w[y]+dfs(x,y)<<"\n";
	}
	return 0;
}
