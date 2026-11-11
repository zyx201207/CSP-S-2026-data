#include <iostream>
#include <algorithm>
#include <cstdio>
#define ll long long
using namespace std;
ll a[500005],b[300005],s[300005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n,m;
    cin >> n >> m;
    for (ll i = 1;i <= n;i++) cin >> a[i];
    if (n <= 500 && m <= 200)
    {
        for (ll i = 1;i <= n;i++)
        {
            for (ll j = 1;j <= m;j++) b[j] = 0;
            ll k = 1;
            for (ll j = i;j <= n;j++)
            {
                bool flag = 0;
                for (ll k = j+1;k <= n;k++)
                {
                    if (a[k] == a[j])
                    {
                        j = k-1;
                        flag = 1;
                        break;
                    }
                }
                if (!flag) b[a[j]]++;
            }
            for (ll j = 1;j <= m;j++)
            {
                if (b[j]) s[j]++;
            }
        }
        for (ll j = 1;j <= m;j++)
        {
            cout << s[j] << ' ';
        }
    }
    else
    {
        for (int i = 1;i <= n;i++)
        {
            for (ll j = 1;j <= m;j++) b[j] = 0;
            for (int j = i;j <= n;j++)
            {
                b[a[j]] = 1;
            }
            for (ll j = 1;j <= m;j++)
            {
                if (b[j]) s[j]++;
            }
        }
        for (ll j = 1;j <= m;j++)
        {
            cout << s[j] << ' ';
        }
    }
    return 0;
}
