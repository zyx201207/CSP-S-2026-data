#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 1e5 + 5;
ll n, m, a[N], ans[N];
bool t[N];

void solve(ll n) {
    for (ll i = 1; i <= m; i++) {
        ans[i] = 0;
    }
    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= m; j++) {
            t[j] = 0;
        }
        stack <ll> st;
        for (ll j = i; j <= n; j++) {
            if (t[a[j]]) {
                ll num = 0;
                while (num != a[j]) {
                    num = st.top();
                    st.pop();
                    t[num] = 0;
                }
            }
            st.push(a[j]);
            t[a[j]] = 1;
        }
        for (ll j = 1; j <= m; j++) {
            ans[j] += t[j];
        }
    }
    for (ll i = 1; i <= m; i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
    }
    solve(n);
    return 0;
}
