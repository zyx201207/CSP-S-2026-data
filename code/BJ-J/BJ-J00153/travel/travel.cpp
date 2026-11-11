#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    long long a, c;
    string b, d;
    cin >> a >> b >> c >> d;
    if (a == c)
    {
        cout << 1;
        if (b[0]+b[1] == d[0]+d[1])
        {
            cout << 1;
            if ((d[2] == 'A' && b[2] == 'B') || (d[2] == 'B' && b[2] == 'A'))
            {
                cout << 1;
                if ((d[2] == 'A' && b[2] == 'B') || (d[2] == 'B' && b[2] == 'A'))
                {
                    cout << 1;
                }
                else if ((d[2] == 'C' && b[2] == 'B') || (d[2] == 'B' && b[2] == 'C'))
                {
                    cout << 1;
                }
                else if ((d[2] == 'D' && b[2] == 'F') || (d[2] == 'F' && b[2] == 'D'))
                {
                    cout << 1;
                }
                else
                {
                    cout << 0;
                }
            }
            else if ((d[2] == 'C' && b[2] == 'B') || (d[2] == 'B' && b[2] == 'C'))
            {
                cout << 1;
                if ((d[2] == 'A' && b[2] == 'B') || (d[2] == 'B' && b[2] == 'A'))
                {
                    cout << 1;
                }
                else if ((d[2] == 'C' && b[2] == 'B') || (d[2] == 'B' && b[2] == 'C'))
                {
                    cout << 1;
                }
                else if ((d[2] == 'D' && b[2] == 'F') || (d[2] == 'F' && b[2] == 'D'))
                {
                    cout << 1;
                }
                else
                {
                    cout << 0;
                }
            }
            else if ((d[2] == 'D' && b[2] == 'F') || (d[2] == 'F' && b[2] == 'D'))
            {
                cout << 1;
                if ((d[2] == 'A' && b[2] == 'B') || (d[2] == 'B' && b[2] == 'A'))
                {
                    cout << 1;
                }
                else if ((d[2] == 'C' && b[2] == 'B') || (d[2] == 'B' && b[2] == 'C'))
                {
                    cout << 1;
                }
                else if ((d[2] == 'D' && b[2] == 'F') || (d[2] == 'F' && b[2] == 'D'))
                {
                    cout << 1;
                }
                else
                {
                    cout << 0;
                }
            }
            else if ((d[2] == 'A' && b[2] == 'C') || (d[2] == 'C' && b[2] == 'A'))
            {
                cout << 1;
                if ((d[2] == 'A' && b[2] == 'B') || (d[2] == 'B' && b[2] == 'A'))
                {
                    cout << 1;
                }
                else if ((d[2] == 'C' && b[2] == 'B') || (d[2] == 'B' && b[2] == 'C'))
                {
                    cout << 1;
                }
                else if ((d[2] == 'D' && b[2] == 'F') || (d[2] == 'F' && b[2] == 'D'))
                {
                    cout << 1;
                }
                else
                {
                    cout << 0;
                }
            }
            else
            {
                cout << 0;
            }
        }
    }
    else
    {
        cout << 0 << 0 << 0 << 0;
    }
    return 0;
}