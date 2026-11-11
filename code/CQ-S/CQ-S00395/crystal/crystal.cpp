#include<bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;

set<int> s;

long long a, b, c, d, e, f, g[N], p, sum, cnt;

bool vis, vis1;

bool cmp(int x, int y)
{
	return x > y;
}

signed main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin >> a >> b;
	for(int i = 1; i <= a; i ++)
	{
		cin >> g[i];
		if(g[i] != i) vis = 1;
		s.insert(g[i]);
	}
	for(int i = 2; i < a; i ++)
	{
		if(g[i] - g[i - 1] != g[i + 1] - g[i]) vis1 = 1;
	}
	if(vis == 0)
	{
		for(int i = 1; i <= a; i ++)
		{
			sum += i;
			cnt ++;
			if(sum > b)
			{
				break;
			}
		}
		cout << cnt;
		return 0;
	}
	if(vis1 == 0)
	{
		long long k = g[2] - g[1];
		for(int i = k; i <= b; i += k)
		{
			sum += i;
			cnt ++;
			if(sum > b)
			{
				break;
			}
		}
		cout << cnt;
		return 0;
	}
	sort(g + 1, g + a + 1, cmp);
	for(int k : s)
	{
		long long sum = 0, ans = 0;
		for(int i = 1; i <= a; i ++)
		{
			if(g[i] <= k)
			{
				sum += k - g[i];
				ans ++;
			}
			if(sum > b)
			{
				ans --;
				break;
			}
		}
		p = max(p, ans);
	}
	cout << p;
	return 0;
}

