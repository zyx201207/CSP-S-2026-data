#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c,t;
int n;ll m;
ll a[2000010];
int p[2000010];
ll dp[2000010][2][2];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--)
	{
		scanf("%d%lld",&n,&m);
		for(register int i=1;i<=n;i++) scanf("%lld",&a[i]);
		for(register int i=1;i<=n;i++)
		{
			p[i]=p[i-1];
			while(p[i]+1<=n)
			{
				if(a[p[i]+1]-a[i]<=m) p[i]++;
				else break;
			}
		}
		for(register int i=n;i>=2;i--)
		{
			if(p[i]==i) continue;
			for(register int cnt=0;cnt<=1;cnt++)
				for(register int op=0;op<=1;op++)
				{
					ll S=0;
					if(cnt==1) S+=p[i]-max(p[i-1],i);
					if((!cnt)&&(p[i-1]>=i-1)&&(!op)) S+=p[i-1]-max(p[i-2],i);
					dp[i][cnt][op]+=S;
					
					int x=cnt;
					
					if(p[i]==p[i-1])
					{
						cnt++;
						if(p[i-2]==p[i]) cnt++;
						if(op) cnt++;
					}
					if(cnt<=1) dp[i][x][op]+=dp[p[i]][cnt][(p[i-1]>=p[i]-1)];
				}
		}
		ll ans=0;
		for(register int i=1;i<=n;i++) if(p[i]!=i) ans+=dp[p[i]][0][0];
		printf("%lld\n",ans);
		for(register int i=1;i<=n;i++) p[i]=0,dp[i][0][0]=dp[i][0][1]=dp[i][1][0]=dp[i][1][1]=0;
	}
	return 0;
}
/*
0 1
14 5
0 1 4 6 7 8 9 11 15 16 17 22 23 28
*/
