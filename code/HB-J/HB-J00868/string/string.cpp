#include <bits/stdc++.h>
using namespace std;

int n, ans;
string s;

int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int cnt;
        char c;
        cin >> cnt >> c;
        for (int j = 1; j <= cnt; ++j) s += c;
    }
    int len0 = s.size();
    string fr = s.substr(0, len0 / 2);
    string target = "";
    target += fr;
    // cout << fr << '\n';
    reverse(fr.begin(), fr.end());
    if (len0 % 2 == 1) target += s[len0 / 2 + 1];
    target += fr;
    int len = target.size();
    // cout << target << '\n';
    for (int i = (len0 % 2 == 1 ? len0 / 2 + 1: len0 / 2); i < len; ++i)
        if (s[i] != target[i]) ++ans;
    cout << ans;

    return 0;
}
