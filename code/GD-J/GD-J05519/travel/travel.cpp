#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string taa,tbb,tcc,tdd;
    cin >> taa >> tbb >> tcc >> tdd;
    if (taa == tcc)
        cout << "1";
    else
        cout << "0";
    if (tbb[0] == tdd[0] && tbb[1] == tdd[1])
        cout << "1";
    else
        cout << "0";
    if (tbb[0] == tdd[0] && tbb[1] == tdd[1])
    {
        if (tbb[2] >= 'A' && tbb[2] <= 'C' && tdd[2] >= 'A' && tdd[2] <= 'C')
            cout << "1";
        else
        {
            if (tbb[2] >= 'D' && tbb[2] <= 'E' && tdd[2] >= 'D' && tdd[2] <= 'E')
                cout << "1";
            else
                cout << "0";
        }
    }
    else
        cout << "0";
    if (tbb[0] == tdd[0] && tbb[1] == tdd[1])
    {
        if ((char)(tbb[2]) > (char)(tdd[2]))
        {
            if ((char)(tbb[2]) == (char)(tdd[2]+1))
            {
                if ((char)(tdd[2]) != 'C')
                {
                    cout << "1";
                }
                else
                    cout << "0";
            }
            else
                cout << "0";
        }
        else
        {
            if ((char)(tbb[2]) == (char)(tdd[2]-1))
            {
                if ((char)(tbb[2]) != 'C')
                {
                    cout << "1";
                }
                else
                    cout << "0";
            }
            else
                cout << "0";
        }
    }
    else
        cout << "0";
    return 0;
}
