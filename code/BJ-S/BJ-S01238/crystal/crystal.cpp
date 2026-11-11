#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5+5;
int n, m, a[N], d[N], sum[N], ans, cnt, sumd;
//int ansl, ansr;

signed main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a+1, a+n+1);
    for (int i = 1; i <= n; i++)
    {
        d[i] = a[i] - a[i-1];
        //cout << d[i] << " ";
    }
    int l = 1, r = 1;
    while (r <= n)
    {
        //cout << l << " " << r << " " << cnt << " " << sumd << endl;
        if ( cnt > m )
        {
            sumd -= d[l++];
            cnt -= sumd;
        }
        if ( cnt <= m )
        {
            //if ( r - l + 1 > ans ) ansl = l, ansr = r;
            ans = max(ans, r - l + 1);
        }
        sumd += d[++r];
        cnt += sumd;
    }
    //cout << ansl << " " << ansr << endl;
    cout << ans;

    return 0;
}
