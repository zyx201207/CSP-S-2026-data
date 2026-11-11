#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ll m,n;cin >> n >> m;ll a[n];
    for (ll i = 0;i < n;i++){cin >> a[i];}
    sort(a,a + n);
    if (n <= 5000)
    {
        ll cost[n][n],mico[n + 1];
        for (int i = 0;i < n;i++){for (int j = 0;j < n;j++){cost[i][j] = 0;}}
        for (int i = 0;i <= n;i++){mico[i] = 1000000000000000000;}
        for (int i = 0;i < n;i++)
        {
            for (int j = i + 1;j < n;j++)
            {
                cost[i][j] = cost[i][j - 1] + (j - i) * (a[j] - a[j - 1]);
            }
        }
        for (int t = 0;t <= n;t++)
        {
            for (int i = 0;i <= n - t;i++)
            {
                mico[t] = min(cost[i][i + t - 1],mico[t]);
            }
        }
        for (int i = 0;i <= n;i++)
        {
            if (mico[i] > m){cout << i - 1;return 0;}
        }
        cout << n;
        return 0;
    }
    ll d = a[1] - a[0],flag = 1;
    for (int i = 0;i < n - 1;i++)
    {
        if (a[i + 1] - a[i] != d){flag = 0;}
    }
    if (flag == 1)
    {
        for (ll i = 0;i <= n;i++)
        {
            if (d * i * i - d * i > m + m){cout << i - 1;return 0;}
        }
        cout << n;return 0;
    }
    return 0;
}