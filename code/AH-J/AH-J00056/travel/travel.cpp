#include <bits/stdc++.h>
using namespace std;

string c1, c2;
string s1, s2;

bool check(char c) {
    if(c=='A' || c=='B' || c=='C') return 1;
    else return 0;
}

bool check1() {
    if(c1==c2) return 1;
    return 0;
}

bool check2() {
    if(check1() && s1[0]+s1[1] == s2[0]+s2[1]) return 1;
    return 0;
}

bool check3() {
    if(check2() && check(s1[2])==check(s2[2])) return 1;
    return 0;
}

bool check4() {
    if(check3() && (s1[2]==s2[2]+1 || s1[2]+1==s2[2])) return 1;
    return 0;
}

int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    if(check1()) cout<<1;
    else cout<<0;
    if(check2()) cout<<1;
    else cout<<0;
    if(check3()) cout<<1;
    else cout<<0;
    if(check4()) cout<<1;
    else cout<<0;
    fclose(stdin);
    fclose(stdout);
}
