#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2e6 + 5;
int x[N],f[N],dp[N],n,d,c,t;

bool checkA()
{
	int diff = x[2] - x[1];
	for(int i = 2;i <= n;i++)
		if(x[i] - x[i - 1] != diff) return 0;
	return 1;
}

void solve()
{
	scanf("%lld%lld",&n,&d);
	for(int i = 1;i <= n;i++) scanf("%lld",&x[i]);
	int ans = 0;
	if(c == 11 || c == 12)
	{
		int diff = x[2] - x[1];
		int maxn = d / diff;
		if(maxn >= 2)
		{
			cout << max(0ll,n - (2 * maxn - 1)) << '\n';
		}
		else cout << 0 << '\n';
		return ;
	}
	else if(c == 13 || c == 14)
	{
		if(abs(x[n] - x[1]) <= d)
		{
			cout << 0 << '\n';
		}
		int p;
		for(int i = 2;i < n;i++)
			if(abs(x[i] - x[1]) <= d && abs(x[i] - x[n]) <= d) p = i;
		int cnt1 = 0,cnt2 = 0;
		for(int i = 1;i < p;i++)
			if(x[p + 1] - x[i] <= d) cnt1++;
		for(int i = p + 1;i <= n;i++)
			if(x[i] - x[p - 1] > d) cnt2++;
		ans = cnt1 * cnt2;
		cnt1 = 0,cnt2 = 0;
		for(int i = 1;i < p;i++)
			if(x[p + 1] - x[i] > d) cnt1++;
		for(int i = p + 1;i <= n;i++)
			if(x[i] - x[p - 1] <= d) cnt2++;
		ans += cnt1 * cnt2;
		cout << ans << '\n';
	}
	else
	{
		for(int i = 1;i <= n;i++)
		{
			for(int j = 1;j <= n;j++) f[j] = 0,dp[j] = 1e9;
			dp[i] = 0;
			f[i] = 1;
			for(int j = i + 1;j <= n;j++)
				for(int k = j - 1;k >= i;k--)
				{
					if(abs(x[j] - x[k]) <= d)
					{
						if(dp[k] + 1 < dp[j])
						{
							dp[j] = dp[k] + 1;
							f[j] = f[k];
						}
						else if(dp[k] + 1 == dp[j])
						{
							f[j] += f[k];
							if(f[j] > 2) f[j] = 3;
						} 
					}
					else break;
				}
			for(int j = i + 1;j <= n;j++)
				if(f[j] == 2) ans++;
		}
		cout << ans << endl;
	}
}

signed main() 
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--)	solve();
	return 0;
}
