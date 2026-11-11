#include <bits/stdc++.h>
using namespace std;
int n, v, u, sum, mid, ans;
char a[200005];
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) 
	{
		cin >> v >> u;
		//cout << v << endl;
		for (int i = sum; i <= v + sum; i++)
		{
			a[i] = u;
		}
		sum += v;
		//cout << sum << endl; 
	}
	mid = sum / 2;
	for (int i = 1; i <= mid; i++)
	{
		if (a[i] != a[sum - i + 1])
		{
			ans++;
		}
	}
	cout << ans;
	return 0;
}
