#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, m, a[N], maxx, cnt0;
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		if(a[i] == 0)
		{
			cnt0++;
		}
	}
	if(cnt0 > abs(n - m))
	{
		cout << 0;
		return 0;
	}
	if(m == 1)
	{
		for(int i = 1;i <= n;i++)
		{
			maxx = max(a[i], maxx);
		}
		cout << maxx;
		return 0;
	}else if(m == n)
	{
		int tmp = a[1];
		for(int i = 2;i <= n;i++)
		{
			tmp = tmp & a[i];
		}
		cout << tmp;
		return 0;
	}
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j < i;j++)
		{
			maxx = max(a[i] & a[j], maxx);
		}
	}
	cout << maxx;
	return 0;
}
