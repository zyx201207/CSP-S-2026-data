#include <bits/stdc++.h>
using namespace std;
int n, m, a[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	int maxn = -1000;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		maxn = max(maxn, a[i]);
	}
	cout << maxn;
}
