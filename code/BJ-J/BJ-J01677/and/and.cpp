#include <iostream>
#include <algorithm>
#include <cstdio>
#define ll long long
using namespace std;
ll a[200005][35],c[100],del[200005],anss[100];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n,m;
    cin >> n >> m;
    for (ll i = 1;i <= n;i++)
    {
        ll x,cnt = 0;
        cin >> x;
        while (x)
        {
            cnt++;
            if (x % 2) c[cnt] = 1;
            else c[cnt] = 0;
            x /= 2;
        }
        for (ll j = 1;j <= cnt;j++)
        {
            a[i][j] = c[j];
            //cout << a[i][j];
        }
        //cout << ' ';
    }
    ll lst = n,ans = 0;
    for (ll i = 30;i >= 1;i--)
    {
        ll sum = 0;
        for (ll j = 1;j <= lst;j++) if (!del[j] && a[j][i]) sum++;
        //cout << sum << ' ';
        if (sum >= m)
        {
            for (ll j = 1;j <= lst;j++) if (!a[j][i]) del[j] = 1;
            anss[i] = 1;
        }
    }
    ll mi = 1;
    for (ll i = 1;i <= 40;i++)
    {
        if (anss[i]) ans += mi;
        mi *= 2;
    }
    cout << ans;
    return 0;
}
//9:40
