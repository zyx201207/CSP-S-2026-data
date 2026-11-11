#include <bits/stdc++.h>
using namespace std;
long long n,m;
int main ()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	long long a[n];
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	sort(a + 1,a + n + 1);
	cout << a[3];
	return 0;
}
