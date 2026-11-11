#include<bits/stdc++.h>
using namespace std;
int c1, r1, c2, r2;
char s1, s2;
int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> c1 >> r1 >> s1 >> c2 >> r2 >> s2;
    cout << (c1 == c2 ? 1 : 0);
    cout << (c1 == c2 && r1 == r2 ? 1 : 0);
    cout << (c1 == c2 && r1 == r2 && ((s1 < 'D' && s2 < 'D') || (s1 > 'D' && s2 > 'D')) ? 1 : 0);
    cout << (c1 == c2 && r1 == r2 && abs(s1 - s2) == 1 ? 1 : 0);
    return 0;
}
