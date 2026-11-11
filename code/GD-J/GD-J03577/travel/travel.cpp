#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    string C_1, S_1, C_2, S_2;
    cin >> C_1 >> S_1 >> C_2 >> S_2;
    if (C_1 == C_2) {
        cout << 1;
    } else {
        cout << "0000";
        return 0;
    }
    int num_S1 = S_1[0] * 10 + S_1[1];
    int num_S2 = S_2[0] * 10 + S_2[1];
    if (num_S1 == num_S2) {
        cout << 1;
    } else {
        cout << "000";
        return 0;
    }
    if ((S_1[2] <= 'C' && S_2[2] <= 'C') || (S_1[2] > 'C' && S_2[2] > 'C')) {
        cout << 1;
    } else {
        cout << "00";
        return 0;
    }
    if (abs(((int)S_1[2]) - ((int)S_2[2])) == 1) {
        cout << 1;
    } else {
        cout << 0;
    }
    return 0;
}