#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("r", "travel.in", stdin);
	freopen("w", "travel.out", stdout);
    string rcb,xcb,rs,xs;
    cin >> rcb >> rs >> xcb >> xs;
    if(rcb[0]==xcb[0] && rcb[1]==xcb[1])
    {
        cout << "1";
        if(rs[0]==xs[0] && rs[1]==xs[1])
        {
            cout << "1";
            if((rs[2]=='C' && xs[2]=='D') || (rs[2]=='D' && xs[2]=='C'))
                cout << "00";
            else
            {
                cout << "1";
                if(rs[2]+1==xs[2] || rs[2]-1==xs[2])
                    cout<< "1";
            }
        }
        else
            cout << "000";
    }
    else
        cout << "0000";

    return 0;
}
