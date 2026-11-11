#include <bits/stdc++.h>
using namespace std;
int n, a, l, ans;
string s, c;
int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr),cout.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a >> c;
        l += a;
        for (int j = 1; j <= a; j++) {
            s += c;
        }
    }
    for (int i = 0; i <= l / 2; i++) {
        if (s[i] != s[l - 1 - i]) {
            s[l - 1 - i] = s[i];
            ans++;
        }
    }
    cout << ans;
    return 0;
}