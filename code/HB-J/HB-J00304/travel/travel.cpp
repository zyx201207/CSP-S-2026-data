#include <bits/stdc++.h>
#define lx long long

using namespace std;
string ca , sa , cb , sb;
bool check1 () {
    for (lx i = 0 ; i < 2 ; i ++) {
        if (ca[i] != cb[i]) return 0;
    }
    return 1;
}
bool check2 () {
    for (lx i = 0 ; i < 2 ; i ++) {
        if (sa[i] != sb[i]) return 0;
    }
    return 1;
}
bool check3 () {
    if (sa[2] == 'A') {
        if (sb[2] == 'B') return 1;
        if (sb[2] == 'C') return 1;
        else return 0;
    }
    else if (sa[2] == 'B') {
        if (sb[2] == 'A') return 1;
        if (sb[2] == 'C') return 1;
        else return 0;
    }
    else if (sa[2] == 'C') {
        if (sb[2] == 'A') return 1;
        if (sb[2] == 'B') return 1;
        else return 0;
    }
    else if (sa[2] == 'D') {
        if (sb[2] == 'F') return 1;
        else return 0;
    }
    else if (sa[2] == 'F') {
        if (sb[2] == 'D') return 1;
        else return 0;
    }
}
bool check4 () {
    if (sa[2] == 'A') {
        if (sb[2] == 'B') return 1;
        else return 0;
    }
    else if (sa[2] == 'B') {
        if (sb[2] == 'A') return 1;
        if (sb[2] == 'C') return 1;
        else return 0;
    }
    else if (sa[2] == 'C') {
        if (sb[2] == 'B') return 1;
        else return 0;
    }
    else if (sa[2] == 'D') {
        if (sb[2] == 'F') return 1;
        else return 0;
    }
    else if (sa[2] == 'F') {
        if (sb[2] == 'D') return 1;
        else return 0;
    }
}
int main () {
    freopen ("travel.in" , "r" , stdin);
    freopen ("travel.out" , "w" , stdout);
    cin >> ca >> sa >> cb >> sb;
    if (check1 ()) cout << "1";
    else {
        cout << "0000";
        return 0;
    }
    if (check2 ()) cout << "1";
    else {
        cout << "000";
        return 0;
    }
    if (check3 ()) cout << "1";
    else {
        cout << "00";
        return 0;
    }
    if (check4 ()) cout << "1";
    else cout << "0";
    return 0;
}
