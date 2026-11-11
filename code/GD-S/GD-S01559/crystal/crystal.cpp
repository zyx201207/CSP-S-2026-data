#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5 * 1e5 + 10;
int n,m,a[N],b[N];
vector <int> sum[N];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++) cin >> a[i];
	sort(a + 1,a + n + 1);
	int ans = 0;
	for (int i = n;i >= 1;i--)
	{
		if (i != n)
		{
			sum[i].push_back(sum[i + 1][sum[i + 1].size() - 1] - (i - n + b[i + 1] + 1) * (a[i + 1] - a[i]));
			b[i] = b[i + 1];
		}
		else sum[i].push_back(0);
		for (int j = (n == i ? i - 1 : n - b[i + 1] - 1);j >= 1;j--)
		{
			sum[i].push_back(sum[i][sum[i].size() - 1] + (a[i] - a[j]));
			b[i]++;
			if (sum[i][sum[i].size() - 1] > m || j == 1) 
			{
				if (j == 1 && sum[i][sum[i].size() - 1] <= m) 
				{
					ans = max(ans,i - j + 1);
					cout << ans;
					return 0;
				}
				else ans = max(ans,i - j);
				break;
			} 
		}
	}
	cout << ans;
	return 0;
}

