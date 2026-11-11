#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5+5;
ll n, m, a[N], cnt=1, ans=0;
int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a+1, a+n+1);
    if (n == 1) {
        cout << 1;
        return 0;
    }
    for (ll l=1, r=2; r <= n; r++) {
        ans += (r-l)*(a[r]-a[r-1]);
        while (ans > m) {
            ans -= a[r]-a[l];
            l++;
        }
        cnt = max(cnt, r-l+1);
    }
    cout << cnt;
    return 0;
}
