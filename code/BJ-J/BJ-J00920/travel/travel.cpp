#include <bits/stdc++.h>
using namespace std;
int ra, rb, ca, cb;
string s;
char a, b;
int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> s;
    ca = stoi(s);
    cin >> s;
    ra = stoi(s.substr(0, 2));
    a = s.back();
    cin >> s;
    cb = stoi(s);
    cin >> s;
    rb = stoi(s.substr(0, 2));
    b = s.back();
    if (ca == cb) cout << 1;
    else cout << 0;
    if (ca == cb && ra == rb) cout << 1;
    else cout << 0;
    if (ca == cb && ra == rb && (((a == 'A' || a == 'B' || a == 'C') && (b == 'A' || b == 'B' || b == 'C')) || ((a == 'D' || a == 'F') && (b == 'D' || b == 'F'))))
    {
        cout << 1;
        if (b == 'F') b = 'E';
        if (a == 'F') a = 'E';
        if (abs(a - b) == 1) cout << 1;
        else cout << 0;
    }
    else cout << "00";
    return 0;
}
// 08:53 11:54