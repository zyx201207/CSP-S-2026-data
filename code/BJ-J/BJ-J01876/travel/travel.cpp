#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
string c1, s1, c2, s2;
bool check1(char a, char b) {
    if(a <= 'C' && b >= 'D') return false;
    if(a >= 'D' && b <= 'C') return false;
    return true;
}
bool check2(char a, char b) {
    char c = min(a, b), d = max(a, b);
    if(c == 'A' && d == 'B') return true;
    if(c == 'B' && d == 'C') return true;
    if(c == 'D' && d == 'F') return true;
    return false;
}
int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    bool f1 = (c1 == c2);
    bool f2 = f1 && (s1[0] == s2[0] && s1[1] == s2[1]);
    bool f3 = f2 && check1(s1[2], s2[2]);
    bool f4 = f2 && check2(s1[2], s2[2]);
    cout << f1 << f2 << f3 << f4 << "\n";
    return 0;
}