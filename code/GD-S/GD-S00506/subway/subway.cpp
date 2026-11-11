#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=550;
int dp[N][N];
int zd[N*N][N];
int w[N*N]; 
set<int> xl[N];
int c,n,m,d,q;
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		while(k--)
		{
			int a,val;
			cin>>a>>val;
			zd[a][i]=val;
			xl[i].insert(a);
		}
	}
	memset(dp,0x3f,sizeof(dp));
	for(int i=1;i<=n;i++)
	{
		for(int j:xl[i])
		{
			for(int k:xl[i])
			{
				dp[j][k]=zd[j][i]+zd[k][i];
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		dp[i][i]=0;
	}
	for(int k=1;k<=m;k++)
	{
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=m;j++)
			{
				for(int l=1;l<=n;l++)	
				{

					if(xl[l].find(i)!=xl[l].end()&&xl[l].find(k)!=xl[l].end())
					{
						for(int o=l+1;o<=n;o++)
						{
							if(xl[o].find(j)!=xl[o].end()&&xl[o].find(k)!=xl[o].end())
							{
								dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]+zd[i][l]+zd[j][o]+zd[k][l]+zd[k][o]);
								break;
							}
						}
						break;
					}
					if(xl[l].find(j)!=xl[l].end()&&xl[l].find(k)!=xl[l].end())
					{
						for(int o=l+1;o<=n;o++)
						{
							if(xl[o].find(i)!=xl[o].end()&&xl[o].find(k)!=xl[o].end())
							{
								dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]+zd[i][o]+zd[j][l]+zd[k][l]+zd[k][o]);
								break;
							}
						}
						break;
					}					
				}
				
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	while(q--)
	{
		int xr,yr;
		cin>>xr>>yr;
		cout<<dp[xr][yr]+w[xr]+w[yr]<<endl;
	}
	return 0;
}
	


