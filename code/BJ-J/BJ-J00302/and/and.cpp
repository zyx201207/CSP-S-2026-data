#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using sg = string;

ll n, m, k, a[2026000]; bool v[2026000];

void dfs(ll q, ll g)
{
    if(g == m)
    {
        ll qp;
        for(qp = 1; qp <= n; qp++)
            if(v[qp]) break;
        ll dq = a[qp];
        for(ll i = qp+1; i <= n; i++)
            if(v[i]) dq = dq & a[i];
        k = max(dq, k);
        return;
    }
    if(q > n) return;
    v[q] = true; dfs(q+1, g+1);
    v[q] = false; dfs(q+1, g);
}

int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(ll i = 1; i <= n; i++) cin >> a[i];
    if(m == n) for(ll i = 1; i <= n; i++) k = a[i]&k;
    else if(m == n-1)
        for(ll i = 1; i <= n; i++)
        {
            ll dq = a[(i == 1)? 2 : 1];
            for(ll j = 1; j <= n; j++)
                if(i != j) dq = dq&a[j];
            k = max(dq, k);
        }
    else if(m == 1) for(ll i = 1; i <= n; i++) k = max(a[i], k);
    else dfs(1, 0);
    cout << k;
    return 0;
}
