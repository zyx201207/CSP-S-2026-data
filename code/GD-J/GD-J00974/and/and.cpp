#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 5;
int n, m, f[N], a[N], vis[N], p, mn[N], sum;
void dp(int x)
{
	if(x == m + 1)
	{
		return ;
	}
	for(int i = 1;i <= n;i ++)
	{
		if(vis[i] == 1)
		{
			continue;
		}
		if(f[x] < (f[x - 1] & a[i]))
		{
//			cout << (f[x - 1] & a[i]) << ' ';
			int t = f[x];
			f[x] = (f[x - 1] & a[i]);
			mn[x] = max(f[x], mn[x]);
			vis[i] = 1;
			dp(x + 1);
			f[x] = t;
			vis[i] = 0; 
		}
		else
		{
			dp(x + 1);
		}
	}
}
signed main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	sum = pow(2, 31) - 1;
	for(int i = 1;i <= n;i ++)
	{
		cin >> a[i];
		sum &= a[i];
	}
	if(n == m)
	{
		cout << sum << '\n';
		return 0;
	}
	f[0] = pow(2, 31) - 1;
	dp(1);
	cout << mn[m] << '\n'; 
	return 0;
}

