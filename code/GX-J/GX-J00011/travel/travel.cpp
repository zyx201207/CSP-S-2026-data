#include<bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
int to_int(const string& pos) {
    return (pos[0] - '0') * 10 + (pos[1] - '0');
}
bool same_ce(const string& pos1, const string& pos2) {
    return (pos1[2] <= 'C' && pos2[2] <= 'C') || (pos1[2] > 'C' && pos2[2] > 'C');
}
int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> c1 >> s1 >> c2 >> s2;
    bool first = (c1 == c2);
    bool second = (first && to_int(s1) == to_int(s2));
    bool third = (second && same_ce(s1, s2));
    bool fourth = (third && abs(s1[2] - s2[2]) == 1);
    cout << first << second << third << fourth;
    return 0;
}
