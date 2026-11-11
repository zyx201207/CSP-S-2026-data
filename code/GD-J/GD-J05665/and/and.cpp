#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int main()
{
    freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    int n,m;
    long long a[N],ds=-1,dp[N][N],h;
    scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]),ds=max(ds,a[i]);
		if(i==1) h=a[i];
		h=(h&a[i]);
	}
	if(m==1) {printf("%lld",ds);return 0;}
	if(m==n) {printf("%lld",h);return 0;}
    dp[1][1]=a[1],dp[1][0]=0;
    for(int i=1;i<=n;i++)
    {
    	for(int j=1;j<=m;j++)
    	{
    		dp[i][j]=max(dp[i-1][j],dp[i-1][j-1]&a[j]);
		}
	}
	printf("%lld",&dp[n][m]);
	return 0;
}
