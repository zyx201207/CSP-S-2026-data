#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rd read()
#define pii pair<int,int>
#define fo(a,b,c) for(int a=(b); a<=(c);++a)
#define of(a,b,c) for(int a=(b); a<=(c);--a)
#define pb push_back
#define enter putchar('\n')
const int N =5e5+7, M = 1e5+7, INF = 0x3f3f3f3f;
inline ll read() {
    ll x = 0,f=1; char ch = getchar();
    while (ch < '0' || ch > '9') {if (ch == '-')f=-1; ch = getchar();}
    while (ch >='0' && ch <='9') {x=x*10+ch-'0';ch = getchar();}
    return x*f;
}
// g++ crystal444.cpp -o crystal444 -std=c++14 -O2 -Wall
ll n, m;
ll a[N], s[N];
void Input() {
    n = rd, m = rd;
    fo (i, 1, n) {
        a[i] = rd;
    }
    sort(a+1, a+n+1);
    fo (i, 1, n) {
        s[i] = s[i-1]+a[i];
    }
}
ll ans = 1;
void answer() {
    printf("%lld", ans);
}
bool check(ll i, ll j) {
    return (j-i+1)*a[j]-s[j]+s[i-1] <= m;
}
void solve() {
    Input();
    fo (i, 1, n) {
        ll l = i, r = n, mid, res=0;
        while (l <= r) {
            mid = (l+r)>>1;
            if (check(i, mid)) {
                l = mid+1;
                res = mid;
            } else r = mid-1;
        }
        // printf("%lld %lld\n", i, res);
        if (check(i, mid))
            ans = max(ans, res-i+1);
    }

    answer();
}
signed main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    solve();
    return 0;
}