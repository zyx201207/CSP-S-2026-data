#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,k[501],x,y;
long long w[500001],di[1001][1001],dis[20001];
bool f1[1000001],f2[1000001],b[20001][20001];
vector<int>a[501];
vector<long long>t[501];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	  scanf("%lld",&w[i]);
    for(int i=1;i<=n;i++)
    {
		cin>>k[i];
		int u,v;
		for(int j=1;j<=k[i];j++)
		{
			cin>>u>>v;
			a[i].push_back(u);
			t[i].push_back(v);
		}
	}
	if(c>=7 and c<=11)
	{
		for(int i=1;i<=m;i++)
		  for(int j=1;j<=m;j++)
		    di[i][j]=1e18;
		for(int i=1;i<=m;i++)
		  di[i][i]=0;
		for(int i=1;i<=n;i++)
		  if(k[i]==2)
		  {
			  di[a[i][0]][a[i][1]]=min(di[a[i][0]][a[i][1]],t[i][0]+t[i][1]);
			  di[a[i][1]][a[i][0]]=min(di[a[i][1]][a[i][0]],t[i][0]+t[i][1]);
		  }
		for(int k=1;k<=m;k++)
		  for(int i=1;i<=m;i++)
		    for(int j=1;j<=m;j++)
		      di[i][j]=min(di[i][j],di[i][k]+di[k][j]);
		for(int i=1;i<=q;i++)
		{
			cin>>x>>y;
			cout<<di[x][y]+w[x]+w[y]<<'\n';
		}
	}
	if(c<=6)
	{
		for(int i=1;i<=m;i++)
		  for(int j=1;j<=m;j++)
		    di[i][j]=1e18;
		for(int i=1;i<=m;i++)
		  di[i][i]=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<k[i];j++)
			  for(int k2=j+1;k2<k[i];k2++)
			  {
			    di[a[i][j]][a[i][k2]]=min(di[a[i][j]][a[i][k2]],t[i][j]+t[i][k2]);
			    di[a[i][k2]][a[i][j]]=min(di[a[i][k2]][a[i][j]],t[i][k2]+t[i][j]);
			  }
		}
		for(int k=1;k<=m;k++)
		  for(int i=1;i<=m;i++)
		    for(int j=1;j<=m;j++)
		      di[i][j]=min(di[i][j],di[i][k]+di[k][j]);
		for(int i=1;i<=q;i++)
		{
			cin>>x>>y;
			cout<<di[x][y]+w[x]+w[y]<<'\n';
		}
	}
	return 0;
}
