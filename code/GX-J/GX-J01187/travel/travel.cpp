#include <bits/stdc++.h>
using namespace std;

string c1,s1,c2,s2;
char ans[10];
int gd1, gd2;

int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);

    cin >> c1 >> s1 >> c2 >> s2;
    if (c1 == c2)
        ans[0] = '1';
    else
        ans[0] = '0';

    string tmp1, tmp2;
    tmp1.push_back(s1[0]);
    tmp1.push_back(s1[1]);
    tmp2.push_back(s2[0]);
    tmp2.push_back(s2[1]);
    if (tmp1 == tmp2 && ans[0] == '1')
        ans[1] = '1';
    else
        ans[1] = '0';

    if (s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C')
        gd1 = 1;
    else
        gd1 = 2;
    if (s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C')
        gd2 = 1;
    else
        gd2 = 2;
    if (gd1 == gd2 && ans[1] == '1' && ans[0] == '1')
        ans[2] = '1';
    else
        ans[2] = '0';

    if (abs(s1[2] - s2[2]) == 1 && !(s1[2] == 'C' && s2[2] == 'D') && !(s2[2] == 'C' && s1[2] == 'D') && ans[1] == '1' && ans[0] == '1')
        ans[3] = '1';
    else
        ans[3] = '0';

    cout << ans[0] << ans[1] << ans[2] << ans[3];

    return 0;
}
