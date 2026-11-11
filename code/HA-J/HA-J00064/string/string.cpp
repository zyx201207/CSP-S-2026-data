#include<bits/stdc++.h>

#define int long long 
#define N 200010

using namespace std;

int n;
int a[N], sum[N];
char c[N];
int ans;
string s1, s2;
signed main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i] >> c[i];
	}
	int i = 1, j = n;
	while (i <= j) 
	{
//		cout << a[i] << ' ' << c[i] << "   " << a[j] << ' ' << c[j] << "   ";
		if (a[i] > a[j])
		{
			if (c[i] != c[j])
			{
				ans += a[j];
			}
			a[i] -= a[j], j--;
		}
		else if (a[i] < a[j])
		{
			if (c[i] != c[j])
			{
				ans += a[i];
			}
			a[j] -= a[i], i++;
		}
		else
		{
			if (c[i] != c[j])
			{
				ans += a[i];
			}
			i++, j--;
		}
//		cout << ans << '\n';
	}
	cout << ans;
	return 0;
}
/*
24474
31777
*/

