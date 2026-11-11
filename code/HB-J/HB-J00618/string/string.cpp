#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2 * 1e5 + 5;
int n, a[N];
char c[N];
ll ans = 0;
string s = "";
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i] >> c[i];
        for (int j = 1; j <= a[i]; ++j) {
            s += c[i];
        }
    }
    ll len = s.size();
    for (ll i = 0; i < len / 2; ++i) {
        if (s[i] != s[len - i - 1])
            ans++;
    }
    cout << ans;
    return 0;
}
