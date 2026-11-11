#include<bits/stdc++.h>

using namespace std;

const int N = 2e4+500;
int dp[N][N]={};
long long a[27]={};

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	string s;
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		int k; char t;
		cin >> k >> t;
		for (int i = 1;i <= k;i++)
		s += t;
	}
	int len = s.size();
	for (int i = 0;i < len;i++) if (s[len-1] != s[i]) dp[len-1][i] = 1;
	for (int i = 0;i < len;i++) if (s[0] != s[i]) dp[i][0] = 1;
	for (int l = len-2;l >= 0;l--)
	{
		for (int r = l;r < len;r++)
		{
			if (s[l] != s[r]) 
			{
				dp[l][r] = min(dp[l+1][r]+1,min(dp[l][r-1]+1,dp[l+1][r-1]+1));
			}
			else dp[l][r] = dp[l+1][r-1];
		}
	}
	cout << dp[0][len-1];
	return 0;
}
