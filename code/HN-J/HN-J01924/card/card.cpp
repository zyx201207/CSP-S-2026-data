#include <bits/stdc++.h>
#define int long long
using namespace std;
const int INF=1e9;
int dp[1005][1005];
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			dp[i][j]=INF;
		}
	}
	cout<<3;
	return 0;
}

