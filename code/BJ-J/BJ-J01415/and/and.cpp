#include <bits/stdc++.h>
using namespace std;
long long n, m, a[100020], ans;
int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
		cin >> a[i];
    for(int i = 1; i <= n; i++)
    {
		long long num = 0;
		for(int j = 1; j <= m; j++)
			num += &a[i];
		ans = max(ans, num);
    }
    cout << ans;
    return 0;
}