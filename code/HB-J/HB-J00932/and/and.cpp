#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m,a[200005];
    cin >> n >> m;
    if (m == 1)
    {
	    cout << 0;
	    return 0;
	}
    for (long long i = 1;i <= n;i++)
    {
		cin >> a[i];
	}
	sort(a + 1,a + n + 1);
	long long ans = a[n];
	for (long long i = 2;i <= m;i++)
	{
	    ans = ans & a[n - i + 1];
	}
	cout << ans;
    return 0;
}
