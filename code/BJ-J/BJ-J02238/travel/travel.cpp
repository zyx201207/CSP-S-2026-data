#include <bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
bool flag = true;
bool tc(char a, char b) {
    bool la = false, lb = false;
    if(a == 'A' || a == 'B' || a == 'C') {
        la = true;
    }
    if(b == 'A' || b == 'B' || b == 'C') {
        lb = true;
    }
    if(la == lb) {
        return true;
    }
    else {
        return false;
    }
}
int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1 == c2) {
        printf("1");
    }
    else {
        printf("0");
        flag = false;
    }
    if(flag && s1[0] == s2[0] && s1[1] == s2[1]) {
        printf("1");
    }
    else {
        printf("0");
        flag = false;
    }
    if(flag && tc(s1[2], s2[2])) {
        printf("1");
    }
    else {
        printf("0");
        flag = false;
    }
    if(flag && (s1[2] - 1 == s2[2] || s1[2] + 1 == s2[2])) {
        printf("1\n");
    }
    else {
        printf("0\n");
    }
    return 0;
}
