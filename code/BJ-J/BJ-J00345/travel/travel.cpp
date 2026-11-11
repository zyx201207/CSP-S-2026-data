#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    string c1, s1, c2, s2;
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1 == c2)
    {
        cout << 1;
        string t1 = s1.substr(0, 2);
        string t2 = s2.substr(0, 2);
        if(t1 == t2)
        {
            cout << 1;
            char k1 = s1[2], k2 = s2[2];
            if(('A' <= k1 && k1 <= 'C' && 'A' <= k2 && k2 <= 'C') || ('D' <= k1 && k1 <= 'F' && 'D' <= k2 && k2 <= 'F'))
            {
                cout << 1;
                if(abs(k1 - k2) == 1)
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
                return 0;
            }
        }
        else
        {
            cout << "000";
            return 0;
        }
    }
    else
    {
        cout << "0000";
        return 0;
    }
    return 0;
}
