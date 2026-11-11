#include <bits/stdc++.h>

using namespace std;

long long n, a[200005], ans = 0;
char c[200005];

int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    cin >> a[1] >> c[1];
    for (int i = 2; i <= n; i++)
    {
        long x;
        char y;
        cin >> x >> y;
        if (y == c[i - 1])
        {
            i--;
            n--;
        }
        a[i] += x;
        c[i] = y;
    }
    for (int i = 1, j = n; i < j;)
    {
        if (c[i] != c[j])
            ans += min(a[i], a[j]);
        if (a[i] > a[j])
        {
            a[i] -= a[j];
            j--;
        }
        else
        {
            a[j] -= a[i];
            i++;
        }
    }
    cout << ans;
    return 0;
}
