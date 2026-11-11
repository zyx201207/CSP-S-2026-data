#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define ull unsigned long long
#define sqr(x) ((x) * (x))
using namespace std;

constexpr unsigned int NR = 2e5 + 5;
int n;
ll a[NR];
char ch[NR];
void solve() {
    cin >> n;
    ll sum = 0;
    for (int i = 1; i <= n; ++ i) {
        cin >> a[i] >> ch[i];
        sum += a[i];
    }
    int tot = 0;
    for (int i = 1; i <= n; ++ i)
        if (ch[i] == ch[tot])
            a[tot] += a[i];
        else {
            ch[++ tot] = ch[i];
            a[tot] = a[i];
        }
    n = tot;
    ll suml = 0, sumr = 0, l = 0, r = n + 1, ans = 0;
    while (l < r - 1) {
        if (suml <= sumr) {
            l ++;
            if (ch[r] != ch[l])
                ans += min(sumr, suml + a[l]) - suml;
            suml += a[l];
        } else {
            r --;
            if (ch[r] != ch[l])
                ans += min(suml, sumr + a[r]) - sumr;
            sumr += a[r];
        }
    }
    cout << ans << '\n';
}

int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int oT_To = 1;
    // cin >> oT_To;
    while (oT_To --)
        solve();
    return 0;
}
