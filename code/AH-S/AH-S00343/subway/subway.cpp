#include<bits/stdc++.h>
using namespace std;
int data,n,m,d,q,w[20010],k,a[20010],t[20010],s[2001][2001],g[2001][2001],ans[2001][2001],start,finish,dist[20010],f[20010];
void bfs()
{
	int tx,minn=INT_MAX,i,j;
	for(int k=1;k<=m;k++)
		{
			for(i=1;i<=m;i++)
			{
				f[i]=0;
				dist[i]=s[k][i];
			}
			f[k]=1;
			for(i=2;i<=m;i++)
			{
				minn=INT_MAX;
				for(j=1;j<=m;j++)
				{
					if(f[j]==0&&dist[j]<minn)
					{
						tx=j;
						minn=dist[j];
					}
				}
				f[tx]=1;
				for(j=1;j<=m;j++)
				{
					if(f[j]==0&&s[tx][j]!=INT_MAX)
					{
						dist[j]=dist[tx]+s[tx][j];
					}
				}	
			}	
			for(i=1;i<=m;i++)
			{
				ans[k][i]=dist[i];
			}		
		}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>data>>n>>m>>d>>q;
	int i;
	for(i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(i=1;i<=m;i++)
	{
		for(int j=1;j<=m;j++)
		{
			s[i][j]=INT_MAX;
		}
	}
	for(i=1;i<=n;i++)
	{
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>a[j]>>t[j];
		}
		for(int j=1;j<=k;j++)
		{
			for(int l=j+1;l<=k;l++)
			{
				s[a[j]][a[l]]=min(t[j]+t[l],s[a[j]][a[l]]);
				s[a[l]][a[j]]=min(t[j]+t[l],s[a[l]][a[j]]);
			}
		}
	}
	bfs();
	while(q--)
	{
		cin>>start>>finish;
		cout<<ans[start][finish]+w[start]+w[finish]<<endl;
	}
	return 0;
}
