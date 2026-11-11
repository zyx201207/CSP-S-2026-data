#include<bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
bool check(){
    char x = s1[2], y = s2[2];
    if (x == 'A' && y == 'B') return 1;
    if (x == 'B' && (y == 'A' || y == 'C')) return 1;
    if (x == 'C' && y == 'B') return 1;
    if (x == 'D' && y == 'F') return 1;
    if (x == 'F' && y == 'D') return 1;
    return 0;
}
int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> c1 >> s1 >> c2 >> s2;
    if (c1 != c2) cout << "0000";
    else if (s1[0] != s2[0] || s1[1] != s2[1]) cout << "1000";
    else if (!((s1[2] <= 'C' && s2[2] <= 'C') || ('D' <= s1[2] && s1[2] <= 'F' && 'D' <= s2[2] && s2[2] <= 'F'))) cout << "1100";
    else if (!check()) cout << "1110";
    else cout << "1111";
    return 0;
}
