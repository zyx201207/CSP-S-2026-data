#include <bits/stdc++.h>
using namespace std;
int w;
bool cmp(int a, int b)
{
	return (a & (1 << w)) > (b & (1 << w));
}
int n, m;
int a[200005];
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	int ans = 0;
	int l = n;
	for(int i = 30; i >= 0; i--)
	{
		w = i;
		sort(a + 1, a + l + 1, cmp);
		if((a[m] & (1 << w)) == 0)
		{
			continue;
		}
		ans += (1 << w);
		int id = 1;
		while(id <= l && (a[id] & (1 << w)) != 0)
		{
			id++;
		}
		l = id - 1;
	}
	cout << ans;
	return 0;
}
