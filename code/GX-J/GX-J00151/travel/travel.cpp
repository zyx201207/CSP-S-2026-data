#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2,num = "";
    cin >> c1 >> s1 >> c2 >> s2;
    if (c1 == c2)
    {
        num += "1";
        if (s1[0] == s2[0] && s1[1] == s2[1])
        {
            num += "1";
            if ((s1[2] <= 'C' && s2[2] <= 'C') || (s1[2] == 'D' || s1[2] == 'F') && (s2[2] == 'D' || s2[2] == 'F'))
            {
                num += "1";
                if ((s1[2] == 'A' && s2[2] == 'B') || (s1[2] == 'B' && s2[2] == 'A') || (s1[2] == 'B' && s2[2] == 'C') || (s1[2] == 'C' && s2[2] == 'B') || (s1[2] == 'D' && s2[2] == 'F') || (s1[2] == 'F' && s2[2] == 'D'))
                {
                    num += "1";
                }
                else num += "0";
            }
            else num += "00";
        }
        else num += "000";
    }
    else num += "0000";
    cout << num;
    return 0;
}
