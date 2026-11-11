#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n;
ll l;
struct Piece
{
    ll a, l, r;
    char c;
} p[2000005];
Piece at(ll x)
{
    int l = 1, r = n;
    while(l != r)
    {
        int mid = (l + r) / 2;
        if(p[mid].l <= x && x <=p[mid].r)
            return p[mid];
        if(p[mid].l > x)
            r = mid - 1;
        if(p[mid].r < x)
            l = mid + 1;
    }
    return p[l];
}
int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n;
    for(ll i = 1; i <= n; i++)
    {
        cin >> p[i].a >> p[i].c;
        p[i].l = l + 1;
        l += p[i].a;
        p[i].r = l;
    }
    ll mid = (l + 1) / 2;
    ll idx;
    for(ll i = 1; i <= n; i++)
    {
        if(p[i].l >= mid && p[i].r < mid)
        {
            idx = i;
            break;
        }
    }
    ll cnt = 0;
    for(ll i = 1; i <= mid; i++)
    {
        Piece a = at(i), b = at(l - i + 1);
        if(a.c == b.c && a.l == b.l)
            break;
        ll ral = l - a.l + 1;
        ll rbl = l - b.l + 1;
        ll rar = l - a.r + 1;
        ll rbr = l - b.r + 1;
        ll al = max(a.l, rbr);
        ll ar = min(a.r, rbl);
        ll bl = max(b.l, rar);
        ll br = min(b.r, ral);
        if(a.c != b.c)
        {
            cnt += min(ar - al, br - bl) + 1;
        }
        i+= min(ar - al, br - bl); // + 1 - 1;
    }
    cout << cnt;
    return 0;
}