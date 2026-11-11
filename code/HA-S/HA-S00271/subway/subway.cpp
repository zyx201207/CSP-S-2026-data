#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500],a[510][510],t[510][510];
int L[510];
int f[510][510];
int l[5010],r[5010];
int dfs(int u,int v)
{
	int ans=w[u]+w[v];
	for(int k=1;k<=m;k++)
	{
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(f[i][k]+f[k][j]<f[i][j])
				{
					f[i][j]=f[i][k]+f[k][j];
				}
			}
		}
	}
	return ans;
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
	int x=1;
	for(int i=1;i<=n;i++)
	{
		cin>>L[i];
		for(int j=1;j<=L[i];j++)
		{
			cin>>a[j][x]>>t[j][x];
		}
		x++;
		
	}
	for(int i=1;i<=x;i++)
	{
		for(int k=1;k<=n;k++)
		{
			for(int j=1;j<=L[k];j++)
			{
				f[a[j][i]][a[j+1][i]]=t[j][i];
				f[a[j+1][i]][a[j][i]]=t[j][i];
			}
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>l[i]>>r[i];
	}
	for(int i=1;i<=q;i++)
	{
		cout<<dfs(l[i],r[i])<<endl;
	}
	return 0;
}
