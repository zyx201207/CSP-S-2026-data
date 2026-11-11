#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,i,j,h;
long long w[500005],t[500005][500005],x,y,k,dp[500005][500005],r[500005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(i=1;i<=m;i++)cin>>w[i];
	for(i=1;i<m;i++)
	for(j=2;j<=m;j++)dp[i][j]=dp[j][i]=0x7fffffff;
	for(i=1;i<=n;i++)
	{
		cin>>k;
		for(j=1;j<=k;j++)
		{
			cin>>r[j];
			cin>>t[i][r[j]];
			for(h=1;h<=j;h++)
			if(r[h]!=r[j])dp[r[h]][r[j]]=dp[r[j]][r[h]]=(t[r[h]][i]+t[i][r[h]]);
		}
	}
	for(i=1;i<m;i++)
	for(j=2;j<=m;j++)
	for(h=1;h<=m;h++)
	if(dp[i][j]>dp[i][h]+dp[h][j])dp[i][j]=dp[j][i]=dp[i][h]+dp[h][j];
	for(i=1;i<=q;i++)
	{
		cin>>x>>y;
		cout<<dp[x][y]+w[x]+w[y]<<endl;
	}
return 0;
}
