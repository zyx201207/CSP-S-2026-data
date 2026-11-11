#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N = 5e5 + 10;
int n, m, a[N], dif[N], pre[N], sum[N];
bool isA = true, isB = true;
signed main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++)
	{
		dif[i] = a[i] - a[i - 1];
		pre[i] = pre[i - 1] + dif[i];
		if(a[i] != i) isA = false;
		if(i >= 3 && a[i] - a[i - 1] != a[i - 1] - a[i - 2]) isB = false;
	}
	if(isA)
	{
		for(int i = 1; i <= n; i++)
		{
			if(i * (i - 1) / 2 > m)
			{
				cout << i - 1;
				return 0;
			}
		}
		cout << n;
		return 0;
	}
	else if(isB)
	{
		int g = a[2] - a[1];
		for(int i = 1; i <= n; i++)
		{
			if((g + g * (i - 1)) * (i - 1) / 2 > m)
			{
				cout << i - 1;
				return 0;
			}
		}
		cout << n;
		return 0;
	}
	else
	{
		int tot = 0;
		for(int i = 1; i <= n; i++) tot += pre[n] - pre[i], sum[i] = sum[i - 1] + pre[i];
		if(tot <= m)
		{
			cout << n;
			return 0;
		}
		for(int i = 1; i <= n; i++)
		{
			if(pre[i] * i - sum[i] > m)
			{
				cout << i - 1;
				return 0;
			}
		}
		cout << n;
	}
	return 0;
}
