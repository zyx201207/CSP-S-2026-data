#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[100005];
int a[100005][100005];
int t[100005][100005];
int k;
int x[10005];
int y[10005];
long long u=0;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	int o[10005];
	int l=1;
	for(int i=1;i<=n;i++)
	{
		cin>>k;	
		o[l]=k;
		l++;
		for(int j=1;j<=k;j++)
		{
			cin>>a[i][j]>>t[i][j];
		}	
	}
	int num=0;
	int number=0;
	int r=0;
	int first;
	int last;
	for(int i=1;i<=q;i++)
	{
		cin>>x[i]>>y[i];
		num=0;
		number=0;
		first=0;
		last=0;
		for(int j=1;j<=n;j++)
		{
			for(int h=1;h<=o[j];h++)
			{
				if(a[j][h]==x[i]&&num==0)
				{
					u+=t[j][h];
					num++;
					first=j;
				}
				if(a[j][h]==y[i]&&number==0)
				{
					u+=t[j][h];
					number++;
					last=j;
				}			
			}	
		}
		if(first!=last)
		{
			for(int j=1;j<=n;j++)
			{
				for(int h=1;h<=n;h++)
				{
					for(int v=1;v<=o[i];v++)
					{
						for(int z=1;z<=o[i];z++)
						{
							if(j==h) h++;
							if(a[j][v]==a[h][z])
							{
								u=u+(t[j][v]+t[h][z])/n;
							
								break;
							}
						}
					}
				}
			}
		}
		u=u+w[x[i]]+w[y[i]];
		cout<<u;
		u=0;
	}

	return 0;
}
