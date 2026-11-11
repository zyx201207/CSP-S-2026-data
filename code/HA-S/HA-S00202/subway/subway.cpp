#include<bits/stdc++.h>
using namespace std;
int Maxn=100000001;
int main()
{

	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d1,p;
	int a[10001];
	cin>>c>>n>>m>>d1>>p;
	int t[d1+1][21],d[n+1][n+1];
	for(int i=1;i<=m;i++)
	{
		cin>>a[i];
		for(int j=0;j<21;j++)
		{
			t[i][j]=Maxn;
		}	
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			d[i][j]=-1;
		}
		int num;
		cin>>num;
		for(int j=0;j<num;j++)
		{
			int b,c;
			cin>>b>>c;
			t[b][i]=c;
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(i>=j)
			{
				continue;
			}
			d[i][j]=0;
			d[j][i]=0;
			for(int k=1;k<=n;k++)
			{
				if(t[i][k]!=Maxn&&t[j][k]!=Maxn)
				{
					d[i][j]=max(d[i][j],t[i][k]+t[j][k]);
					d[j][i]=max(d[j][i],t[i][k]+t[j][k]);
				}
				 
			}
		}
	}

	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=m;j++)
		{
			for(int k=1;k<=m;k++)
			{
				if(i!=j&&j!=k&&i!=k&&d[i][j]>d[i][k]+d[k][j]&&d[i][k]!=-1&&d[j][k]!=-1&&d[i][k]+d[j][k]!=0)
				{
					d[i][j]=d[i][k]+d[j][k];
					d[j][i]=d[i][k]+d[j][k];
				}
			}
		}
	}
	
	for(int i=0;i<p;i++)
	{
		int u;
		int v;
		cin>>u>>v;
		cout<<a[u]+a[v]+d[u][v];
	}
	return 0;
}
