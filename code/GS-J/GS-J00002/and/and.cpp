#include<bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
int n, m, ans, mx, cnt;
int a[N];
int main ()
{
    freopen ("and.in", "r", stdin);
    freopen ("and.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        mx = max (mx, a[i]);
        if (a[i] == 0 || a[i] == 1 || a[i] == 3 || a[i] == 7 || a[i] == 15 || a[i] == 31 || a[i] == 63 || a[i] == 127 || a[i] == 255 || a[i] == 511 || a[i] == 1023 || a[i] == 2047 || a[i] == 4095 || a[i] ==8191 || a[i] == 16383 || a[i] == 32677 || a[i] == 65535 || a[i] == 131071 || a[i] == 262143 || a[i] == 524287 || a[i] == 1048575)
        {
            cnt++;
        }
    }
    if (m == 1)
    {
        cout << mx;
        return 0;
    }
    if (m == n)
    {
        ans = pow (2, 20) - 1;
        for (int i = 1; i <= n; i++)
        {
            ans &= a[i];
        }
        cout << ans ;
        return 0;
    }
    if (m == 2)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                ans = max (ans, a[i] & a[j]);
            }
        }
        cout << ans;
        return 0;
    }
    if (mx < 4)
    {
        sort (a + 1, a + n + 1, greater<int> ());
        cout << a[m];
        return 0;
    }
    if (n == 1 || n == 2 || n == 4 || n == 8 || n == 16 || n == 32 || n == 64 || n == 128 || n == 256 || n == 512 || n == 1024 || n == 2048 || n == 4096 || n == 8192 || n == 16384 || n == 32768 || n == 65536 || n == 131072)
    {
        int sum = 0;
        for (int i = 1; i <= n; i++)
        {
            if (a[i] == i - 1)
                sum++;
        }
        if (sum == n)
        {
            sort (a + 1, a + n + 1, greater<int> ());
            ans = n - 1;
            for (int i = 1; i <= m; i++)
            {
                ans &= a[i];
            }
            cout << ans;
            return 0;
        }
    }
    if (cnt == n)
    {
        sort (a + 1, a + n + 1, greater <int> ());
        cout << a[m];
        return 0;
    }
    return 0;
}
