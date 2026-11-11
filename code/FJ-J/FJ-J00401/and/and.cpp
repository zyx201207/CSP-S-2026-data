#include <bits/stdc++.h>
using namespace std;
const int N=2*1e5+10;
int n,m;
int a[N];
int dp[N];
int sum[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		dp[i]=a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=n;j>=m;j--)
		{
			dp[i]=max(dp[i],dp[i-j]&a[i]);
		}
		//printf("%d ",dp[i]);
	}
	printf("%d",dp[n]);
	return 0;
}
