#include <bits/stdc++.h>
using namespace std;
void sv(long long jt);
void fre()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("card.in","r", stdin);
    freopen("card.out","w",stdout);
}

using ll = long long;
ll a[1145141], ans[1145141];
ll n, m;

signed main()
{
    fre();
    cin >> n >> m;
    for (ll i = 1; i <= n; i++)
        cin >> a[i];
    for (ll i = 1; i <= n; i++)
        sv(i);
    for (ll i = 1; i <= m; i++)
        cout << ans[i] <<' ';
    return 0;
}

ll find(ll x, vector <ll> &vec, ll bl)
{
    ll cnt = 0;
    if (vec.empty()) return -1;
    for (auto i : vec)
    {
        if (cnt == bl) return -1;
        if (i == x) return cnt;
        cnt++;
    }
    return -1;
}

void sv(ll jt)
{
    vector <ll> v;
    ll blue = 0;
    for (ll i = jt; i <= n; i++)
    {
        ll itl = find(a[i], v, blue);
        if (itl == -1)
        {
            blue++;
            v.push_back(a[i]);
        }
        else
            blue = itl+1;
    }
    int xi = 0;
    for (auto i : v)
    {
        if (xi == blue) break;
        xi++;
        ans[i]++;
    }
}
