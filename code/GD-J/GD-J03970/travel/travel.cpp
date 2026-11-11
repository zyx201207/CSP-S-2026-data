#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","w","std.in");
	freopen("travel.out","r","std.out");
    string c1,c2,c3,c4;
    cin >> c1 >> c2 >> c3 >> c4;
    if (c1 == c3)
    {
        cout << "1";
    }
    else
    {
        cout << "0000";
        return 0;
    }
    if (c2[0] == c4[0] && c2[1] == c4[1])
    {
         cout << "1";
    }
    else
    {
        cout << "000";
        return 0;
    }
    if((c2[2] - 'A') < 3 && (c4[2] - 'A') < 3)
    {
        cout << "1";
    }
    else if(((c2[2] - 'A') < 5 && (c2[2] - 'A') > 2) && ((c4[2] - 'A') < 5 && (c4[2] - 'A') > 2))
    {
        cout << "1";
    }
    else
    {
        cout << "00";
        return 0;
    }
    if (((c2[2] - 'A' + 1) == (c4[2] - 'A')) || ((c2[2] - 'A' - 1) == (c4[2] - 'A')))
    {
        cout << "1";
    }
    else
    {
        cout << "0";
    }
    return 0;
}
