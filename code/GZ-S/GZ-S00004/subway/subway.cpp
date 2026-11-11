//GZ-S00004 ¶­ÜÇÐù 
#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q; 
int w[1000001],a[1001][1001],t[1001][1001],k[100001];
int f[1001][1001];
int main()
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
			if(i==j) f[i][j]=0;
			f[i][j]=1e9;
		}
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[i][1]>>t[i][1];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=k[i];j++)
		{
			f[a[i][j]][a[i][j+1]]=t[i][j]+t[i][j+1];
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=m;j++)
		{
			for(int k=1;k<=m;k++)
			{
				if(f[i][k]!=1e9&&f[k][j]!=1e9&&f[i][j]!=1e9)
				{
					f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
				}
			}
		}
	}
	for(int i=1;i<=q;i++)
	{
		int x,y;
		cin>>x>>y;
		cout<<f[x][y];
	}
	return 0;
} 
