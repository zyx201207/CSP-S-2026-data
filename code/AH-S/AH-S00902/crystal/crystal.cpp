
#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 5e5+1;
int n, ans;
ll m, a[N], he[N];

bool check (int x)
{
	for (int l = 1; l <= n-x+1; l++)
	{
		int r = l+x-1;
		ll sum = a[r] * x - (he[r] - he[l-1]);
		if (sum <= m)
			return true;
	}
	return false;
}

int main()
{
	freopen ("crystal.in", "r", stdin);
	freopen ("crystal.out", "w", stdout);
	
	ios::sync_with_stdio (false);
	cin.tie (nullptr), cout.tie (nullptr);
	
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort (a+1, a+n+1);
	for (int i = 1; i <= n; i++)
		he[i] = he[i-1] + a[i];
			
	int l = 1, r = n, mid = 0;
	
	while (l <= r)
	{
		mid = l + ((r-l)>>1);
		if (check (mid))
			l = mid+1,
			ans = max (ans, mid);
		else
			r = mid-1;
	}
	
	cout << ans;
	
	return 0;
}
