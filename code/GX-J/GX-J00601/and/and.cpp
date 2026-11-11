#include <iostream>
#include <algorithm>
using namespace std;
const int N = 2e5 + 5;
long long n, m, ans, a[N];
int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    if (m == 1)
    {
        cout << a[n];
        return 0;
    }
    ans = (a[n] & a[n - 1]);
    for (int i = 3; i <= m; i++)
    {
        ans &= a[n - i + 1];
    }
    cout << ans;
    return 0;
}
