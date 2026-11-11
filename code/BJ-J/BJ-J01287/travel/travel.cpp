#include <bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1 == c2) {
        cout << "1";
        if(s1.substr(0, 2) == s2.substr(0, 2)) {
            cout << "1";
            if(('A'<=s1[2]&&s1[2]<='C'&&'A'<=s2[2]&&s2[2]<='C')||('D'<=s1[2]&&s1[2]<='F'&&'D'<=s2[2]&&s2[2]<='F')) {
                cout << "1";
                if(abs(s1[2]-s2[2]) == 1 || (s1[2] == 'D' && s2[2] == 'F') || (s1[2] == 'F' && s2[2] == 'D')) {
                    cout << "1\n";
                } else {
                    cout << "0\n";
                }
            } else {
                cout << "00\n";
            }
        } else {
            cout << "000\n";
        }
    } else {
        cout << "0000\n";
    }
    return 0;
}