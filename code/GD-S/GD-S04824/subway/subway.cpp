#include<bits/stdc++.h>
#define LL long long
using namespace std;
const LL INF=2e17;
int m,nn,ceshidian,n,ddd,Q;
LL useless[500005],dp[505][505];
vector<int> si[500005];
vector<LL> ti[500005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&ceshidian,&nn,&m,&ddd,&Q);
	for(int i=1;i<=m;i++) scanf("%lld",&useless[i]);
	for(int i=1;i<=nn;i++)
	{
		int gs;
		scanf("%d",&gs);
		for(int j=1;j<=gs;j++)
		{
			int x;
			LL y;
			scanf("%d%lld",&x,&y);
			si[x+nn].push_back(i);
			ti[x+nn].push_back(y);
		}
	}
	for(int i=0;i<505;i++)
	{
		for(int j=0;j<505;j++)
		{
			dp[i][j]=INF;
		}
		dp[i][i]=0;
	}
	for(int i=nn+1;i<=m+nn;i++)
	{
		for(int j=0;j<(int)si[i].size();j++)
		{
			for(int k=j+1;k<(int)si[i].size();k++)
			{
				int d1=si[i][j];
				int d2=si[i][k];
				dp[d1][d2]=dp[d2][d1]=min(dp[d1][d2],ti[i][j]+ti[i][k]);
			}
		}
	}
	for(int k=1;k<=nn;k++)
	{
		for(int i=1;i<=nn;i++)
		{
			for(int j=1;j<=nn;j++)
			{
				dp[i][j]=dp[j][i]=min(dp[i][k]+dp[k][j],dp[i][j]);
			}
		}
	}
	while(Q--)
	{
		int a1,a2;
		scanf("%d%d",&a1,&a2);
		LL ans=INF;
		a1+=nn,a2+=nn;
		for(int i=0;i<(int)si[a1].size();i++)
		{
			for(int j=0;j<(int)si[a2].size();j++)
			{
				ans=min(ans,ti[a1][i]+ti[a2][j]+dp[si[a1][i]][si[a2][j]]);
			}
		}
		ans+=useless[a1-nn]+useless[a2-nn];
		printf("%lld\n",ans);
	}
	return 0;
}
