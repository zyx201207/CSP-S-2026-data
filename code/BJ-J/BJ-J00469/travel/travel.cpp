#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    string a1, a2, b1, b2;
    cin >> a1 >> a2 >> b1 >> b2;
    string ans = "";
    if (a1 == b1)
    {
        ans += '1';
        if (a2[0] == b2[0] && a2[1] == b2[1])
        {

            ans += '1';
            if ((a2[2] >= 'A' && a2[2] <= 'C' && b2[2] >= 'A' && b2[2] <= 'C') || ((a2[2] == 'D' && b2[2] == 'F') || (a2[2] == 'F' && b2[2] == 'D')))
            {
                ans+='1';
                if (a2[2] >= 'A' && a2[2] <= 'C' && b2[2] >= 'A' && b2[2] <= 'C')
                {
                    if (abs(a2[2] - b2[2]) == 1)
                    {
                        ans += '1';
                    }
                    else
                    {
                        ans += '0';
                    }
                }
                else if ((a2[2] == 'D' && b2[2] == 'F') || (a2[2] == 'F' && b2[2] == 'D'))
                {
                    ans +='1';
                }
            }
            else
            {
                ans += "00";
            }
        }
        else
        {
            ans += "000";

        }
    }
    else
    {
        ans  += "0000";
    }
    cout << ans;
    return 0;
}
