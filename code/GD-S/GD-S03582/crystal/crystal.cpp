#include <bits/stdc++.h>
using namespace std;
int n,ans;
long long m,pre[500003],a[500003];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for(int i = 1;i <= n;i++)
	{
		pre[i] = pre[i - 1] + a[i];
	}
	ans = 1;
	for(int i = 1;i <= n;i++)
	{
		for(int j = i + ans;j <= n;j++)
		{
			int x = j - i + 1;
			if((a[j] * x) - (pre[j] - pre[i - 1]) <= m)
			{
				ans = max(ans,x);
			}
			else
			{
				break;
			}
		}
	}
	cout << ans;
	return 0;
}
