#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int n, m;
long long int a[514514], s[514514];

bool pd (int ans)
{
    int i;
    for (i = 0; i <= n - ans; i++)
    {
        int j = i + ans;
        if ((s[j] - s[i]) + m >= a[j] * ans)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    freopen ("crystal.in", "r", stdin);
    freopen ("crystal.out", "w", stdout);
    int i;
    cin >> n >> m;
    for (i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for (i = 1; i <= n; i++)
    {
        s[i] = s[i - 1] + a[i];
    }
    int l = 0, r = n + 1, mid;
    while (r - l > 1)
    {
        mid = (l + r) / 2;
        if (pd(mid))
        {
            l = mid;
        }
        else
        {
            r = mid;
        }
    }
    cout << l << endl;
    return 0;
}
