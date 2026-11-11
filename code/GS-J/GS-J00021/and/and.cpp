#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 2e5+5;
inline ll read() {
    ll x = 0, f = 1;char c = getchar();
    while(c<'0'||c>'9') {
        if(c == '-') f = -1;
        c = getchar();
    }
    while(c>='0'&&c<='9') {
        x = x*10+(c-'0');
        c = getchar();
    }
    return f*x;
}
ll n, m, a[N];
int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);

    n = read();m = read();
    for(int i = 0; i < n; ++i) a[i] = read();
    sort(a, a+n+1, greater<ll>());
    ll ans = a[0];
    for(int i = 0; i < m; ++i) {
        ll p = a[i];
        if(ans<p) {
            ll t = ans;
            ans = p;
            p = t;
        }
        ans = (ans&p);
    }
    cout << ans << endl;
    return 0;
}