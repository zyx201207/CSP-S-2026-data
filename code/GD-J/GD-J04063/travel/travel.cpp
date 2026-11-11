#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    string cA,sA,cB,sB;
    cin >> cA >> sA >> cB >> sB;

    if(cA != cB)
    {
        cout << "0000";
        return 0;
    }
    else
    {
        cout << "1";

        if((sA[0] == sB[0]) && (sA[1] == sB[1]))
        {
            cout << "1";

            if((sA[2] >= 'A' && sA[2] <= 'C') && (sB[2] >= 'A' && sB[2] <= 'C'))
            {
                cout << "1";
                if((sA[2] - '0') - (sB[2] - '0') == 1 || (sA[2] - '0') - (sB[2] - '0') == -1)
                {
                    cout << "1";
                    return 0;
                }
                else
                {
                    cout << "0";
                    return 0;
                }
            }
            else if((sA[2] >= 'D' && sA[2] <= 'F') && (sB[2] >= 'D' && sB[2] <= 'F'))
            {
                cout << "11";
                return 0;
            }
            else
            {
                cout << "00";
                return 0;
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
