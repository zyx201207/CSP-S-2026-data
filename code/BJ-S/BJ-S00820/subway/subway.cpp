#include <bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q,w[500005],a[3][500005],t[3][500005],k[505],sm;
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1;i <= m;i++)
    {
        cin >> w[i];
    }
    for (int i = 1;i <= n;i++)
    {
        cin >> k[i];
        for (int j = 1;j <= k[i];j++)
        {
            cin >> a[i][j];
            cin >> t[i][a[i][j]];
        }
    }
    for (int i = 1;i <= k[1];i++)
    {
        for (int j = 1;j <= k[2];j++)
        {
            if (a[1][i] == a[2][j]) sm = a[1][i];
        }
    }
    for (int r = 1;r <= q;r++)
    {
        int xr,yr,xline,yline;
        cin >> xr >> yr;
        int ans = 0;
        ans += w[xr];
        ans += w[yr];
        for (int i = 1;i <= k[1];i++)
        {
            if (a[1][i] == xr)
            {
                xline = 1;
                break;
            }
            else if(a[2][i] == xr)
            {
                xline = 2;
                break;
            }
        }
        for (int i = 1;i <= k[2];i++)
        {
            if (a[1][i] == yr)
            {
                yline = 1;
                break;
            }
            else if(a[2][i] == yr)
            {
                yline = 2;
                break;
            }
        }
        if (xline == yline)
        {
            cout << ans << endl;
        }
        else
        {
            ans += t[xline][sm];
            ans += t[yline][sm];
            cout << ans << endl;
        }
    }
    return 0;
}
