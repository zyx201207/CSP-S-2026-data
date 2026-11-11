#include <bits/stdc++.h>
using namespace std;

long long n,ans;
char a[1000000005],c[5];
bool m = true;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	int k = 1;
	for ( int i = 1 ; i <= n ;i++)
	{
		int x;
		cin >> x >> c[2];
		for ( int i = 1 ; i <= x ;i++)
			a[k++] = c[2];
		if (i != 1)
			if ( c[2] != c[1])
				m = false;
		c[1] = c[2];
	}
	for ( int i = 1 ; i <= k ; i++)
	{
		if ( a[i] != a[k+1-i])
		{
			ans++;
			a[k+1-i] = a[i];
		}
	}
	if (m)
		cout << 0;
	else
		cout << ans;
	return 0;
}
