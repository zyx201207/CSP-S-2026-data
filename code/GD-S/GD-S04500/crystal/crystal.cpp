#include <bits/stdc++.h>
using namespace std;
int n;
long long m,cr[5005];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

	cin >> n >> m;
	for (int i = 1;i <= n;i++) cin >> cr[i];
	sort(cr + 1,cr + n + 1);
	if (n <= 5000)
	{
		int ans = 0;
		for (int i = 1;i <= n;i++)
		{
			for (int j = 1;j <= i;j++)
			{
				int res = 0;
				for (int k = j;k <= i;k++) res += cr[i] - cr[k];
				if (res <= m)
				{
					ans = max(ans,i - j + 1);
					break;
				}
			}
		}
		cout << ans;
	}
	else
	{
		bool b = 1;
		int d = cr[2] - cr[1];
		for (int i = 1;i <= n;i++)
		{
			if (d * (i - 1) * i / 2 > m)
			{
				cout << i - 1;
				b = 0;
				break;
			}
		}
		if (b) cout << n;
	}
	
	return 0;
}
