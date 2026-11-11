#include <bits/stdc++.h>
using namespace std;
string a, b, c, d;
int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> a >> b >> c >> d;
    bool s1, s2, s3, s4;
    s1 = (a == c);
    s2 = (b[0] == d[0] && b[1] == d[1]);
    s3 = ((b[2] - 'A' <= 2 && d[2] - 'A' <= 2) || (b[2] - 'A' + 1 > 3 && d[2] - 'A' + 1 > 3));
    s4 = (abs((b[2] - 'A') - (d[2] - 'A')) == 1);
    if (s1) cout << 1;
    else cout << 0;
    if (s1 && s2) cout << 1;
    else cout << 0;
    if (s1 && s2 && s3) cout << 1;
    else cout << 0;
    if (s1 && s2 && s3 && s4) cout << 1;
    else cout << 0;
    return 0;
}
