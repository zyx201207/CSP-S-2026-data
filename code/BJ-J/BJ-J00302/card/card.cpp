#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using sg = string;

ll n, m, a[2026000], z[2026000], t, u[2026000];

int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(ll i = 1; i <= n; i++) cin >> a[i];
    for(ll i = 1; i <= n; i++)
    {
        for(ll i = 1; i <= t; i++) z[i] = 0;
        t = 0;
        for(ll j = i; j <= n; j++)
        {
            for(ll k = 1; k <= t; k++)
                if(z[k] == a[j]) {t = k-1; break;}
            z[++t] = a[j];
        }
        for(ll j = 1; j <= m; j++)
            for(ll k = 1; k <= t; k++) if(z[k] == j) {u[j]++; break;}
    }
    for(ll i = 1; i <= m; i++) cout << u[i] << " ";
    return 0;
}
