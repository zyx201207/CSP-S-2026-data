#include<bits/stdc++.h>
using namespace std;
//#define int long long
int n, m;
int a[200010];
int maxx;
signed main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1;i <= n; i ++)
    {
        cin >> a[i];
        maxx = max(maxx, a[i]);

    }
    if(m == 1)
    {
        cout << maxx;
        return 0;
    }
    if(m == n)
    {
        int cnt = 0;
        for(int i = 1; i <= n; i ++)
        {
            cnt = a[i] & cnt;
        }
        cout << cnt;
        return 0;
    }
    if(m == 2)
    {
        int ans = 0;
        for(int i = 1; i <= n; i ++)
        {
            for(int j = 1; j <= n; j ++)
            {
                ans = max(ans, a[i] & a[j]);
            }
        }
        cout << ans;
        return 0;
    }

    return 0;
}
