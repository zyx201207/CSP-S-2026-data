#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int rc,rs,xc,xs;
    char rp,xp;
    cin >> rc >> rs >> rp >> xc >> xs >> xp;
    bool rb = (rp == 'A' || rp == 'B' || rp == 'C') ? 1 : 0,xb = (xp == 'A' || xp == 'B' || xp == 'C') ? 1 : 0;
    if (rc != xc)
    {
        cout << "0000";
        return 0;
    }
    else
    {
        cout << 1;
        if (rs != xs)
        {
            cout << "000";
            return 0;
        }
        else
        {
            cout << 1;
            if (rb != xb)
            {
                cout << "00";
                return 0;
            }
            else
            {
                cout << 1;
                if (abs((int)rp - (int)xp) == 1 && (!((rp == 'C' && xp == 'D') || (rp == 'D' && xp == 'C'))))
                    cout << 1;
                else
                    cout << 0;
            }
        }
    }
    return 0;
}
