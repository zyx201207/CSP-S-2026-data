#include <bits/stdc++.h>
using namespace std;
long long n, m, a[200005], maxn = -1e18, sum;
int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        sum = a[i];
        for (int j = i + 1; j <= n; j++)
        {
            sum = sum & a[j];
        }
        maxn = max(maxn, sum);
    }
    cout << maxn;
    return 0;
}
