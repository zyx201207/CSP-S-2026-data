#include <bits/stdc++.h>
using namespace std;
int n,m,a[200005],p[35],ans;
bool f[200005];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for (int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    p[0] = 1;
    for (int i = 1;i <= 30;i++)
    {
        p[i] = p[i - 1] * 2;
    }
    for (int i = 30;i >= 0;i--)
    {
        int cnt = 0;
        for (int j = 1;j <= n;j++)
        {
            if (f[j]) continue;
            if ((a[j] & p[i]) > 0) cnt++;
        }
        if (cnt < m) continue;
        for (int j = 1;j <= n;j++)
        {
            if (f[j]) continue;
            if ((a[j] & p[i]) == 0) f[j] = 1;
        }
        ans += p[i];
    }
    cout << ans;
    return 0;
}