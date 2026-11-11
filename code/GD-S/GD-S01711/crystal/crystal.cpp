#include <bits/stdc++.h>
using namespace std;

int n;
long long m;
long long a[500005], s[500005];

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];	
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
	
	int maxn = 1; 
	for (int i = 2; i <= n; i++)
	{
		int l = 1, r = i - 1, ans = 0;
		while (l <= r)
		{
			int mid = (l + r) / 2;
			long long cost = (i - mid) * a[i] - (s[i - 1] - s[mid - 1]);
			if (cost <= m) 
			{
				ans = i - mid + 1;
				r = mid - 1;
			}
			else l = mid + 1;
		}
		maxn = max(maxn, ans);
	}
	
	cout << maxn << endl;
	return 0;
}
