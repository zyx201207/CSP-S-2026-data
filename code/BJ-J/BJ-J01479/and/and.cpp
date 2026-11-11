#include <bits/stdc++.h>
using namespace std;
long long a[200005],vis[200005],ans,n,m,num,p;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for (int i = 1;i <= n;i++)
    {
        cin >> a[i];
        vis[i] = 1;
    }
    num = n;
    for (int i = 31;i >= 1;i--)
    {
        p = num;
        for (int j = 1;j <= n;j++)
        {
            if (vis[j] == 0) continue;
            if((a[j] & (1 << (i - 1))) == 0)
            {
                num -= 1;
            }
        }
        if (num >= m)
        {
            for (int j = 1;j <= n;j++)
            {
                if((a[j] & (1 << (i - 1))) == 0)
                {
                    vis[j] = 0;
                }
            }
            ans += (1 << (i - 1));
        }
        else if (num < m)
        {
            num = p;
        }
    }
    cout << ans;
    return 0;
}
