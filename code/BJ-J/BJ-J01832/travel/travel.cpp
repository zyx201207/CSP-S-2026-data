#include <bits/stdc++.h>
using namespace std;
int n, m, a[4];
string n1, m1;
int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> n >> n1 >> m >> m1;
    if (n != m) {
        cout << "0000";
        return 0;
    } else {
        a[0] = 1;
    }
    if (n1[0] == m1[0] && n1[1] == m1[1]) {
        a[1] = 1;
    } else {
        cout << "1000";
        return 0;
    }
    if (((n1[2] == 'A' || n1[2] == 'B' || n1[2] == 'C') && (m1[2] == 'A' || m1[2] == 'B' || m1[2] == 'C'))
        || ((n1[2] == 'D' || n1[2] == 'F') && (m1[2] == 'D' && m1[2] == 'F'))) {
        a[2] = 1;
    } else {
        a[2] = 0;
    }
    if ((n1[2] == 'A' || n1[2] == 'B' || n1[2] == 'C') && (m1[2] == 'A' || m1[2] == 'B' || m1[2] == 'C')) {
        if (n1[2] == 'A' && m1[2] == 'B') {
            a[3] = 1;
        } else if (n1[2] == 'B' && m1[2] == 'A') {
            a[3] = 1;
        } else if (n1[2] == 'B' && m1[2] == 'C') {
            a[3] = 1;
        } else if (n1[2] == 'C' && m1[2] == 'B') {
            a[3] = 1;
        } else {
            a[3] = 0;
        }
    }
    if ((n1[2] == 'D' || n1[2] == 'F') && (m1[2] == 'D' || m1[2] == 'F')) {
        if (n1[2] == 'D' && m1[2] == 'F') {
            a[3] = 1;
        } else if (n1[2] == 'F' && m1[2] == 'D') {
            a[3] = 1;
        } else {
            a[3] = 0;
        }
    }
    cout << a[0] << a[1] << a[2] << a[3];
    return 0;
}
