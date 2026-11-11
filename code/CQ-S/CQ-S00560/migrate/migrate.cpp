#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e6 + 5;
ll x[N]; int nxt[N], sto[N], l[N], r[N];
ll cnt1[N], cnt2[N];
void solve() {
    int n; ll d;
    cin >> n >> d;
    for (int i = 1; i <= n; i++)
        cin >> x[i], cnt1[i] = cnt2[i] = 0, nxt[i] = sto[i] = l[i] = r[i] = 0;
    ll ans = 0;
    for (int i = n, j = n; i >= 1; i--) {
        while (j - 1 >= i && x[j] - x[i] > d) {
            j--;
        }
        nxt[i] = j;
        sto[i] = 0;
        if (nxt[i] != i && nxt[nxt[i]] != nxt[i] && i != nxt[i] - 1) {
            if (nxt[nxt[i] - 1] == nxt[nxt[i]]) {
                sto[i] = nxt[i] - 1;
            }
        }
        if (i != nxt[i] && i != nxt[i] - 1) {
            r[i] = nxt[nxt[i] - 1];
            if (i != nxt[i] - 2) {
                l[i] = nxt[nxt[i] - 2] + 1;
            }
            else l[i] = nxt[i] + 1;
        }
        else {
            l[i] = nxt[nxt[i]], r[i] = nxt[nxt[i]] - 1;
        }
        if (nxt[nxt[nxt[i]]] != nxt[nxt[i]]) {
            if (sto[i] && sto[nxt[i]]) {
                cnt2[i] += r[i] - l[i] + 1;
                cnt1[i] += nxt[nxt[i]] - r[i] + nxt[i] - i;
            }
            else if (sto[i] && !sto[nxt[i]]) {
                if (r[i] - l[i] + 1 > 0)
                    cnt2[i] += cnt1[nxt[nxt[i]]];
                cnt2[i] += r[i] - l[i] + 1;
                cnt1[i] += nxt[nxt[i]] - r[i] + nxt[i] - i;
            }
            else if (!sto[i] && sto[nxt[i]]) {
                if (sto[nxt[i]] <= r[i] && i != nxt[i] - 1) {
                    cnt1[i] += nxt[nxt[nxt[i]]] - r[nxt[i]];
                    cnt2[i] += r[i] - l[i] + 1;
                    cnt1[i] += nxt[nxt[i]] - r[i] + nxt[i] - i;
                }
                else {
                    cnt1[i] += cnt1[nxt[i]] - (r[i] - l[i] + 1);
                    cnt2[i] += cnt2[nxt[i]];
                    cnt1[i] += nxt[i] - i;
                    cnt2[i] += r[i] - l[i] + 1;
                }
            }
            else {
                cnt1[i] += cnt1[nxt[i]] - (r[i] - l[i] + 1);
                cnt2[i] += cnt2[nxt[i]];
                if (i != nxt[i] - 1 && nxt[i] != nxt[nxt[i]] - 1 && l[i] <= nxt[nxt[i]] - 1 && nxt[nxt[i]] - 1 <= r[i])
                    cnt2[i] -= (r[nxt[i]] - l[nxt[i]] + 1);
                cnt1[i] += nxt[i] - i;
                cnt2[i] += r[i] - l[i] + 1;
            }
        }
        else if (nxt[nxt[i]] != nxt[i]) {
            cnt2[i] += r[i] - l[i] + 1;
            cnt1[i] += nxt[nxt[i]] - r[i] + nxt[i] - i;
        }
        else if (nxt[i] != i) {
            cnt1[i] += nxt[i] - i;
        }
        // if (i == 4) cerr << cnt2[i] << '\n';
        ans += cnt2[i];
    }
    cout << ans << '\n';
}
int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int c, T;
    cin >> c >> T;
    while (T--)
        solve();
    return 0;
}