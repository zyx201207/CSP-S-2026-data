#include <bits/stdc++.h>
#define int long long
using namespace std;
struct node 
{
	int cnt , k , w , b[35];
}a[200005];
int n , m;
int last_1 (int x)
{
	return (~x + 1) & x;
}
int cmp (node x , node y)
{
	for (int i = 30;i >= 1;i --)
	{
		if (x.b[i] != y.b[i])
		{
			return x.b[i] > y.b[i];
		}
	}
	return x.cnt > y.cnt;
}
signed main ()
{

	freopen ("and.in" , "r" , stdin);
	freopen ("and.out" , "w" , stdout);
	ios::sync_with_stdio (NULL);
	cin.tie (0);
	cout.tie (0);
	cin >> n >> m;
	for (int i = 1;i <= n;i ++)
	{
		cin >> a[i].k;
		int x = a[i].k;
		while (x > 0)
		{
			a[i].cnt ++;
			a[i].w = last_1 (x);
			a[i].b[(int) log2 (last_1 (x))] = 1;
			x -= last_1 (x);
		}
	}
	sort (a + 1 , a + n + 1 , cmp);
	int ans = 0;
	for (int i = 30;i >= 1;i --)
	{
		int t = 0;
		ans = 0;
		for (int j = 1;j <= n;j ++)
		{
			if (a[j].b[i] > 0)
			{
				if (ans == 0)
				{
					ans = a[j].k;
				}
				else
				{
					ans &= a[j].k;
				}
				t ++;
				if (t == m)
				{
					cout << ans;
					return 0;
				}
			}
		}
	}
	cout << ans;
	return 0;
}

