#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 50;
const int inf = 1e18;
int n, m, a[N], p[N], sum[N];
bool check(int x)
{
	int tmp = inf;
	for(int i = x - 1; i >= 1; i--)
	{
		p[1] += sum[x] - sum[i];
	}
	for(int i = 2; i <= n - x + 1; i++)
	{
		p[i] = p[i - 1] + (x - 1) * abs(a[i + x - 2] - a[i + x - 1]) - abs(sum[i + x - 2] - sum[i - 1]);
	}
	for(int i = 1; i <= n - x + 1; i++)
	{
		tmp = min(tmp, p[i]);
	}
	for(int i = 1; i <= n - x + 1; i++)
	{
		p[i] = 0;
	}
	if(tmp <= m)
	{
		return 1;
	}
	else{
		return 0;
	}
}
signed main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for(int i = 2; i <= n; i++)
	{
		sum[i] = sum[i - 1] + abs(a[i] - a[i - 1]);
	} 
	int l = 1, r = n + 1;
	while(l + 1 < r)
	{
		int mid = (l + r) / 2;
		if(check(mid))
		{
			l = mid;
		}
		else{
			r = mid;
		}
	}
	cout << l;
	return 0;
}
