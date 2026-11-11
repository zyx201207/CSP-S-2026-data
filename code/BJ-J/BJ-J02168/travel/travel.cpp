
// ========== ACACACACAC ==========
// This is T1.

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

string c1, s1, c2, s2;

inline void solve() {
    cin >> c1 >> s1 >> c2 >> s2;

    if (c1 != c2) {
        cout << "0000";
        return ;
    }
    cout << "1";

    if (s1[0] != s2[0] || s1[1] != s2[1]) {
        cout << "000";
        return ;
    }
    cout << "1";

    if (s1[2] == 'D' || s1[2] == 'F') {
        if (s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C') cout << "00";
        else cout << "11";
    } else {
        if (s2[2] == 'D' || s2[2] == 'F') {
            cout << "00";
            return ;
        }

        cout << "1";
        if (s2[2] == s1[2] + 1 || s2[2] == s1[2] - 1) cout << "1";
        else cout << "0";
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    int T = 1;
    // cin >> T;
    while (T--) solve();
    return 0;
}