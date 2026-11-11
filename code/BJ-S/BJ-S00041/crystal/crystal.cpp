#include <bits/stdc++.h>
#define N 500011
using namespace std;
typedef long long ll;

int n;
ll a[N], m;

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + 1 + n, [](const ll x, const ll y) {
        return x < y;
    });
    int ans = 1;
    ll sum = 0;
    for(int i = 1; i <= n; i++)
        if(i != 1 && a[i] != a[i - 1]) {
            sum += (a[i] - a[i - 1]) * (i - 1);
            ans = max(ans, i - 1);
            if(sum > m) break;
        }
    if(sum <= m) ans = n;
    cout << ans;
    return 0;
}