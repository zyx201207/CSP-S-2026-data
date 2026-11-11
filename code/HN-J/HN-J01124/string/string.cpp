#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 5;
int a[N];
char c[N];
signed main()
{
	freopen("string.in" , "r" , stdin);
	freopen("string.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i] >> c[i];
	int tot = 0;
	for (int i = 1 , j = n; i < j;)
	{
		if (a[i] > a[j])
		{
			if (c[i] != c[j]) tot += a[j];
			a[i] -= a[j];
			j--; 
		}
		else if (a[i] < a[j])
		{
			if (c[i] != c[j]) tot += a[i];
			a[j] -= a[i];
			i++;
		}
		else
		{
			if (c[i] != c[j]) tot += a[i];
			i++;
			j--;
		}
	}
	cout << tot;
	return 0;
}
