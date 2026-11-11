#include <bits/stdc++.h>
using namespace std;

struct zuo {
    char c;
    int i;
} zuo1, zuo2;

int che1, che2;
string zu1, zu2;

zuo split_zuo(string zu) {
    zuo ret;
    ret.i = (zu[0] - '0') * 10 + (zu[1] - '0');
    ret.c = zu[2];
    return ret;
}

void tc(char za, char zb) {
    if (za > zb) {
        swap(za, zb);
    }
    if ((za == 'A' && zb == 'B') || (za == 'A' && zb == 'C') || (za == 'B' && zb == 'C') ||
        (za == 'D' && zb == 'F')) {
            cout << 1;
            cout << !(za == 'A' && zb == 'C');
    } else {
        cout << "00";
    }
    return ;
}

int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> che1 >> zu1 >> che2 >> zu2;
    zuo1 = split_zuo(zu1);
    zuo2 = split_zuo(zu2);
    if (che1 == che2) {
        cout << 1;
        if (zuo1.i == zuo2.i) {
            cout << 1;
            tc(zuo1.c, zuo2.c);
        } else {
            cout << "000";
        }
    } else {
        cout << "0000";
    }
    return 0;
}