#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string a, b, c, d;
int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> a >> b >> c >> d;
    if(a != c) {cout << "0000\n"; return 0;}
    if(b[0] != d[0] || b[1] != d[1]) {cout << "1000\n"; return 0;}
    if((b[2] == 'A' && d[2] == 'C') || (b[2] == 'C' && d[2] == 'A')) {cout << "1110\n"; return 0;}
    if((b[2] == 'A' && d[2] == 'B') || (b[2] == 'B' && d[2] == 'A') || (b[2] == 'B' && d[2] == 'C') || (b[2] == 'C' && d[2] == 'B') ||
       (b[2] == 'D' && d[2] == 'F') || (b[2] == 'F' && d[2] == 'D')) {cout << "1111\n"; return 0;}
    cout << "1100\n";
    return 0;
}
