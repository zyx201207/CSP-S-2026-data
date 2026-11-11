#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,c2,s1,s2;
    cin >> c1 >> s1 >> c2 >> s2;
    if (c1 == c2) cout << 1;
    else
    {
        cout << "0000";
        return 0;
    }
    if (s1[0] == s2[0] && s1[1] == s2[1])cout << 1;
    else
    {

        cout << "000";
        return 0;
    }
    if (s1[2] == 'F') s1[2] = 'E';
    if (s2[2] == 'F') s2[2] = 'E';
    int x = s1[2] - 'A' + 1;
    int y = s2[2] - 'A' + 1;
    if ((x <= 3 && y <= 3) || (x > 3 && y > 3))cout << 1;
    else
    {
        cout << "00";
        return 0;
    }
    if (abs(y - x) == 1) cout << 1;
    else cout << 0;
    return 0;
}
