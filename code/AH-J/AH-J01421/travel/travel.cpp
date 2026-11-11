#include<bits/stdc++.h>
using namespace std;

int main() {

    freopen("travel.in" ,"r", stdin);
    freopen("travel.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int c1, c2;
    string s1, s2;
    cin >> c1 >> s1 >> c2 >> s2;

    if(c1 == c2) {
        cout << 1;
    } else {
        cout << "0000" << '\n';
        return 0;
    }

    int x = (s1[0] - '0') * 10 + (s1[1] - '0');
    int y = (s2[0] - '0') * 10 + (s2[1] - '0');

    char a = s1[2];
    char b = s2[2];

    bool flag = 0;

    cout << (x == y);

    if(x == y) {
        if((a == 'A' || a == 'B' || a == 'C') && (b == 'A' || b == 'B' || b == 'C')) {
            cout << 1;
            flag = 1;
        } else if((a == 'D' || a == 'F') && (b == 'D' || b == 'F')) {
            cout << 1;
            flag = 1;
        } else {
            cout << 0;
        }
    } else {
        cout << 0;
    }

    if(flag) {
        if((a == 'A' && b == 'B') || (a == 'B' && b == 'A') || (a == 'B' && b == 'C') || (a == 'C' && a == 'B')){
            cout << 1;
        } else if ((a == 'D' && b == 'F') && (a == 'F' && b == 'D')) {
            cout << 1;
        } else {
            cout << 0;
        }
    } else {
        cout << 0;
    }

    cout << '\n';

    return 0;
}
