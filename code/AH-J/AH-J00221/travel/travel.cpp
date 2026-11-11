#include<bits/stdc++.h>

using namespace std;

char c1[20], c2[20], s1[20], s2[20];

int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    scanf("%s%s%s%s", c1 + 1, s1 + 1, c2 + 1, s2 + 1);
    bool ok1, ok2, ok3, ok4;
    ok1 = ok2 = ok3 = ok4 = false;
    if (c1[1] == c2[1] && c1[2] == c2[2])
        ok1 = true;
    if (ok1 && s1[1] == s2[1] && s1[2] == s2[2])
        ok2 = true;
    if (ok2 && ((s1[3] < 'D' && s2[3] < 'D') || (s1[3] > 'C' && s2[3] > 'C')))
        ok3 = true;
    if (ok3 && abs(s1[3] - s2[3]) == 1)
        ok4 = true;
    if (ok1) cout << 1;
    else cout << 0;
    if (ok2) cout << 1;
    else cout << 0;
    if (ok3) cout << 1;
    else cout << 0;
    if (ok4) cout << 1;
    else cout << 0;
    return 0;
}
