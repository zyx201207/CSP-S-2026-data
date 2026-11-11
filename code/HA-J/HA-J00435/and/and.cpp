#include <bits/stdc++.h>

using namespace std;
int a[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,p = 0;
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
		p = max(p,a[i]);
	}
	int k = a[1];
	if (n == m)
	{
		for(int i = 1;i <= n;i++)
		{
			k = k & a[i];
		}
		cout << k;
		return 0;
	}
	if(m == 1)
	{
		cout << p;
		return 0;
	}
		int _m = 0;
	for (int i = 1;i < n;i++)
	{
		for (int j = i + 1;j <= n;j++)
		{
			_m = max(_m,a[i] & a[j]);
		}
	}
	cout << _m;
}
