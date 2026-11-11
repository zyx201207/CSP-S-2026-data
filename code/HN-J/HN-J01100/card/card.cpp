#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[300005],cnt[300005];
bool f = 1;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
		if (a[i] < a[i - 1]) f = 0;
	}
	for (int i = 1;i <= n;i++) b[a[i]] = i;
	if (f)
	{
		for (int i = 1;i <= m;i++) cout << b[a[i]] << ' ';
		return 0;
	}
	for (int i = 1;i <= n;i++)
	{
		for (int j = i;j <= n;j++)
		{
			++cnt[a[j]];
			if (b[a[j]] != j)
			{
				for (int k = b[a[j]] + 1;k <= n;k++)
				{
					++cnt[a[k]];
					if (b[a[k]] != k) k = b[a[k]];
				}
				break;
			}
		}
	}
	for (int i = 1;i <= m;i++) cout << cnt[i] << ' ';
	return 0;
}
