#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
void solve() {
    string c1, s1, c2, s2;
    cin >> c1 >> s1 >> c2 >> s2;
    if (c1 != c2) {
        cout << "0000";
    } else {
        cout << 1;
        if (s1.substr(0, 2) != s2.substr(0, 2)) {
            cout << "000";
        } else {
            cout << 1;
            if (s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C') {
                if (s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C') cout << 1;
                else {
                    cout << "00";
                    return ;
                }
            } else {
                if (s2[2] == 'D' || s2[2] == 'F') cout << 1;
                else {
                    cout << "00";
                    return ;
                }
            }
            if (s1[2] == (s2[2] + 1) || s1[2] == (s2[2] - 1)) {
                cout << 1;
            } else {
                cout << 0;
            }
        }
    }
}
int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
