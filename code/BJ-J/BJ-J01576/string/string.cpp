#include <iostream>
using namespace std;
#define ll long long
const int N = 2e5 + 5;
struct pst{
    ll le, ri;
}a[N];
char c[N];
ll n;
int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    ll x;
    ll cnt = 0;
    bool flag = 1;
    for(int i = 1; i <= n; i++) {
        cin >> x >> c[i];
        a[i].le = cnt + 1;
        a[i].ri = cnt + x;
        cnt += x;
    }
    ll cc = n, ans = 0;
    for(int i = 1; i <= n; i++) {
        if(a[i].ri >= cnt / 2) {
            if(a[i].le <= cnt / 2) {
                ll tmp = cnt - a[i].le + 1;
                if(tmp <= a[i].ri) {
                    break;
                }
                if(c[cc] != c[i] && cc != i) {
                    ans += tmp - a[cc].le + 1;
                    cc--;
                }
                while(cc > i) {
                    if(c[cc] == c[i]) {
                        cc--;
                        continue;
                    }
                    ans += a[cc].ri - a[cc].le + 1;
                    cc--;
                }
            }
            break;
        }
        ll tmp = cnt - a[i].le + 1;
        ll tmp2 = cnt - a[i].ri + 1;
        if(tmp < a[cc].le) {
            cc--;
        }
        if(c[i] != c[cc]) {
            if(tmp2 > a[cc].le) {
                ans += tmp - tmp2 + 1;
                continue;
            }
            ans += tmp - a[cc].le + 1;
            cc--;
        }
        while(a[cc].le >= tmp2) {
            if(c[cc] == c[i]) {
                cc--;
                continue;
            }
            ans += a[cc].ri - a[cc].le + 1;
            cc--;
        }
        if(tmp2 <= a[cc].ri && c[cc] != c[i]) {
            ans += a[cc].ri - tmp2 + 1;
        }
    }
    cout << ans;
    return 0;
}
