#include <iostream>
#include <algorithm>
using namespace std;

long long a[500010], s[500010], n, m;

bool chk(int len)
{
    for (int i = 1, j = len; j <= n; i++, j++)
    {
        if (s[j] - 1ll * (i - 1) * (a[j] - a[i - 1]) - s[i - 1] <= m)  return true;
    }
    return false;
}

int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for (int i = 2; i <= n; i++)
    {
        s[i] = s[i - 1] + 1ll * (i - 1) * (a[i] - a[i - 1]);
    }
    int l = 1, r = n;
    while (l < r)
    {
        int mid = (l + r + 1) / 2;
        if (chk(mid))  l = mid;
        else r = mid - 1;
    }
    cout << l;
    return 0;
}