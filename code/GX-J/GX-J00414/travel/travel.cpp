#include <bits/stdc++.h>
using namespace std;
int a, c;
string b, d;
int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> a >> b >> c >> d;
    //1
    if (a == c) {
        cout << 1;
    } else {
        cout << "0000";
        return 0;
    }
    bool flag = false;
    //2
    if (b[0] == d[0]) {
        if (b[1] == d[1]) {
            cout << 1;
            //3
            if ((b[2] >= 'A' && b[2] <= 'C' && d[2] >= 'A' && d[2] <= 'C') || (b[2] >= 'D' && b[2] <= 'F' && d[2] >= 'D' && d[2] <= 'F')) {
                cout << 1;
            } else {
                cout << 0;
                flag = true;
            }
        } else {
            cout << "00";
            flag = true;
        }
    }
    //4
    if (flag) {
        cout << 0;
    }
    else if ((b[2] == 'C' && d[2] == 'D') || (b[2] == 'D' && d[2] == 'C')) {
        cout << 0;
    }
    else if ((b[2] == 'D' && d[2] == 'F') || (b[2] == 'F' && d[2] == 'D')) {
        cout << 1;
    }
    else if (abs(int(b[2]) - int(d[2])) == 1) {
        cout << 1;
    } else {
        cout << 0;
    }
    return 0;
}
