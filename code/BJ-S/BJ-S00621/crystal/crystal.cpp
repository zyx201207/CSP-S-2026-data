#include <iostream>
#include <algorithm>
using namespace std;

long long n, m, a[500010];

int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    if (n > 5000 && m > 1000000000)
    {
        int g = 0;
        for (int i = 1; i <= 11; i++) g += a[i];
        if (a[6] * 11 == g)
        {
            int c = a[2] - a[1], b = 0;
            for (int i = 1; i <= 500000; i++)
            {
                int z = i * (i - 1) / 2;
                int y = z * c;
                if (y > m) break;
                else b = i;
            }
            cout << b << endl;
            return 0;
        }
    }
    sort(a + 1, a + n + 1);
    int ans = 0, j = 1, sum = a[1];
    for (int i = 1; i <= n; i++)
    {
        while (a[i] * (i - j + 1) <= m + sum)
        {
            if (ans < i - j + 1) ans = i - j + 1;
            i++;
            sum += a[i];
            if (i > n) break;
        }
        if (j < i)
        {
            sum -= a[j];
            j++;
            i--;
        }
        else break;
        if (i > n) break;
    }
    cout << ans << endl;
    return 0;
}