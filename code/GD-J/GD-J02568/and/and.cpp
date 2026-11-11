#include <bits/stdc++.h>
using namespace std;

const int N = 200010;

int n,m;
int a[N],pre[N],suf[N];
int dp[N];

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for (int i = 1;i <= n;i++) cin>>a[i];
	if (m == 1){
		int ans = 0;
		for (int i = 1;i <= n;i++) ans = max(ans,a[i]);
		cout<<ans;
		return 0;
	}
	if (m == 2){
		int ans = 0;
		for (int i = 1;i <= n;i++)
		{
			for (int j = i + 1;j <= n;j++)
			{
				ans = max(ans,a[i] & a[j]);
			}
		}
		cout<<ans;
		return 0;
	}
	if (m == n - 1){
		pre[1] = a[1];
		for (int i = 2;i <= n;i++) pre[i] = pre[i - 1] & a[i];
		suf[n] = a[n];
		for (int i = n - 1;i >= 1;i--) suf[i] = suf[i + 1] & a[i];
		int ans = max(pre[n - 1],suf[1]);
		for (int i = 2;i < n;i++)
		{
			int ret = pre[i - 1] & suf[i + 1];
			ans = max(ans,ret);
		}
		cout<<ans;
		return 0;
	}
	dp[1] = a[1];
	for (int i = 2;i <= n;i++)
	{
		for (int j = min(m,i);j >= 1;j--)
		{
			if (j == 1) dp[j] = max(dp[j],a[i]);
			else dp[j] = max(dp[j],dp[j - 1] & a[i]);
		}
	}
	cout<<dp[m];
	return 0;
}
