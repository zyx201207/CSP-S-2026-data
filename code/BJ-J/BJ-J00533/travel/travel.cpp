#include <bits/stdc++.h>

using namespace std;

int main()
{
    string c1, s1, c2, s2;

    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);

    cin >> c1 >> s1 >> c2 >> s2;

    char res1 = '0', res2 = '0', res3 = '0', res4 = '0';

    if(c1 == c2)
    {
        res1 = '1';
    }

    if(res1 == '1' && s1[0] == s2[0] && s1[1] == s2[1])
    {
        res2 = '1';
    }

    if(res1 == '1' && res2 == '1' && (s1[2] >= 'A' && s1[2] <= 'C' && s2[2] >= 'A' && s2[2] <= 'C') || (s1[2] >= 'D' && s1[2] <= 'F' && s2[2] >= 'D' && s2[2] <= 'F'))
    {
        res3 = '1';
    }

    if(res1 == '1' && res2 == '1' && res3 == '1' && abs(s1[2] - s2[2]) == 1)
    {
        res4 = '1';
    }

    cout << res1 << res2 << res3 << res4 << endl;

    return 0;
}