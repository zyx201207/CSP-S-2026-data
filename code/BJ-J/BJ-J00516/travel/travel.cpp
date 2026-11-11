#include <bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
int ans[5];
inline void l(int k) {
    for (int j = 1; j <= k; j++) cout << "0";
}
int main() {
    freopen ("travel.in", r, stdin);
    freopen ("travel.out", w, stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    if (c1 != c2) {
        l(4);
        return 0;
    }
    else {
        cout << "1";
    }
    for (int i = 0; i < 2; i++) {
        if (s1[i] != s2[i]) {l(3); return 0;}
    }
    cout << 1;
    if ((s1[2] <= 'C' && s2[2] >= 'D') || (s1[2] >='D' && s2[2] <= 'C')) {
        l(2);
        return 0;
    }
    cout << 1;
    if ((s1[2] - '0') - (s2[2] - '0') == 1 || (s1[2] - '0') - (s2[2] - '0') == -1) cout << "1";
    else cout << "0";
    return 0;
}
