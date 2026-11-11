#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    string ca, cb, ra, rb;
    cin >>ca >>cb >> ra >>rb;
    //cout <<ca <<" " << cb << " " << ra << " " << rb << endl;
    if (ca == ra)
    {
        cout << 1;
        string cpai = cb.substr(0, 2);
        string rpai = rb.substr(0, 2);
        if (cpai == rpai)
        {
            cout << 1;
            char czuo = cb[2];
            char rzuo = rb[2];
            if (czuo == 'D')
            {
                if(rzuo == 'F')
                {
                    cout << 11;
                }
                else
                {
                    cout << "00";
                }
            }
            else if(czuo == 'F')
            {
                if (rzuo == 'D')
                {
                    cout << 11;
                }
                else
                {
                    cout << "00";
                }
            }
            else
            {
                if (rzuo == 'C' || rzuo == 'B' || rzuo == 'A')
                {
                    cout << 1;
                    if (abs(int(rzuo) - int(czuo)) == 1)
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
    return 0;
}
