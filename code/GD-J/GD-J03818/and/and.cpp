#include <bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	for (int i = 1;i <= n;i++)
	{
		int b[m + 5];
		for (int j = 1;j <= m;j++)
		{
			b[j] = a[i + j];
		}
		int c = b[1];
		for (int j = 1;j <= m + 1;j++)
		{
			c = c & b[j + 1];
		}
		if (i == 1)
		{
			ans = c;
			continue;
		}
		if (c > ans) ans = c;
	}
	cout << ans;
	return 0;	
}
