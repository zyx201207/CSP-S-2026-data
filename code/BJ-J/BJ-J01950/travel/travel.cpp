#include <bits/stdc++.h>
using namespace std;

bool f = true;
string c1, s1, c2, s2;

int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    if (c1 == c2 && c1 != "01" && c1 != "16")
        cout << 1;
    else if (c1 != c2){
        cout << "0000";
        return 0;
    }
    else cout << 0;

    if (s1[0] == s2[0] && f == true) f = true;
    else f = false;
    if (s1[1] == s2[1] && f == true) f = true;
    else f = false;
    if (f == true) cout << 1;
    else cout << 0;

    if (f == false || (s1[2] == 'C' && s2[2] == 'D'))  cout << 0;
    else cout << 1;

    if (f == true) {
        if (s1[2] == 'A' && s2[2] == 'B') cout << 1;
        else if (s1[2] == 'B' && s2[2] == 'A') cout << 1;
        else if (s1[2] == 'B' && s2[2] == 'C') cout << 1;
        else if (s1[2] == 'C' && s2[2] == 'B') cout << 1;
        else if (s1[2] == 'D' && s2[2] == 'F') cout << 1;
        else if (s1[2] == 'F' && s2[2] == 'D') cout << 1;
        else cout << 0;
    }
    else cout << 0;
    return 0;
}
