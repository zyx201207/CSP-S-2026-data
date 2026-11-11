#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    string c1, s1, c2, s2;
    cin >> c1 >> s1 >> c2 >> s2;
    if (c1 == c2) {
        cout << 1;
        if (s1.substr(0, 2) == s2.substr(0, 2)) {
            cout << 1;
            if (s1[2] <= 'C' && s2[2] <= 'C' || s1[2] >= 'D' && s2[2] >= 'D') {
                cout << 1;
                char ch1 = s1[2], ch2 = s2[2];
                if (ch1 > ch2) swap(ch1, ch2);
                if (ch1 + 1 == ch2) {
                    cout << 1;
                }
                else {
                    cout << 0;
                }
            }
            else {
                cout << 0 << 0;
            }
        }
        else {
            cout << 0 << 0 << 0;
        }
    }
    else {
        cout << 0 << 0 << 0 << 0;
    }
    cout << '\n';
    return 0;
}
