#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    string r1, x1, r2, x2;
    cin >> r1 >> r2 >> x1 >> x2;
    for (int i = 0; i < r1.size(); i++) {
        if (r1[i] != x1[i]) {
            cout << "0000";
            return 0;
        }
    }
    cout << '1';
    if (r2[0] == x2[0] && r2[1] == x2[1]) {
        cout << 1;
    }
    else {
        cout << "000";
        return 0;
    }

    if (r2[2] > 'C' && x2[2] > 'C') {
        cout << "11";
        return 0;
    }
    else if (r2[2] <= 'C' && x2[2] <= 'C') {
        if ((int)r2[2] == (int)x2[2] + 1 || (int)x2[2] == (int)r2[2] + 1) {
            cout << "11";
        }
        else {
            cout << "10";
        }
        return 0;
    }
    cout << "00";
    return 0;
}