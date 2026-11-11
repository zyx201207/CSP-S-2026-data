#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,ww[500005],k[505];
long long dp[505][505];
vector<long long> u[500005],w[500005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>ww[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			dp[i][j]=1e18;
		}
		dp[i][i]=0;
	} 
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			long long www,bbb;
			cin>>www>>bbb;
			u[www].push_back(i);
			w[www].push_back(bbb);
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<u[i].size();j++)
		{
			for(int kk=j+1;kk<u[i].size();kk++)
			{
				dp[u[i][kk]][u[i][j]]=min(dp[u[i][kk]][u[i][j]],w[i][kk]+w[i][j]);
				dp[u[i][j]][u[i][kk]]=min(dp[u[i][j]][u[i][kk]],w[i][kk]+w[i][j]);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int kk=1;kk<=n;kk++)
			{
				dp[j][kk]=min(dp[j][kk],dp[j][i]+dp[i][kk]);
			}
		}
	}
	for(int i=1;i<=q;i++)
	{
		int a,b;
		long long h=1e18;
		cin>>a>>b;
		for(int j=0;j<u[a].size();j++)
		{
			for(int kk=0;kk<u[b].size();kk++)
			{
				h=min(ww[a]+w[a][j]+w[b][kk]+ww[b]+dp[u[a][j]][u[b][kk]],h);
			}
		}
		cout<<h<<"\n";
	}
	return 0;
}
