#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s1, s2, k1, k2;
    cin >> s1 >> s2 >> k1 >> k2;
    if(s1 != k1) {
        cout << "0000";
        return 0;
    }
    cout << '1';
    string h1(s2.begin(), s2.begin() + 2), h2(k2.begin(), k2.begin() + 2);
    if(h1 != h2) {
        cout << "000";
        return 0;
    }
    cout << '1';
    if(s2.back() == 'F' || s2.back() == 'D') {
        if(k2.back() == 'F' || k2.back() == 'D') cout << '1';
        else {
            cout << "00";
            return 0;
        }
    } else {
        if(k2.back() == 'A' || k2.back() == 'B' || k2.back() == 'C') cout << '1';
        else {
            cout << "00";
            return 0;
        }
    }
    int temp = max(s2.back(), k2.back()) - min(s2.back(), k2.back());
    if(temp == 1) cout << 1;
    else cout << 0;
    return 0;
}
