#include <bits/stdc++.h>

const long long IMX = 1ll << 30;
const long long LMX = 1ll << 60;

#define fst first
#define snd second

using namespace std;
using ll = long long;
using ld = long double;
const int N = 200005;
ll n, m, ans;
ll a[N];
bool check(ll x) {
    ll cnt = 0;
    for (int i = 1; i <= n; i++) cnt += (a[i] & x) >= x;
    return cnt >= m;
}
int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios :: sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 30; i >= 0; i--) { if (check(ans | (1ll << i))) ans |= 1ll << i; }
    cout << ans;
    return 0;
}