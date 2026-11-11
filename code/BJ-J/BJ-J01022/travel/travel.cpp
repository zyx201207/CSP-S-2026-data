#include<bits/stdc++.h>
using namespace std;
int c[10] = {1,1,1,2,0,2};
int c2[10] = {1,2,3,5,-10,6};
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,a1,b1;
    cin >> a >> b >> a1 >> b1;
    if(a == a1)
    {
        cout << "1";
        if(b[1] == b1[1] && b[0] == b1[0])
        {
            cout << "1";
            if(c[b[2] - 'A'] == c[b1[2] - 'A'])
            {
                cout << 1;
                if(abs(c2[b[2] - 'A'] - c2[b1[2] - 'A'] ) == 1)
                {
                    cout << 1;
                }
                else
                {
                    cout <<0;
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
