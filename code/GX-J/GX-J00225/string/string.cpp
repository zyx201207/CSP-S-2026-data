#include <bits/stdc++.h>
using namespace std;
void sv();
void svb();
void svp();
#define fuck(NM); fre();
void fre()
{

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("string.in","r", stdin);
    freopen("string.out","w",stdout);
}
signed main()
{
    fuck(NM);
    signed T = 1; //cin >> T;
    while (T--) svb();
    return 0;
}

using ll = long long;

void svb()//Centre Opening (? BLnb  68pts
{
    ll n, l = 0;
    string s = "";
    cin >> n;
    for (ll i = 1; i <= n; i++)
    {
        ll a;
        char c;
        cin >> a >> c;
        for (int j = 1; j <= a; j++)
            s += c;
        l += a;
    }
    ll lp, rp, cnt = 0;
    if (l % 2 == 0)
        lp = l/2-1, rp = l/2;
    else lp = rp = l/2;
    while (lp >= 0)
    {
        if (s[lp] != s[rp]) cnt++;
        lp--; rp++;
    }
    cout << cnt <<'\n';
}

// void svp()
// {
//     ll n;
//     cin >> n;
//     vector <ll> a(n+114),arc(n+114);
//     vector <char> c(n+114);
//     for (ll i = 1; i <= n; i++)
//     {
//         cin >> a[i] >> c[i];
//         arc[i] = arc[i-1] + a[i];
//     }
//     ll mid = arc[n] / 2;
//     ll lp = lower_bound(arc.begin(), arc.end(), mid) - arc.begin();
//     ll rp = upper_bound(arc.begin(), arc.end(), mid) - arc.begin();
//     ll lpl = mid - arc[lp], rpl = mid - arc[rp];
//     while (lp != arc.begin())
//     {
//         if (c[lp] != c[rp]) cnt += mid

//         if (lpl < rpl) lp--;
//         else if (lpl > rpl) rp++;
//         else if (lpl == rpl) lp--, rp++;
//         lpl = mid - arc[lp], rpl = mid - arc[rp];
//     }
// }
