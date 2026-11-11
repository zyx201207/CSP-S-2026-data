#include <bits/stdc++.h>
using namespace std;
#define long long int
const int N = 5e5 + 5;
int n, m, a[N], cost[N], b[N],t;
int ans;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	priority_queue<pair<int, int>> q;//cost,energy
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	bool flag = 1,flag1 = 1;
	for(int i = 1; i <= n; i++)
	{
		if(a[i] != i) flag = 0;
	}
	for(int i = 2; i <= n - 1; i++)
	{
		if(a[i + 1] - a[i] != a[i] - a[i - 1]) flag1 = 0;
	}
	if(flag)
	{
		while(t <= m)
		{
			ans++;
			t += ans;
		}
		cout << min(ans, n);
		return 0;
	}
	if(flag1)
	{
		int d = a[2] - a[1];
		while(t <= m)
		{
			ans++;
			t += ans * d;
		}
		cout << min(ans, n);
		return 0;
	}
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++)
	{
		b[i] = a[i];
	}
	unique(b + 1, b + n + 1);
	for(int i = n; i >= 1; i--)
	{
		if(b[i] != 0) break;
		t++;
	}
	t = n - t;
	int g = b[t % 2 == 0 ? t / 2 : t / 2 + 1];
	for(int i = 1; i <= n; i++)
	{
		cost[i] = abs(a[i] - g);
	}
	for(int i = 1; i <= n && a[i] <= g; i++)
	{
		while(m < cost[i])
		{
			auto[c, p] = q.top();
			q.pop();
			ans--;
			m += c;
		}
		if(m - cost[i] >= 0)
		{
			q.push({cost[i], a[i]});
			m -= cost[i];
			ans++;
		}
	}
	cout << ans;
}
