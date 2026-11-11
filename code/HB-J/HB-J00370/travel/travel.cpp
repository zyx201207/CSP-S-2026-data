#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    string a,b,c,d;
    cin >> a >> c >> b >> d;
    if(a==b)
    {
        cout << '1';
        if(c[0]==d[0] && c[1]==d[1])
        {
            cout << '1';
            if(c[2]>'C')
            {
                if(d[2]>'C')
                {
                    cout << "11";
                }
                else
                {
                    cout << "00";
                }
            }
            else
            {
                if((c[2]=='A'&& d[2]=='B')||(c[2]=='B'&&(d[2]=='A'|| d[2]=='C'))||(c[2]=='C'&& d[2]=='B'))
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
}
