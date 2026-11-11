#include <iostream>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    string c1, s1, c2, s2;
    cin >> c1 >> s1 >> c2 >> s2;
    // cout << c1 << ' ' << s1 << ' ' << c2 << ' ' << s2 << endl;
    bool flag = 0;
    if(c1 == c2) cout << 1, flag = 1;
    else cout << 0;
    if(flag && s1[0] == s2[0] && s1[1] == s2[1]) cout << 1;
    else cout << 0, flag = 0;
    int a1 = s1[2] - 'C';
    int a2 = s2[2] - 'C';
    if(flag && ((a1 <= 0 && a2 <= 0) || (a1 > 0 && a2 > 0))) cout << 1;
    else cout << 0, flag = 0;
    int cha = abs(s1[2] - s2[2]);
    if(flag && cha == 1) cout << 1;
    else cout << 0;
    return 0;
}
