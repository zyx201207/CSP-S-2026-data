#include<bits/stdc++.h>
using namespace std;
vector<int>G[550000];
int c,n,m,d,q;
int w[550000];
int a[550000],t[550000];
long long dis[1100][1100];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=m;i++)
		for (int j=1;j<=m;j++)
			dis[i][j]=1e12;
	for (int i=1;i<=m;i++)
		cin>>w[i];
	for (int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for (int i=1;i<=k;i++)
			cin>>a[i]>>t[i];
		for (int i=1;i<k;i++)
			for (int j=i+1;j<=k;j++)
			{
				G[a[i]].push_back(a[j]);
				G[a[j]].push_back(a[i]);
				dis[a[i]][a[j]]=t[i]+t[j];
				dis[a[j]][a[i]]=t[i]+t[j];
			}
	}
	for (int i=1;i<=m;i++)
		for (int j=1;j<=m;j++)
			for (int k=1;k<=m;k++)
				if (i!=j&&j!=k)
				{
					dis[i][j]=dis[j][i]=min(dis[i][k]+dis[k][j],dis[i][j]);
				}
	while (q--)
	{
		int x,y;
		cin>>x>>y;
		cout<<w[x]+w[y]+dis[x][y]<<'\n';
	} 
	return 0;
} 
