#include <bits/stdc++.h>
using namespace std;

string c1, c2, c3, c4;

int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> c1 >> c2 >> c3 >> c4;
    string pai1 = "", pai2 = "";
    for (auto i : c2) {
        if (i >= '0' && i <= '9') pai1 += i;
    }
    for (auto i : c4) {
        if (i >= '0' && i <= '9') pai2 += i;
    }
    char wei1, wei2;
    wei1 = c2[c2.size() - 1];
    wei2 = c4[c4.size() - 1];
    bool f1, f2;
    if (wei1 >= 'A' && wei1 <= 'C') f1 = 0;
    else f1 = 1;
    if (wei2 >= 'A' && wei2 <= 'C') f2 = 0;
    else f2 = 1;

    if (stoi(c1) == stoi(c3)) cout << 1;
    else {cout << "0000"; return 0;}

    if (pai1 == pai2) cout << 1;
    else {cout << "000"; return 0;}

    if (f1 == f2) cout << 1;
    else {cout << "00"; return 0;}

    if (abs(wei1 - wei2) == 1) cout << 1;
    else cout << 0;
    return 0;
}
