#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,t,tt,k,s;
long long g[5000][5000],dis[5005],f[5005];
void dj(int u)
{
	memset(f,0,sizeof(f));
	memset(dis,0x3f,sizeof(dis));
	dis[u]=0;
	for(int i=1;i<=m+m+n;i++)
	{
		int mi=0;
		for(int j=1;j<=m+m+n;j++)
		{
			if(f[j]==0&&(mi==0||dis[j]<dis[mi]))
			{
				mi=j;
			}
		}
		f[mi]=1;
		for(int j=1;j<=m+m+n;j++)
		{
			if(f[j]==0&&dis[mi]+g[mi][j]<dis[j])
			{
				dis[j]=dis[mi]+g[mi][j];
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(g,0x3f,sizeof(g));
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>t;
		g[i][m+i]=t;
		g[m+i][i]=t;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>t>>tt;
			g[t+m][m+m+i]=tt;
			g[m+m+i][t+m]=tt;
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>t>>tt;
		dj(t);
		cout<<dis[tt]<<'\n';
	}
}
//Oct31==Dec25?
