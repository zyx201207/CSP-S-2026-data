#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    string c1, s1, c2, s2;
    cin >> c1 >> s1 >> c2 >> s2;
    if (c1 != c2) cout << "0000";
    else {
        cout << 1;
        if (s1[0] != s2[0] || s1[1] != s2[1]) cout << "000";
        else {
            cout << 1;
            if ((s1[2] <= 'C' && s2[2] >= 'D') || (s1[2] >= 'D' && s2[2] <= 'C')) cout << "00";
            else {
                cout << 1;
                if (s1[2] > 'C' && s2[2] > 'C') cout << 1;
                else if (abs(s1[2] - s2[2]) == 1) cout << 1;
                else cout << 0;
            }
        }
    }
    cout << '\n';
    return 0;
}
