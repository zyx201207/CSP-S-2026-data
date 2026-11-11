#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a1,a2,b1,b2;
    cin >> a1 >> a2 >> b1 >> b2;
    if(a1 == b1)
    {
        cout << 1;
        char x = a2[0],y = b2[0];
        char o = a2[1],p = b2[1];
        char n = a2[2],m = b2[2];
        if (x+o == y+p)
        {
            cout << 1;
            if (n < 'D' && m < 'D' || n > 'C' && n < 'F' && m > 'C' && m < 'F')
            {
                cout  << 1;
                if (n == 'D' && m == 'E' || n == 'E' && m == 'D') cout << 1;
                else if(n == 'B' || m == 'B') cout << 1;
                else cout << 0;
            }
            else cout << "00";

        }
        else cout << "000";

    }
    else cout << "0000";

    return 0;
}
