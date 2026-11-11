#include<bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    cout << (c1 == c2) << (c1 == c2 && s1.substr(0, 2) == s2.substr(0, 2)) << (c1 == c2 && s1.substr(0, 2) == s2.substr(0, 2) && (s1[2] < 'D' && s2[2] < 'D' || s1[2] >= 'D' && s2[2] >= 'D')) << (c1 == c2 && s1.substr(0, 2) == s2.substr(0, 2) && (s1[2] < 'D' && s2[2] < 'D' || s1[2] >= 'D' && s2[2] >= 'D') && (abs(s1[2] - s2[2]) == 1 || s1[2] == 'D' && s2[2] == 'F' || s1[2] == 'F' && s2[2] == 'D')) << '\n';
    return 0;
}
