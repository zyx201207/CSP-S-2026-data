#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int sum=1;

void pd4() {
    sum++;
    char r1,r2;
    r1=s1[2];
    r2=s2[2];
    if (r1++ == r2 || r2++ == r1 || r1-- == r2 || r2-- == r1) {
        cout << 1;
    } else {
        cout << 0;
    }
}

void pd3() {
    sum++;
    if (s1[0] == s2[0]) {
        if (s1[1] == s2[1]) {
            if ((s1[2] == 'A' ||s1[2] == 'B' ||s1[2] == 'C') && (s2[2] == 'A' ||s2[2] == 'B' ||s2[2] == 'C')) {
                pd4();
                return;
            } else if ((s1[2] == 'D' ||s1[2] == 'F') && (s2[2] == 'D' ||s2[2] == 'F')) {
                pd4();
                return;
            } else {
                cout << 0;
                return;
            }

        } else {
            cout << 0;
        }
    } else {
        cout <<0;
    }
}

void pd2() {
    sum++;
    if (s1[0] == s2[0]) {
        if (s1[1] == s2[1]) {
            if ((s1[2] == 'A' ||s1[2] == 'B' ||s1[2] == 'C') && (s2[2] == 'A' ||s2[2] == 'B' ||s2[2] == 'C')) {
                cout << 1;
                pd3();
                return;
            } else if ((s1[2] == 'D' ||s1[2] == 'F') && (s2[2] == 'D' ||s2[2] == 'F')) {
                cout << 1;
                pd3();
                return;
            } else {
                cout << 0;
                return;
            }

        } else {
            cout << 0;
        }
    } else {
        cout <<0;
    }
}

void pd1() {
    sum++;
    if (s1[0] == s2[0]) {
        if (s1[1] == s2[1]) {
            cout << 1;
            pd2();
        } else {
            cout << 0;
        }
    } else {
        cout <<0;
    }
}

int main() {
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    cin >>c1 >>s1>>c2>>s2;

    if (c1 == c2) {
        cout << 1;
        pd1();
    } else {
        cout << 0;
    }

    if (4-sum != 0) {
        for (int i=1;i <= 4-sum;i++) cout <<0;
    }

    return 0;
}
