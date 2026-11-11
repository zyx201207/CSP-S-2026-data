#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    int a, b;
    string s, z;
    cin >> a >> s >> b >> z;
    if(a == b)
    {
        cout << 1;
        int x, y;
        x = (s[0] - '0') * 10 + (s[1] - '0');
        y = (z[0] - '0') * 10 + (z[1] - '0');
        if(x == y)
        {
            cout << 1;
            if((s[2] == 'D' && z[2] == 'F') || (s[2] == 'A' && z[2] == 'B') || (s[2] == 'A' && z[2] == 'C') || (s[2] == 'B' && z[2] == 'C') || (s[2] == 'F' && z[2] == 'D') || (s[2] == 'B' && z[2] == 'A') || (s[2] == 'C' && z[2] == 'A') || (s[2] == 'C' && z[2] == 'B'))
                cout << 1;
            else
                cout << 0;
            if((s[2] == 'D' && z[2] == 'F') || (s[2] == 'A' && z[2] == 'B') || (s[2] == 'B' && z[2] == 'C') || (s[2] == 'F' && z[2] == 'D') || (s[2] == 'B' && z[2] == 'A') || (s[2] == 'C' && z[2] == 'B'))
                cout << 1;
            else
                cout << 0;
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
