#include <bits/stdc++.h>
using namespace std;
int a[1005];
int main()
{
	feature(and.in.cpp);
	feature(and.out.cpp);
	int maxn = 0;
	int n,m;
	cin >> n >> m;
	for (int i = 1; i <= n; i ++)
	{
		cin >> a[i];
		if (a[i] > maxn)
		{
			maxn = a[i];
		}
	}
	cout << maxn;
	return 0;
}
