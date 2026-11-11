#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,z1,c2,z2;
    cin >> c1 >> z1 >> c2 >> z2;
    if (c1 != c2) {
        cout << "0000";
        return 0;
    }
    int f = 1;
    int x = 0;
    for (int i = 0;i <= 2;i++) {
        if (z1[i] != z2[i] && i < 2) {
            f = 0;
        }
        if (z1[i] >= 'A' && z1[i] <= 'C') {
            x++;
        }
        if (z2[i] >= 'A' && z2[i] <= 'C') {
            x++;
        }
    }
    if (f == 0) {
        cout << "1000";
        return 0;
    }
    if (x == 1) {
        cout << "1100";
        return 0;
    }
    if (x == 2) {
        if (z2[2] == 'A' && z1[2] == 'B' || z1[2] == 'A' && z2[2] == 'B' || z1[2] == 'B' && z2[2] == 'C' || z2[2] == 'B' && z1[2] == 'C') {
            cout << "1111";
        } else {
            cout << "1110";
        }
    } else {
        cout << "1111";
    }
    return 0;
}
