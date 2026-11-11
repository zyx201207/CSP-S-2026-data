#include <bits/stdc++.h>
using namespace std;

long long a[2005];

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin >> n >> m;
    for (int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    if (m == n)
    {
        for (int i = 2;i <= n;i++)
        {
            a[i] = a[i] & a[i-1];
        }
        cout << a[n];
    }
    else if (m == 1)
    {
        int maxa = 0;
        for (int i = 1;i <= n;i++)
        {
            if (a[i] & a[i] > maxa)
            {
                maxa = a[i] & a[i];
            }
        }
        cout << maxa;
        return 0;
    }
    else if (m == 2)
    {
        int maxa = 0;
        for (int i = 1;i <= n;i++)
        {
            for (int j = i + 1;j <= n;j++)
            {
                if (a[i] & a[j] > maxa)
                {
                    maxa = a[i] & a[j];
                }
            }
        }
        cout << maxa;
        return 0;

    }
    else
    {
        cout << 2;
    }
    return 0;
}
