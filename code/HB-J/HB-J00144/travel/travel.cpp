#include <bits/stdc++.h>
using namespace std;
void open (string s) {
    string in = s + ".in", out = s + ".out";
    freopen (in.c_str(), "r", stdin);
    freopen (out.c_str(), "w", stdout);
}
typedef long long ll;
string c1, s1, c2, s2;
int main () {
    open ("travel");
    cin >> c1 >> s1;
    cin >> c2 >> s2;
    if (c1 == c2) {
        cout << "1";
        if (s1[0] == s2[0] and s1[1] == s2[1]) {
            cout << "1";
            if (s1.back() - 'A' < 3 and s2.back() - 'A' < 3) {
                cout << "1";
                if (abs(s1.back() - s2.back()) == 1 ) cout << "1";
                else if ((s1.back() == 'D' and s2.back() == 'F')
                    or (s1.back() == 'F' and s2.back() == 'D')) 
                    cout << "1";
                else cout << "0";
                
            } else if (s1.back() - 'A' >= 3 and s2.back() - 'A' >= 3) {
                cout << "1";
                if (abs(s1.back() - s2.back()) == 1 ) cout << "1";
                else if ((s1.back() == 'D' and s2.back() == 'F')
                    or (s1.back() == 'F' and s2.back() == 'D')) 
                    cout << "1";
                else cout << "0";
            } else 
                cout << "00";
        } else 
            cout << "000";
    } else 
        cout << "0000";
    return 0;
}
