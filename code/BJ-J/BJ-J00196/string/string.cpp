#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e5 + 5;
ll n;
struct Node{
    ll a;
    char ch;
} a[N];
int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    ll sum = 0;
    for (ll i = 1; i <= n; i++) {
        cin >> a[i].a >> a[i].ch;
        //sum += a[i].a;
    }
    ll ans = 0, i = 1, j = n;
    while (i < j) {
        if (a[i].ch != a[j].ch) {
            if (a[i].a < a[j].a) {
                ans += a[i].a;
                a[j].a -= a[i].a;
                i++;
            } else if (a[i].a > a[j].a) {
                ans += a[j].a;
                a[i].a -= a[j].a;
                j--;
            } else {
                ans += a[i].a;
                i++;
                j--;
            }
        } else {
            if (a[i].a < a[j].a) {
                //ans += a[i].a;
                a[j].a -= a[i].a;
                i++;
            } else if (a[i].a > a[j].a) {
                //ans += a[j].a;
                a[i].a -= a[j].a;
                j--;
            } else {
                //ans += a[i].a;
                i++;
                j--;
            }
        }
    }
    cout << ans;
    return 0;
}
