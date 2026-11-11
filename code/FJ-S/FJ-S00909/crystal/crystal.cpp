#include<bits/stdc++.h>
using namespace std;
int n,ans=0;
long long a[500005],dp[500005],m;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int last=1;
	dp[1]=0;
	for(int i=2;i<=n;i++)
	{
		dp[i]=(a[i]-a[i-1])*(i-last)+dp[i-1];
		while(dp[i]>m)
		{
			dp[i]-=a[i]-a[last];
			last++;
		}
		ans=max(ans,(i-last+1));
	}
	cout<<ans;
	return 0;
}
