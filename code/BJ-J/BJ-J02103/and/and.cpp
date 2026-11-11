#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin >> n >> m;
    int a[200011] = {0};
    for (int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    if (n == m)
    {
        int ans = a[1];
        for (int i = 2;i <= n;i++)
        {
            ans = ans & a[i];
        }
        cout << ans;
        return 0;
    }
    else if (m == 1)
    {
        sort(a + 1,a + n + 1);
        cout << a[n];
        return 0;
    }
    else if (m == 2)
    {
        int ans = 0;
        for (int i = 1;i <= n;i++)
        {
            for (int j = i + 1;j <= n;j++)
            {
                if (a[i] & a[j] > ans) ans = a[i] & a[j];
            }
        }
        cout << ans;
        return 0;
    }
    else{
        sort(a + 1,a + n + 1);
        int ans = a[n];
        for (int i = 1;i < m;i++)
        {
            ans  = ans & a[n - i];
        }
        cout << ans;
    }
    return 0;
}
