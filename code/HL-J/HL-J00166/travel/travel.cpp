#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a;
    string b;
    string c;
    string d;
    cin >> a >> b >> c >> d;
    if (a==c)
    {
        cout << "1";
        if (b[1]==d[1])
        {
            cout << "1";
            if (((b[2]>='A'&&b[2]<='C')&&(d[2]>='A'&&d[2]<='C'))||((b[2]=='D'||b[2]=='F')&&(d[2]=='D'||d[2]=='F')))
            {
                cout << "1";
                if ((b[2]=='A'&&d[2]=='B')||(b[2]=='B'&&d[2]=='C')||(b[2]=='D'&&d[2]=='F'))
                {
                    cout << "1";
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
