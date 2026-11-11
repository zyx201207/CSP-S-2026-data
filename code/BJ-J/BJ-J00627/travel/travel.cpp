#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    string r1, r2, x1, x2;
    cin >> r1 >> r2 >> x1 >> x2;
    if (r1 == x1)
    {
        cout << 1;
        int tmp1 = r2[0] + r2[1], tmp2 = x2[0] + x2[1];
        if (tmp1 == tmp2)
        {
            cout << 1;
            if ('A' <= r2[2] && r2[2] <= 'C')
            {
                if ('A' <= x2[2] && x2[2] <= 'C')
                {
                    cout << 1;
                    if (abs(int(r2[2])-int(x2[2]))==1)
                    {
                        cout << 1;
                    }
                    else
                    {
                        cout << "0";
                    }
                }
                else
                {
                    cout << "00";
                }
            }
            else if('D' <= r2[2] && r2[2] <= 'F')
            {
                if ('D' <= x2[2] && x2[2] <= 'F')
                {
                        cout << "11";
                }
                else
                {
                    cout << "00";
                }
            }
        }
        else
        {
            cout << "000";
        }
    }
    else
    {
        cout << "0000";
    }
    return 0;
}
