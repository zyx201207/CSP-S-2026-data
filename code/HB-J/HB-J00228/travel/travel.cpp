#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
string s1, c1, s2, c2;
int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    if (c1 == c2)
        cout << 1;
    else {
        cout << "0000";
        return 0;
    }

    cout << ((s1[0] == s2[0] && s1[1] == s2[1]) ? 1 : 0);

    cout << (((s1[0] == s2[0] && s1[1] == s2[1]) &&
             (s1[2] < 'D' && s2[2] < 'D') ||
             (s1[2] >= 'D' && s2[2] >= 'D')) ? 1 : 0);

    cout << (
             (s1[0] == s2[0] && s1[1] == s2[1]) &&
             (
              (s1[2] == 'A' && s2[2] == 'B') ||
              (s1[2] == 'B' && s2[2] == 'A') ||
              (s1[2] == 'B' && s2[2] == 'C') ||
              (s1[2] == 'C' && s2[2] == 'B') ||
              (s1[2] == 'D' && s2[2] == 'F') ||
              (s1[2] == 'F' && s2[2] == 'D')
             )
             ? 1 : 0
            );
    return 0;
}
