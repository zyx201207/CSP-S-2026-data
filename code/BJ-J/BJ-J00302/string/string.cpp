#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using sg = string;

ll n, ct, k[2026000], gd[2026000]; char c[2026000]; sg s; bool tp1 = true, tp2 = true;

ll Gcd(ll a, ll b)
{
    if(!(a%b)) return b;
    return Gcd(b, a%b);
}

int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n; cin >> k[1] >> c[1];
    for(ll i = 2; i <= n; i++)
    {
        cin >> k[i] >> c[i];
        if(!tp1 && !tp2) continue;
        if(k[i] != k[i-1]) tp1 = false;
        if(c[i] != c[i-1]) tp2 = false;
    }
    if(tp2) {cout << 0; return 0;}
    if(tp1) for(ll i = 1; i <= n; i++) s += c[i];
    else
    {
        gd[1] = k[1];
        for(ll i = 2; i <= n; i++) gd[i] = Gcd(gd[i-1], k[i]);
        for(ll i = 1; i <= n; i++)
            for(ll j = 1; j <= k[i]/gd[n]; j++) s += c[i];
    }
    for(ll i = 0; i < s.size()/2; i++)
        if(s[i] != s[s.size()-i-1]) ct++;
    cout << ct*(tp1? k[1] : gd[n]);
    return 0;
}
