#include <bits/stdc++.h>
using namespace std;
string r,x,rseat,xseat;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> r >> rseat >> x >> xseat;
    if(r == x)
    {
        cout << 1;
        if(rseat[0] == xseat[0] && rseat[1] == xseat[1])
        {
            cout << 1;
            if(rseat[2] < xseat[2])
            {
                if((rseat[2] == 'A' && xseat[2] == 'B') || (rseat[2] == 'A' && xseat[2] == 'C') || (rseat[2] == 'B' && xseat[2] == 'C') || (rseat[2] == 'D' && xseat[2] == 'F'))
                {
                    cout << 1;
                    if((rseat[2] == 'A' && xseat[2] == 'B') || (rseat[2] == 'B' && xseat[2] == 'C') || (rseat[2] == 'D' && xseat[2] == 'F')) cout << 1;
                    else cout << 0;
                }
            }
            else if(rseat[2] > xseat[2])
            {
                if((xseat[2] == 'A' && rseat[2] == 'B') || (xseat[2] == 'A' && rseat[2] == 'C') || (xseat[2] == 'B' && rseat[2] == 'C') || (xseat[2] == 'D' && rseat[2] == 'F'))
                {
                    cout << 1;
                    if((xseat[2] == 'A' && rseat[2] == 'B') || (xseat[2] == 'B' && rseat[2] == 'C') || (xseat[2] == 'D' && rseat[2] == 'F')) cout << 1;
                    cout << 0;
                }
            }
            else
            {
                cout << 0 << 0 << 0;
            }
        }
    }
    else cout << 0 << 0 << 0 << 0;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
