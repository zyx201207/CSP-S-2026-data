#include <bits/stdc++.h>
using namespace std;
int a1, b1;
string a2, b2;
int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> a1 >> a2 >> b1 >> b2;
    if (a1 == b1) {
        cout << 1;
    }else {
        cout << 0 << 0 << 0 << 0;
        return 0;
    }
    if (a2[0] == b2[0] && a2[1] == b2[1]) {
        cout << 1;
    }else {
        cout << 0 << 0 << 0;
        return 0;
    }
    if ((a2[2] == 'A' && b2[2] == 'B') || (a2[2] == 'C' && b2[2] == 'B') || (a2[2] == 'D' && b2[2] == 'E') || (a2[2] == 'C' && b2[2] == 'A')) {
        cout << 1;
    }else {
        cout << 0 << 0;
        return 0;
    }
    if ((a2[2] == 'A' && b2[2] == 'B') || (a2[2] == 'C' && b2[2] == 'D') || (a2[2] == 'D' && b2[2] == 'E')) {
        cout << 1;
    }else {
        cout << 0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}