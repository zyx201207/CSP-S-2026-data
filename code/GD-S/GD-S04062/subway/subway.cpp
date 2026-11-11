#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q,w[100005],k[505],a[505][1005],t[505][1005],x,y,f[1005][1005];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=m;j++)
		{
			f[i][j]=1e9;
		}
		f[i][i]=0;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[i][j]>>t[i][j];
		}
		for(int j=1;j<=k[i];j++)
		{
			for(int l=j+1;l<=k[i];l++)
			{
				f[a[i][j]][a[i][l]]=min(f[a[i][j]][a[i][l]],t[i][j]+t[i][l]);
				f[a[i][l]][a[i][j]]=min(t[i][j]+t[i][l],f[a[i][l]][a[i][j]]);
			}
		}
	}
	for(int l=1;l<=m;l++)
	{
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=m;j++)
			{
				f[i][j]=min(f[i][j],f[i][l]+f[l][j]);
			}
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>x>>y;
		cout<<f[x][y]+w[x]+w[y]<<endl;
	}
}
