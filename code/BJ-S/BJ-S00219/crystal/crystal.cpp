#include <bits/stdc++.h>
using namespace std;

bool f = 1,f2 = 1;
long long n,m,a[505050],cha,ans = 1,k;

int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m >> a[1];
    for (int i = 2; i <= n; ++i)
    {
        cin >> a[i];
        if (i == 2)
        {
            cha = a[i] - a[i - 1];
        }
        else
        {
            if (a[i] - a[i - 1] != cha)
            {
                f = 0;
            }
        }
    }
    if (f)
    {
        if (cha == 0)
        {
            cout << n << endl;
            return 0;
        }
        for (int i = 1;i <= n; ++i)
        {
            if ((a[1] + a[i]) * i / 2 > m)
            {
                cout << i << endl;
                return 0;
            }
        }
        cout << n << endl;
        return 0;
    }
    sort(a + 1,a + n + 1);
    k = a[1];
    for (int i = 2; i <= n; ++i)
    {
        m = m - (i - 1) * (a[i] - k);
        //cout << (i - 1) << " " << (a[i] - k) << endl;
        k = a[i];
        if (m < 0)
        {
            ans = i - 1;
            f2 = 0;
            break;
        }
    }
    if (f2)
    {
        ans = n;
    }
    cout << ans << endl;
    return 0;
}
