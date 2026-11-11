#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m, a[200005];
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	sort(a+1, a+n+1);
	int maxans = -1;
	for (int i = n-m+1;i <= n;i++)
	{
		int x = a[i];
		for (int j = i+1;j <=i+m-1;j++)
		{
			x=x&a[j];
		}
		if(x>maxans)
		{
			maxans = x;
		}
	}
	cout << maxans;
	return 0;
}
