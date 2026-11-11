#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    long long n, m, a[200005], b[200005], sum;
    cin >> n >> m;
    for (long long i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for (long long i = n; i >= n - m; i--)
    {
        b[n - i + 1] = a[i];
    }
    for (long long i = 1; i <= m - 1; i++)
    {
        sum = b[i] & b[i + 1];
        b[i + 1] = sum;
    }
    cout << b[m];
    return 0;
}
