#include <bits/stdc++.h>
using namespace std;

int c1, c2;
string s1, s2;

int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    bool ans1 = (c1 == c2);
    bool ans2 = (ans1 && (s1[0] + s1[1]) == (s2[0] + s2[1]));
    bool ans3 = (ans1 && ans2 && (((s1[2] == 'A') && ((s2[2] == 'B') || (s2[2] == 'C'))) || ((s1[2] == 'B') && ((s2[2] == 'A') || (s2[2] == 'C'))) || ((s1[2] == 'C') && ((s2[2] == 'B') || (s2[2] == 'A'))) || ((s1[2] == 'D') && (s2[2] == 'F')) || ((s1[2] == 'F') && (s2[2] == 'D'))));
    bool ans4 = (ans1 && ans2 && ans3 && (((s1[2] == 'A') && (s2[2] == 'B')) || ((s1[2] == 'B') && ((s2[2] == 'A') || (s2[2] == 'C'))) || ((s1[2] == 'C') && (s2[2] == 'B')) || ((s1[2] == 'D') && (s2[2] == 'F')) || ((s1[2] == 'F') && (s2[2] == 'D'))));
    cout << ans1 << ans2 << ans3 << ans4 << endl;
    return 0;
}