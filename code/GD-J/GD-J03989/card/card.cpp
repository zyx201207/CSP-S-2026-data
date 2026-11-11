#include <bits/stdc++.h>
using namespace std;
int n, m, a[500005], cnt[300005];
long long ans[300005];
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.in", "r", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int i = 1; i <= n; i++)
	{
		memset(cnt, 0, sizeof(cnt));
		for(int j = i; j <= n; j++)
			cnt[a[j]]++;
		for(int j = i; j <= n; j++)
		{
			if(cnt[a[j]] == 0)
			{
				bool flag = 1;
				for(int s = i; s <= j; s++)
					if(cnt[a[s]] >= 1)
					{
						flag = 0;
						for(int k = i; k <= s; k++)
							cnt[a[k]] = 0;
						break;
					}
				if(flag)
					ans[i]++;
			}
		}
	}
	for(int i = 1; i <= m; i++)
		cout << ans[i] << ' ';
	return 0;
}
