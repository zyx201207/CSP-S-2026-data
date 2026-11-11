#include<bits/stdc++.h>
#define ll long long
using namespace std;

string s, t, c1, c2;

void solve () {
    cin >> c1 >> s >> c2 >> t;
    if (c1 == c2) {
        if (s[0] == t[0] && s[1] == t[1]) {
            if (((s[2] == 'A' || s[2] == 'B' || s[2] == 'C') && (t[2] == 'A' || t[2] == 'B' || t[2] == 'C')) || ((s[2] == 'D' || s[2] == 'F') && (t[2] == 'D' || t[2] == 'F'))) {
                if ((s[2] == 'D' && t[2] == 'F') || (s[2] == 'F' && t[2] == 'D') || (s[2] == 'A' && t[2] == 'B') || (s[2] == 'B' && t[2] == 'A') || (s[2] == 'B' && t[2] == 'C') || (s[2] == 'C' && t[2] == 'B')) {
                    cout << "1111" << '\n';
                    return;
                } else {
                    cout << "1110" << '\n';
                    return;
                }
            } else {
                cout << "1100" << '\n';
                return;
            }
        } else {
            cout << "1000" << '\n';
            return;
        }
    } else {
        cout << "0000" << '\n';
        return;
    }
}

int main () {
    freopen ("travel.in", "r", stdin);
    freopen ("travel.out", "w", stdout);

    ios::sync_with_stdio (false);
    cin.tie (0), cout.tie (0);
    int T = 1; // cin >> T;
    while (T--) {
        solve ();
    }

    return 0;
}
