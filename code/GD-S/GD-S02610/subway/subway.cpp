#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[2001],lu[2001][2001],jian[2001][2001],tong[2001][2001],guo[2001][2001],tiao[2001];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio;
	cin.tie();
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		long long zuo;
		cin>>zuo;
		for(int j=1;j<=zuo;j++)
		{
			long long xv=0,shi=0;
			cin>>xv>>shi;
			lu[i][j]=xv;
			jian[i][xv]=shi;
			tiao[xv]+=1;
			guo[xv][tiao[xv]]=i;
		}
	}
	for(int i=1;i<=m;i++)
	{
		if(tiao[i]>=2)
		{
			for(int j=1;j<tiao[i];j++)
			{
				for(int h=j+1;h<=tiao[i];h++)
				{
				    long long lu1=guo[i][j],lu2=guo[i][h];
					if(tong[lu1][lu2]==0)
					{
						tong[lu1][lu2]=jian[lu1][i]+jian[lu2][i];
						tong[lu2][lu1]=tong[lu1][lu2];
					}
					else
					{
						tong[lu1][lu2]=min(jian[lu1][i]+jian[lu2][i],tong[lu1][lu2]);
						tong[lu2][lu1]=tong[lu1][lu2];
					}
				}
			}
		}
	}
	for(int i=1;i<n;i++)
	{
		for(int j=i+1;j<=m;j++)
		{
			for(int k=1;k<=n;k++)
			{
				if(k!=i&&k!=j)
				{
					if(tong[i][j]==0)
					{
						tong[i][j]=tong[i][k]+tong[k][j];
						tong[j][i]=tong[i][j];
					}
					else
					{
						tong[i][j]=min(tong[i][k]+tong[k][j],tong[i][j]);
						tong[j][i]=tong[i][j];
					}
				}
			}
		}
	}
	for(int i=1;i<=q;i++)
	{
		long long x,y;
		cin>>x>>y;
		if(tiao[x]==1&&tiao[y]==1)
		{
			cout<<w[x]+w[y]+tong[guo[x][tiao[x]]][guo[y][tiao[y]]]+jian[guo[x][tiao[x]]][x]+jian[guo[y][tiao[y]]][y]<<endl;
		}
		else
		{
			long long qita=w[x]+w[y],bian=1e5;
			for(int i=1;i<=tiao[x];i++)
			{
				for(int j=1;j<=tiao[y];j++)
				{
					bian=min(bian,tong[guo[x][i]][guo[y][j]]+jian[guo[x][i]][x]+jian[guo[y][j]][y]);
				}
			}
			cout<<bian+qita<<endl;
		}
	}
	return 0;
} 
