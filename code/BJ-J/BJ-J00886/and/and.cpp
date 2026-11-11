#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 * 2 + 5;
int n, m;
long long a[N];
int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    int cnt = 2e30 - 1;
    for (int i = n - 1; i >= n - m; i--)
    {
        cnt &= a[i];
    }
    cout << cnt;
    return 0;
}
