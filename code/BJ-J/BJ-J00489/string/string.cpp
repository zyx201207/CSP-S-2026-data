#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    char c;
    long long n, x, j, pos = -1, a[1000000], sum, t;
    cin >> n;
    for (long long i = 1; i <= n; i++)
    {
        cin >> x >> c;
        for (j = 1; j <= x; j++)
        {
            a[pos + j] = c - ' ';
            t++;
        }
        pos += j - 1;
    }
    pos = 0;
    for (long long i = t / 2 - 1; i >= 0; i--)
    {
        pos++;
        if (t % 2 != 0 && a[i] != a[i + 2 * pos]) sum++;
        else if (t % 2 == 0 && a[i] != a[i + 2 * pos - 1]) sum++;
    }
    cout << sum;
    return 0;
}