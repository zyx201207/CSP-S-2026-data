#include<bits/stdc++.h>
using namespace std;
const int M=5e5+2;
int c,n,m,d,q;
int w[M];
int t[502][M],mid[505][505];
long long dp[505][505];
vector<int> vc[M];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)
		scanf("%d",&w[i]);
	memset(dp,0x3f,sizeof(dp));
	for(int i=1;i<=n;i++)
		dp[i][i]=0;
	for(int i=1;i<=n;i++)
	{
		int k,a,b;
		scanf("%d",&k);
		for(int j=1;j<=k;j++)
		{
			scanf("%d%d",&a,&b);
			t[i][a]=b;
			for(int l=0;l<vc[a].size();l++)
			{
				int y=vc[a][l];
				if(1ll*(b+t[y][a])<dp[y][i])
				{
					dp[i][y]=dp[y][i]=min(dp[y][i],1ll*(b+t[y][a]));
					mid[i][y]=mid[y][i]=a;
				}
			}
			vc[a].push_back(i);
		}
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
	while(q--)
	{
		int sa,ta;
		long long ans=dp[0][0];
		scanf("%d%d",&sa,&ta);
		for(int i=0;i<vc[sa].size();i++)
			for(int j=0;j<vc[ta].size();j++)
				ans=min(dp[vc[sa][i]][vc[ta][j]]+1ll*t[vc[sa][i]][sa]+1ll*t[vc[ta][j]][ta],ans);
		printf("%lld\n",ans+1ll*w[sa]+1ll*w[ta]);
	}
	return 0;
}
