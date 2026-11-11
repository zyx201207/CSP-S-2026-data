#include <bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    if (c1 != c2){
        cout << "0000\n";
        return 0;
    }

    if (c1 == c2) cout << "1";
    else cout << "0";
    string k1 = "", k2 = "";
    k1 = s1.substr(0, 2);
    k2 = s2.substr(0, 2);
    if (k1 == k2) cout << "1";
    else  {
        cout << "000\n";
        return 0;
    }
    k1 = s1.substr(2, 1);
    k2 = s2.substr(2, 1);
    char t1 = k1[0], t2 = k2[0];
    if ('A' <= t1 && t1 <= 'C' && 'A' <= t2 && t2 <= 'C')cout << "1";
    else if ('D' <= t1 && t1 <= 'F' && 'D' <= t2 && t2 <= 'F')cout << "1";
    else  {
        cout << "00\n";
        return 0;
    }
    if ((t1 == 'A' && t2 == 'B') || (t1 == 'B' && t2 == 'C') || (t1 == 'D' && t2 == 'F')) cout << "1";
    else if ((t1 == 'B' && t2 == 'A') || (t1 == 'C' && t2 == 'B') || (t1 == 'F' && t2 == 'D')) cout << "1";
    else cout << "0\n";
    return 0;
}
