#include <bits/stdc++.h>

using namespace std;
int main()
{
    int n, m, x, a[500005], num[500005] = {100000000};
    cin >> n >> m;
    for (int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    for (int i = 1;i <= n;i++)
    {
        for (int j = 1;j <= n;j++)
        {
            if (i > j && a[i] >= a[j])
            {
                x = a[i] - a[j];
            }
            else if (i == j)
            {
                x = 1000000000;
            }
            else if (i > j && a[i] < a[j])
            {
                x = a[j] - a[i];
            }
            num[i] = min(x,num[i]);
        }
    }
    int minn[500005] = {100000000};
    for (int i = 1;i <= m;i++)
    {
        for (int j = 1;i <= n;i++)
        {
            minn = min(minn[i],num[j]);
        }
    }
    for (int i = 1;i <= m;i++)
    {
        if (minn[i] + minn[i+1] == m)
        {
            cnt++
        }
    }
    cout << cnt;
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    return 0;
}
