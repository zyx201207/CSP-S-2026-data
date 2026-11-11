#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin >> n >> m;
    int a[n + 5];
    for (int i = 1;i <= n;i++) cin >> a[i];
    if (m == n)
    {
        int cnt = a[1];
        for (int i = 2;i <= n;i++) cnt = cnt & a[i];
        cout << cnt;
    }
    else if (m == 1)
    {
        int cnt = 0;
        for (int i = 1;i <= n;i++) cnt = max(cnt,a[i]);
        cout << cnt;
    }
    else if (m == 2)
    {
        int cnt[n + 5],num,ans = 0;
        for (int i = 1;i < n;i++)
        {
            cnt[i] = (a[i] & a[i + 1]);
            for (int j = i + 1;j <= n;j++)
            {
                num = (a[i] & a[j]);
                cnt[i] = max(cnt[i],num);
            }
        }
        for (int i = 1;i < n;i++) ans = max(ans,cnt[i]);
        cout << ans;
    }
    return 0;
}
