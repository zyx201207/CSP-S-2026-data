#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 2e5;
ll n, j, ans, sum_len;
struct node{
    ll len;
    char apl;
}a[N];
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].len >> a[i].apl;
        sum_len += a[i].len;
    }
    ll x;
    j = n;
    if (sum_len % 2) {
        x = (sum_len - 1) / 2;
    } else {
        x = sum_len / 2;
    }
    for (int i = 1; i <= n; i++) {
        if (x == 0) {
            break;
        }
        if (x >= a[i].len) {
            x -= a[i].len;
            if (a[i].len <= a[j].len) {
                if (a[i].apl != a[j].apl) {
                    ans += a[i].len;
                }
                a[j].len -= a[i].len;
                a[i].len = 0;
            } else {
                while (a[i].len > a[j].len) {
                    if (a[i].apl != a[j].apl) {
                        ans += a[j].len;
                    }
                    a[i].len -= a[j].len;
                    j--;
                }
                if (a[i].len <= a[j].len) {
                    if (a[i].apl != a[j].apl) {
                        ans += a[i].len;
                    }
                    a[j].len -= a[i].len;
                    a[i].len = 0;
                }
            }
        } else {
            x = 0;
            if (a[i].apl != a[j].apl) {
                ans += a[j].len;
            }
        }
    }
    cout << ans;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}
