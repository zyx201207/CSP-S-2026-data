#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 5e5 + 5;

int n; ll m, a[MAXN], prea[MAXN];

bool cmp(ll x, ll y)
{
	return x > y;
}

int main()
{
	freopen("crystal.in", "r", stdin); freopen("crystal.out", "w", stdout);
	
	cin >> n >> m;
	
	for (int i = 1; i <= n; i ++) cin >> a[i];
	
	sort(a + 1, a + n + 1, cmp);
	
	for (int i = 1; i <= n; i ++) prea[i] = prea[i - 1] + a[i];
	
	int ans = 0;
	
	for (int i = 1; i <= n; i ++)
	{
		int l = i, r = n;
		
		while (l <= r)
		{
			int mid = (l + r) / 2;
			
			if (a[i] * (mid - i) - prea[mid] + prea[i] <= m)
			{
				ans = max(ans, mid - i + 1); l = mid + 1;
			}
			else
			{
				r = mid - 1;
			}
		}
	}
	
	cout << ans;
	
	return 0;
}
