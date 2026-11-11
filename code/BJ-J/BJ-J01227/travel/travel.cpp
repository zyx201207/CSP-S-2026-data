#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll rc,xx;
string rs,xs;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> rc >> rs >> xx >> xs;
    bool r,x;
    if (rs[2]>='A' && rs[2]<='C')
    {
        r=1;
    }
    if (xs[2]>='A' && xs[2]<='C')
    {
        x=1;
    }
    if (rc!=xx)
    {
        cout << "0000";
        return 0;
    }
    else
    {
        cout << 1;
        ll a=(rs[0]-'0')*10 + (rs[1]-'0');
        ll b=(xs[0]-'0')*10 + (xs[1]-'0');
        if (a==b)
        {
            cout << 1;
            if (r==x)
            {
                cout << 1;
                ll p=abs(rs[2]-xs[2]);
                if (p==1)
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
            return 0;
        }
    }
    return 0;
}
