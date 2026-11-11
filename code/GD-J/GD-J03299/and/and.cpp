#include <bits/stdc++.h>
using namespace std;
int n, m, maxn = -1, num;
int a[200005], b[200005];
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int i = 1; i <= n; i++)
	{
		for(int j = i; j <= n; j++)
		{
			b[i] = a[i] and a[j];
		}
	}
	while(true)
	{
		num++;
		if(maxn < b[num])
			maxn = b[num];
		if(b[num] < 0)
			break;
	}
	cout << maxn;
	return 0;
}
