#include<bits/stdc++.h>
using namespace std;
int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin.tie(0);
    ios::sync_with_stdio(false);
    string a;
    string b;
    string c;
    string d;
    cin >> a >> b >> c >> d;
    if(a[0] == c[0] && a[1] == c[1]) {
        cout << "1";
    } else {
        cout << "0000";
        return 0;
    }
    if(b[0] == d[0] && b[1] == d[1]) {
        cout << "1";
    } else {
        cout << "000";
        return 0;
    }
    if((b[2] == 'A' && d[2] == 'D') || (b[2] == 'A' && d[2] == 'F') || (b[2] == 'B' && d[2] == 'D') || (b[2] == 'B' && d[2] == 'F') || (b[2] == 'C' && d[2] == 'D') || (b[2] == 'C' && d[2] == 'F')) {
        cout << "00";
        return 0;
    } else {
        cout << "1";
    }
    if(abs(b[2]-d[2]) == 1) {
        cout << "1";
    } else {
        cout << "0";
    }
    return 0;
}