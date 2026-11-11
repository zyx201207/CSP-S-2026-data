#include <iostream>
using namespace std;
int main()
{
    freopen("travel.in","r","std");
    freopen("travel.out","w","std");
    string a, b,c,d;
    cin >> a >> b >> c >> d;
    if (a == c)
    {
        cout << 1;
    }
    if (b[:2] == d[:2])
    {
        cout << 1;
        if ((b[-1] == 'C' && d[-1] == 'D') || (b[-1] == 'D' && d[-1] == 'C'))
        {
             cout << 0;
        }
        else
        {
            cout << 1;
            if ((b[-1] == 'A' && d[-1] == 'B') || (b[-1] == 'B' && d[-1] == 'C') || (b[-1] == 'D' && d[-1] == 'E')
            {
                cout << 1;
            }
            else
            {
                cout << 0;
            }
        }
    }
    else
    {
        cout << "000";
    }
    return 0;
}
