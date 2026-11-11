#include <bits/stdc++.h>
using namespace std;
int n, m, a[200005];
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	if(m == 1)
	{
		int maxx = 0;
		for(int i = 1; i <= n; i++)
			maxx = max(maxx, a[i]);
		cout << maxx;
	}
	if(m == 2)
	{
		int maxx = 0;
		for(int i = 1; i <= n; i++)
			for(int j = i + 1; j <= n; j++)
				maxx = max(maxx, (a[i] & a[j]));
		cout << maxx;
	}
	if(m == 3)
	{
		int maxx = 0;
		for(int k = 1; k <= m; k++)
			for(int i = k + 1; i <= n; i++)
				for(int j = i + 1; j <= n; j++)
					maxx = max(maxx, (a[i] & a[j]) & a[k]);
		cout << maxx;
	}
	return 0;
}
