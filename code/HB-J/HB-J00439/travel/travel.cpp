#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll b1, b2;
string s1, s2;
void solve() {
    cin >> b1 >> s1 >> b2 >> s2;
    if (b1 == b2) {
        cout << 1;
        if (s1.substr(0, 2) == s2.substr(0, 2)) {
            cout << 1;
            string x = s1.substr(2, 1), y = s2. substr(2, 1);
            if ((x <= "C" && y <= "C") || (x > "C" && y > "C" )) {
                cout << 1;
                if (x[0] + 1 == y[0]|| x[0] - 1 == y[0]) {
                    cout << 1;
                } else {
                    cout << 0;
                }
            } else {
                cout << "00";
            }
        } else {
            cout << "000";
        }
    } else {
        cout << "0000";
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}
