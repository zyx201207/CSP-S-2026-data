#include<bits/stdc++.h>
using namespace std;
#define int long long
map<int,int>opt[5000005];
int a[500005],w[500005][25],s[5000005],f[500005][25],dp[505][505];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int x,y;
			cin>>x>>y;
			f[x][0]++;
			f[x][f[x][0]]=i;
			s[x]++;
			opt[x][i]=s[x];
			w[x][s[x]]=y;
		}
	}
	memset(dp,0x3f3f3f,sizeof(dp));
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=f[i][0];j++)
		{
			for(int k=j+1;k<=f[i][0];k++)
			{
				dp[f[i][j]][f[i][k]]=min(w[i][opt[i][f[i][j]]]+w[i][opt[i][f[i][k]]],dp[f[i][j]][f[i][k]]);
				dp[f[i][k]][f[i][j]]=dp[f[i][j]][f[i][k]];
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=n;k++)
			{
				if(i!=j&&j!=k&&i!=k)
				{
					dp[i][j]=min(dp[i][k]+dp[k][j],dp[i][j]);
					dp[j][i]=dp[i][j];
				}
			}
		}	
	}
	for(int i=1;i<=n;i++)
		dp[i][i]=0;
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		int ans=1e18;
		for(int i=1;i<=f[x][0];i++)
			for(int j=1;j<=f[y][0];j++)
				ans=min(dp[f[x][i]][f[y][j]]+w[x][opt[x][f[x][i]]]+w[y][opt[y][f[y][j]]],ans);
		cout<<ans+a[x]+a[y]<<endl;
	}
	return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
