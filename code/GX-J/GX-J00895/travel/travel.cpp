#include <iostream>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    char e,f;
    cin >> a >> c >> b >> d;
    if (a[0] == b[0] && a[1] == b[1])
    {
        if (c[0] == d[0] && c[1] == d[1])
        {
            if((c[2] == 'A' && d[2] == 'B') || (c[2] == 'B' && d[2] == 'A') || (c[2] == 'B' && d[2] == 'C') || (c[2] == 'C' && d[2] == 'B') || (c[2] == 'A' && d[2] == 'C') || (c[2] == 'C' && d[2] == 'A') || (c[2] == 'D' && d[2] == 'E') || (c[2] == 'E' && d[2] == 'D') || (c[2] == 'A' && d[2] == 'C') || (c[2] == 'C' && d[2] == 'A'))
            {
                e = c[2],f = d[2];
                if (e - f ==  -1 || e - f ==  1)
                {
                    cout << "1111";
                }
                else
                {
                    cout << "1110";
                }
            }
            else if((c[2] == 'C' && d[2] == 'D') || (c[2] == 'D' && d[2] == 'C'))
            {
                cout << "1101";
            }
            else
            {
                 cout << "1100";
            }
        }
        else
        {
            cout << "1000";
        }
    }
    else cout << "0000";
    return 0;
}
