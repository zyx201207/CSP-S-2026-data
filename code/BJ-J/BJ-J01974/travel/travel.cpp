#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin >> a >> b >> c >> d;
    for (int i = 0; i <= 1; i++)
    {
        if (a[i] != c[i])
        {
            cout << "0000";
            return 0;
        }
    }
    cout << 1;
    for (int i = 0; i <= 1; i++)
    {
        if (b[i] != d[i])
        {
            cout << "000";
            return 0;
        }
    }
    cout << 1;
    if (b[2] == 'A' || b[2] == 'B' || b[2] == 'C')
    {
        if (d[2] == 'D' || d[2] == 'F')
        {
            cout << "00";
            return 0;
        }
    }

    if (b[2] == 'D' || b[2] == 'F')
    {
        if (d[2] == 'A' || d[2] == 'B' || d[2] == 'C')
        {
            cout << "00";
            return 0;
        }
    }
    cout << 1;
    if (b[2] == 'D' || b[2] == 'F')
    {
        if (b[2] != d[2])
            cout << 1;
        return 0;
    }
    else if ((b[2] == 'A' && d[2] == 'C') || (b[2] == 'C' && d[2] == 'A'))
        cout << 0;
    else
    {
        cout << 1;
    }
    return 0;
}
