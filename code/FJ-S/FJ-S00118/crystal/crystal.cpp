#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,mmax,ans;
int a[N],dp[N];
void init()
{
	cin>>n>>m;
	for(int i=1; i<=n; i++)
		cin>>a[i];
	sort(a+1,a+1+n);
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	init();
	dp[1]=0;
	mmax=a[1];
	for(int i=2; i<=n; i++)
	{
		if(a[i] > mmax)
		{
			dp[i]=dp[i-1]+(i-1)*(a[i]-mmax);
			mmax=a[i];
		}
		else
			dp[i]=dp[i-1];
	}
	for(int i=1; i<=n; i++)
	{
		if(dp[i] <= m)
			ans=max(ans,i);
	}
	cout<<ans;
	return 0;
}	
