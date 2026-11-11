#include <bits/stdc++.h>
using namespace std;
inline int side(char x) {
    if (x == 'F' || x == 'D') {
        return 1;
    } else {
        return 2;
    }
}
int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    string c1, s1, c2, s2;
    cin >> c1 >> s1 >> c2 >> s2;
    auto line1 = s1.substr(0, 2);
    auto line2 = s2.substr(0, 2);
    auto seat1 = s1[2];
    auto seat2 = s2[2];
    cout << (c1 == c2 ? "1" : "0");
    cout << (c1 == c2 && line1 == line2 ? "1" : "0");
    cout << (c1 == c2 && line1 == line2 && side(seat1) == side(seat2) ? "1" : "0");
    cout << (c1 == c2 && line1 == line2 && side(seat1) == side(seat2) && (seat1 == seat2 + 1 || seat1 + 1 == seat2) ? "1" : "0");
    cout << '\n';
    return 0;
}