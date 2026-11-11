#include<bits/stdc++.h>
using namespace std;
int n, m, d, q, w[500005], k[505], a[505][20004], t[505][20004], ans;
int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    int c;
    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= m; i++)
        cin >> w[i];
    for(int i = 1; i <= n; i++)
    {
        cin >> k[i];
        for(int j = 1; j <= k[i]; j++)
            cin >> a[i][j] >> t[i][j];
    }
    while(q--)
    {
        ans = 0;
        int s, ta;
        int minn = 2147483647;
        cin >> s >> ta;
        for(int i = 1; i <= n; i++)
        {
            bool f = 0;
            for(int j = 1; j <= k[i]; j++)
            {
                int sum = w[s];
                if(a[i][j] == s)
                {
                    f = 1;
                    sum += t[i][j];
                    if(minn >= sum)
                        minn = sum;
                    break;
                }
            }
            if(f == 0)
                continue;
        }
        ans += minn;
        minn = 2147483647;
        for(int i = 1; i <= n; i++)
        {
            bool f = 0;
            for(int j = 1; j <= k[i]; j++)
            {
                int sum = w[ta];
                if(a[i][j] == ta)
                {
                    f = 1;
                    sum += t[i][j];
                    if(minn >= sum)
                        minn = sum;
                    break;
                }
            }
            if(f == 0)
                continue;
        }
        ans += minn;
        cout << ans << "\n";
    }
    return 0;
}
