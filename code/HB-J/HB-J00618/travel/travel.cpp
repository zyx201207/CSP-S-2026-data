#include <bits/stdc++.h>
using namespace std;
using ll = long long;
string c1, s1, c2, s2;
int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    if (c1 != c2) {
        cout << "0000\n";
        return 0;
    } else {
        cout << 1;
    }
    string p1 = "", p2 = "";
    p1 += s1[0];p1 += s1[1];
    p2 += s1[0];p2 += s2[1];
    if (p1 != p2) {
        cout << "000\n";
        return 0;
    } else {
        cout << 1;
    }
    char w1 = s1[2], w2 = s2[2];
    if ((w1 == 'A' || w1 == 'B' || w1 == 'C') & (w2 == 'A' || w2 == 'B' || w2 == 'C') ||
    ((w1 == 'D' || w1 == 'F') && (w2 == 'D' || w2 == 'F'))) {
        cout << 1;
    } else {
        cout << "00\n";
        return 0;
    }
    if (w1 > w2) {
        swap(w1, w2);
    }
    if ((w1 == 'A' && w2 == 'B') || (w1 == 'B' && w2 == 'C') || (w1 == 'D' && w2 == 'E')) {
        cout << 1;
    } else {
        cout << 0;
    }
    cout << '\n';
    return 0;
}
