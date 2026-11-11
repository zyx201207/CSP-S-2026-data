#include <bits/stdc++.h>
using namespace std;

int c,t;
int n;
long long d,a[2000005],dp[2000005],dp2[2000005],fr[2000005],af[2000005];
long long sum[2000005],sum2[2000005];

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> t;
	while(t > 0)
	{
		t--;
		cin >> n >> d;
		if(n <= 5000)
		{
			for(int i = 1;i <= n;i++)
			{
				cin >> a[i];
			}
			long long ans = 0;
			for(int i = 1;i <= n;i++)
			{
				bool f = false;
				for(int j = i;j <= n;)
				{
					if(f) ans++;
//					cout << i << '|' << j << ' ' << ans << '\n';
					int l = 0,r = n - j + 2;
					while(l + 1 < r)
					{
						int mid = (l + r) / 2;
						if(a[i + mid] - a[i] <= d) l = mid;
						else r = mid;
					}
					if(l == 0) break;
//					cout << l << '\n';
					if(l == 2)
					{
						if(a[j + 3] - a[j + 2] <= d&&a[j + 3] - a[j + 1] <= d)
						{
							j += 3;
							if(f) break;
							f = true;
						}
						else j += l;
					}
					else j += l;
				}
			}
			cout << ans << '\n';
		}
		else
		{
			for(int i = 1;i <= n;i++)
			{
				cin >> a[i];
				dp[i] = dp2[i] = 0;
			}
			for(int i = 1;i <= n;i++)
			{
				dp[i] += 1;
				int l = 0,r = n - i + 2;
				while(l + 1 < r)
				{
					int mid = (l + r) / 2;
	//				cout << l << ' ' << r << "|" << i + mid - 1 << ' ' << i << '\n';
					if(a[i + mid - 1] - a[i] <= d) l = mid;
					else r = mid;
				}
				if(l > 1) dp[i + l - 1] += dp[i];
	//			cout << i << "^" << i + l - 1 << '\n';
			}
			for(int i = n;i >= 1;i--)
			{
				dp2[i] += 1;
				int l = 0,r = i + 1;
				while(l + 1 < r)
				{
					int mid = (l + r) / 2;
					if(a[i] - a[i - mid + 1] <= d) l = mid;
					else r = mid;
				}
				if(l > 1) dp2[i - l + 1] += dp2[i];
			}
			int la = 1;
			long long ans = 0;
			for(int i = 1;i <= n;i++)
			{
				while(a[i] - a[la] > d) la++;
				if(i - la == 2)
				{
					if(a[la - 1] + d >= a[la])
					{
						ans += dp[la - 1] * dp2[i];
					}
				}
			}
			cout << ans << '\n';
		}
	}
	return 0;
}
