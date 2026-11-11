#include <bits/stdc++.h>

using namespace std;
struct ticket
{
    string c;
    string z;
};
int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);

    ticket r,x;
    cin >> r.c >> r.z >> x.c >> x.z;
    if (r.c == x.c)
    {
        cout << 1;

        string rp, xp;
        rp += r.z[0];
        rp += r.z[1];
        xp += x.z[0];
        xp += x.z[1];
        if (rp == xp)
        {
            cout << 1;

            bool r_iso, x_iso;
            if (r.z[2] <= 'C') r_iso  = 1;
            else  r_iso = 0;
            if (x.z[2] <= 'C') x_iso = 1;
            else x_iso = 0;

            if (r_iso == x_iso)
            {
                cout << 1;

                if (abs(r.z[2]-x.z[2]) == 1)
                {
                    cout << 1;
                }
                else{
                    cout << 0;
                }
            }
            else
            {
                cout << "00";
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
