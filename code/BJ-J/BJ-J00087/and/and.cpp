#include <bits/stdc++.h>

using namespace std;

int f[50], x[50];
int n, m, a[200005];

bool cmp(int x, int y)
{
    return x > y;
}

int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    x[0] = 1;
    for (int i = 1; i < 31; i++)
        x[i] = x[i - 1]* 2;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        int j = 0;
        int b = a[i];
        while (b > 0)
        {
            f[j] += b % 2;
            b /= 2;
            j++;
        }
    }
    sort(a, a + n, cmp);
    for (int i = 30; i >= 0; i--)
    {
        if (f[i] >= m)
            break;
        if (f[i] > 0)
        {
            for (int j = 0; j < n; j++)
                if (a[j] >= x[i])
                    a[j] -= x[i];
        }
    }
    sort(a, a + n, cmp);
    int ans = a[0];
    for (int i = 1; i < m; i++)
        ans = ans & a[i];
    cout << ans;
    return 0;
}
