#include <bits/stdc++.h>
using namespace std;
const int N = 1e+4;
long long n,m;
long long a[N];
long long ans = 0;
long long num;
bool fanc(int a , int b)
{
	return a < b;
}

int main()
{
	freopen ("crystal.in","r",stdin);
	freopen ("crystal.out","w",stdout);
	cin >> n >> m;
	for (long long i = 1 ; i <= n ; i++)
	{
		cin >> a[i];
	}
	sort(a + 1 , a + 1 + n,fanc);
	
	
	for (long long i = 1 ; i <= n ; i++)
	{
		if (m <= 0 && num == a[i]) ans++;
		if (m <= 0 && num != a[i]) break;
		if (m <= 0) continue;
		for (int j = i ; j > 0 ; j--)
		{
			m -= (a[i] - a[j]);
			a[j] = a[i];
		}
		num = a[i];
		ans++;
	}
	
	cout << ans;
	return 0;
}
