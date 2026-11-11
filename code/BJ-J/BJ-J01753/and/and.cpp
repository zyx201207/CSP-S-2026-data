#include <iostream>
using namespace std;
int a[1000005];
int b[1000005];
int anwei(int a, int b)
{
    return a || b;
}
int erjin(int n)
{
    int ans = 0;
    while(n != 0)
    {
        ans = ans * 10 + ans / 2;
        n /= 2;
    }
    return ans;
}
int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        b[i] = x;
        a[i] = erjin(x);
    }
    if (m == 1)
    {
         int maxn = -1;
         for (int i = 1; i <= n; i++)
         {
            maxn = max(maxn, a[i]);
         }
         cout << maxn;
    }
    else if (m == n)
    {
        int cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            cnt += anwei(cnt, b[i]);
        }
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cout << anwei(b[i], b[j]);
            }
        }
    }
    return 0;
}
