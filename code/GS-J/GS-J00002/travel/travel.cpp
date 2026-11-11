#include<bits/stdc++.h>

using namespace std;

int main ()
{
    freopen ("travel.in", "r", stdin);
    freopen ("travel.out", "w", stdout);
    string r1, r2, x1, x2;
    cin >> r1 >> r2 >> x1 >> x2;
    if (r1 != x1)
    {
        cout << "0000";
        return 0;
    }
    cout << 1;
    if (r2[0] != x2[0] || r2[1] != x2[1])
    {
        cout << "000";
        return 0;
    }
    else
    {
        cout <<1;
        if (r2[2] <= 'C' && x2[2] >= 'D' || x2[2] <= 'C' && r2[2] >= 'D')
        {
            cout << "00";
            return 0;
        }
        else
        {
            cout << 1;
        }
        if (r2[2] <= 'C')
        {
            if (x2[2] == 'B' || r2[2] == 'B')cout << 1;
            else cout << 0;
        }
        else cout << 1;
    }
    return 0;
}
