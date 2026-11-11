#include <bits/stdc++.h>

using namespace std;
int main()
{
    int c, n, m, d, q, a[5005][50005], k[500005];
    cin >> c >> n >> m >> d >> q;
    for (int i = 1;i <= m;i++)
    {
        cin >> a[i];
    }
    for (int i = 1;i <= n;i++)
    {
        for (int j = 1;j <= i+2;j++)
        {
            cin >> k[j];
        }
    }
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    return 0;
}
