#include <bits/stdc++.h>
using namespace std;
int n,m,a[200005],maxx;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	if (m == 2)
	{
		for (int i = 1;i <= n;i++)
		{
			for (int j = i + 1;j <= n;j++)
			{
				maxx = max(maxx,a[i] & a[j]);
			}
		}
		cout << maxx;
		return 0;
	}
	sort(a + 1,a + n + 1);
	maxx = a[n];
	for (int i = n - 1;i >= n - m  + 1;i--)
	{
		maxx = maxx & a[i];
	}
	cout << maxx;
	return 0;
}
