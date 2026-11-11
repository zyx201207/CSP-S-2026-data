#include<bits/stdc++.h>
using namespace std;
#define int long long

int c, n, m, d, q;
int w[550];

int x, y;
int k;
int f;
int a[520][1100], t[520][1100];
bool flag = false;
bool flag2 = false;
int xx;
signed main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= m; i ++)
        cin >> w[i];

    for(int j = 1; j <= n; j ++)
    {
        cin >> k;
        for(int i = 1; i <= k; i ++)
        {
            cin >> a[j][i] >> t[j][i];
        }
    }
    //sort(a + 1, a + 1 + k, cmp);
    while(q --)
    {
        flag = false;
        int ans = 0;
        cin >> x >> y;
        ans = w[x] + w[y];
        //cout << ans <<'\n';
        if(x > y) swap(x, y);
        for(int i = 1; i <= n; i ++)
        {

            for(int j = 1; j <= 2; j ++)
            {
                if(a[i][j] == x && flag == false)
                {
                    ans += t[i][j];
                    if(x == y)
                    { cout << ans << '\n'; flag = true;}
                    if(flag2 == false)
                    {
                        flag2 = true;
                        x ++;
                    }else flag2 = false;
                }
                if(flag == true) break;
            }
        }
        //cout << ans << '\n';
    }
    return 0;
}
