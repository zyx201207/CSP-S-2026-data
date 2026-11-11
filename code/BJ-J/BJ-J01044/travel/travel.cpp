#include <bits/stdc++.h>
using namespace std;

string c1, s1, c2, s2;
int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> c1 >> s1 >> c2 >> s2;
    int kind1, kind2;
    if(s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C') kind1 = 0;
    else kind1 = 1;
    if(s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C') kind2 = 0;
    else kind2 = 1;
    if(c1 == c2) cout << 1;
    else cout << 0;
    if(c1 == c2 && s1[0] == s2[0] && s1[1] == s2[1]) cout << 1;
    else cout << 0;
    if(c1 == c2 && s1[0] == s2[0] && s1[1] == s2[1] && kind1 == kind2) cout << 1;
    else cout << 0;
    if(c1 == c2 && s1[0] == s2[0] && s1[1] == s2[1] && kind1 == kind2 && abs(int(s1[2] - s2[2])) == 1) cout << 1;
    else cout << 0;
    return 0;
}
