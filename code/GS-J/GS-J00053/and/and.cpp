#include <bits/stdc++.h>
using namespace std;
int n, m, a[200005], tot[200005], maxx = -1;
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	int q = m;
	for(int i = 1; i <= n; i++)
	{
	    for(int j = 1; j <= m; j++)
	    {
	    	tot[j] = a[i];
	   		tot[i] = (tot[i] & a[j]);
	    }
	}
	for(int i = 1; i <= n; i++)
	{
		if(tot[i] > maxx)
		{
			maxx = tot[i];
		}
	}
	cout << maxx;
	return 0;
}
