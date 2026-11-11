#include <bits/stdc++.h>
using namespace std;
long long a[500005],n,m,sum[500005],q = 0;
int ans = 0;
bool flag = true,flag2 = true;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    sum[0] = 0;
    a[0] = 0;
    cin >> a[1];
    q = a[1] - a[0];
    for (int i = 2;i <= n;i++)
    {
        cin >> a[i];
        if(a[i] - a[i - 1] != q) flag = false;
        if(a[i] != i) flag2 = false;
    }
    if (flag)
    {
        long long x = 0;
        for (int i = 1;i <= n;i++)
        {
            x += i * q;
            if(x <= m) ans = i;
        }
        cout << ans;
        return 0;
    }
    if (flag2)
    {
        for (int i = n;i >= 1;i--)
        {
            if (n * (n - 1) == m * 2)
            {
                cout << n;
                return 0;
            }
            if(i < n and n * (n - 1) > m * 2 and (n + 1) * n > m * 2)
            {
                cout << n;
                return 0;
            }
        }
    }
    sort(a + 1,a + n + 1);
    for (int i = 1;i <= n;i++)
    {
        for (int j = 0;j < i;j++)
        {
            sum[i] = sum[i - 1] + (i - 1) * (a[i] - a[i - 1]);
            if(sum[i] - sum[j] == m)
            {
                ans = max(ans,i - j);
            }
            else if(sum[i - 1] -sum[j] < m and sum[i] -sum[j] > m and sum[i - 1] >= 0) ans = max(ans,i - 1 - j);
        }
    }
    cout << ans;
    return 0;
}
