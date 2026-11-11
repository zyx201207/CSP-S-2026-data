#include<bits/stdc++.h>
using namespace std;
string cr, sr, cx, sx;
int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> cr >> sr >> cx >> sx;
    for(int i = 0; i < 2; i++)
    {
        if(cr[i] != cx[i])
        {
            cout << "0000";
            return 0;
        }
    }
    cout << "1";
    for(int i = 0; i < 2; i++)
    {
        if(sr[i] != sx[i])
        {
            cout << "000";
            return 0;
        }
    }
    cout << "1";
    if(sr[2] <= 'C' && sx[2] >= 'D' || sr[2] >= 'D' && sx[2] <= 'C')
    {
        cout << "00";
        return 0;
    }
    cout << "1";
    if(sr[2] == 'A' && sx[2] == 'B' || sr[2] == 'B' && sx[2] == 'A' || sr[2] == 'C' && sx[2] == 'B' || sr[2] == 'B' && sx[2] == 'C' || sr[2] == 'D' && sx[2] == 'F' || sr[2] == 'F' && sx[2] == 'D')
    {
        cout << "1";
        return 0;
    }
    else
    {
        cout << "0";
        return 0;
    }
    return 0;
}
