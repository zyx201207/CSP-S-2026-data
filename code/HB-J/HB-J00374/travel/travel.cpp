#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    int ca, cb, s1, s2;
    char k1, k2;
    cin >> ca >> s1 >> k1 >> cb >> s2 >> k2;
    bool f0 = (ca == cb);
    bool f1 = (s1 == s2);
    bool f2 = (k1 <= 'C' && k2 <= 'C') || (k1 > 'C' && k2 > 'C');
    bool f3 = abs(k1 - k2) == 1;
    f1 &= f0;
    f2 &= f1;
    f3 &= f2;
    cout << f0 << f1 << f2 << f3 << '\n';
    return 0;
}