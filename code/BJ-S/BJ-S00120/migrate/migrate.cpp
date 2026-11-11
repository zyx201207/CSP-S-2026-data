#include<bits/stdc++.h>
#define int long long
using namespace std;
int x[2000005];
signed main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int c, t;
    cin >> c >> t;
    while(t--)
    {
        int n, d;
        cin >> n >> d;
        for(int i = 1; i <= n;i++) cin >> x[i];
        if(n == 1)
        {
            cout << 0 << endl;
            continue;
        }
        int p;
        if(c == 11 || c == 12 || c == 0)
        {
            p = x[2] - x[1];
            int ont = d / p;
            int ans = 0;
            for(int i = 1; i < ont;i++)
            {
                int len = ont + i;
                if(len <= n) ans += n - len + 1;
            }
            if(ont + 1 <= n && ont >= 2) cout << n - ont << endl;
            else cout << 0 << endl;
        }
        else if(c == 13 || c == 14)
        {
            int ans = 0;
            for(int i = 1;i <= n;i++)//以此为起点
            {
                int l = i, r = n;
                while(l < r)
                {
                    int mid = (l + r) / 2;
                    if(x[mid] > x[i] + d) r = mid;
                    else l = mid + 1;
                }
                if(x[l] > x[i] + d && x[l] < x[i] + 2 * d) ans += n - l + 1;
            }
            cout << ans << endl;
        }
    }
    return 0;
}
