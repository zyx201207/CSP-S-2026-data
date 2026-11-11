#include <bits/stdc++.h>
using namespace std;
int main ()
{
    //freopen("and.in", "r", stdin);
    //freopen("and.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    int a[n + 1];
    for (int i = 1; i <= n; i++) cin >> a[i];
    if (n <= 2000)
    {
        if (m == 1)
        {
            sort(a + 1, a + n + 1);
            cout << a[n];
        }
        else if (m == n)
        {
            int cnt = a[1];
            for (int i = 2; i <= n; i++)
            {
                cnt = (cnt & a[i]);
            }
            cout << cnt;
        }
        else
        {
            int cnt = 0, maxx = -1000;
            for (int i = 1; i <= n; i++)
            {
                cnt = a[i];
                for (int j = 1; j <= n; j++)
                {
                    cnt = (cnt & a[j]);
                    if (cnt >= maxx)
                    {
                        maxx = cnt;
                    }
                }
            }
            cout << maxx;
        }
    }
    return 0;
}
