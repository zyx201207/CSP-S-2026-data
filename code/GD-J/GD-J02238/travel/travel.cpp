#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

int check,checkk;
int checkz,checkkz;
string numo,numtwo,numt,numf;
cin >> numo >> numtwo >> numt >> numf;
if(numo == numt)
{
    cout << 1;
    if(numtwo[0] == numf[0] && numtwo[1] == numf[1])
    {
        cout << 1;
        if(numtwo[2] <= 'C' && numtwo[2] >= 'A' && numf[2] >= 'A' && numf[2] <= 'C')
        {
            cout << 1;
            check = numtwo[2] - numf[2];
            checkk = abs(check);
            if(checkk == 1)
            {
                cout << 1;
            }
            else
            {
                cout << 0;
            }

        }
        else if(numtwo[2] <= 'F' && numtwo[2] >= 'D' && numf[2] >= 'D' && numf[2] <= 'F')
        {
            cout << 1;
            checkz = numtwo[2] - numf[2];
            checkkz = abs(checkz);
            if(checkkz == 1)
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
            cout << 00;
        }

    }
    else
    {
        cout << 000;
    }


}
else
{
    cout << 0000;
    return 0;
}

    return 0;
}
