#include <bits/stdc++.h>
using namespace std;
const int maxn=2e4+5;
int c,n,m,d,q,w[maxn],k[maxn],a[505][maxn],t[505][maxn],dp[maxn][maxn];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[i][j]>>t[i][j];
			for(int h=1;h<j;h++) dp[a[i][h]][a[i][j]]=dp[a[i][j]][a[i][h]]=t[i][j]+t[i][h];
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=m;j++)
		{
			for(int h=1;h<=m;h++)
			{
				if(dp[i][h]!=0&&dp[h][j]!=0)
				{
					if(dp[i][j]!=0) dp[i][j]=min(dp[i][j],dp[i][h]+dp[h][j]);
					else dp[i][j]=dp[i][h]+dp[h][j];
				}
			}
		}
	}
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		cout<<dp[x][y]+w[x]+w[y]<<endl;
	}
	return 0;
}
