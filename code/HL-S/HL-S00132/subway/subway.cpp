#include <bits/stdc++.h>
using namespace std;
const int N=5e2+5;
int dis[N][N];
int c,n,m,d,q,w[N];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	int T;
	for (int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for (int j=1;j<=k;j++)
		{
			int v,w;
			cin>>v>>w;
			dis[i][v]=1;
			dis[v][i]=1;
		}
	}
	for (int k=1;k<=n;k++)
	{
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=n;j++)
			{
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--)
	{
		int l,r;
		cin>>l>>r;
		long long ans=dis[l][r]*T*2+w[l]+w[r];
		cout<<ans<<endl;
	}
	return 0;
}
