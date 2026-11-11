#include <bits/stdc++.h>

using namespace std;

string c, s, c2, s2;

int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);

    cin >> c >> s >> c2 >> s2;
    //cout << c << s << c2 << s2 << endl;
    //cout << c.size() << s.size() << c2.size() << s2.size() << endl;

    if(c[0] == c2[0] && c[1] == c2[1])
    {
        cout << "1";
        if(s[0] == s2[0] && s[1] == s2[1] )
        {
            cout << "1";
            if((s[2] == 'D' && s2[2] == 'F') || (s[2] == 'F' && s2[2] == 'D') || (s[2] == 'A' &&(s2[2] == 'B'|| s2[2] == 'C')) || (s[2] == 'B' && (s2[2] == 'A' || s2[2] == 'C')) || (s[2] == 'C' && (s2[2] == 'A' || s2[2] == 'B')))
            {
                cout << "1";
                 if((s[2] == 'D' && s2[2] == 'F') || (s[2] == 'F' && s2[2] == 'D') || (s[2] == 'A' && s2[2] == 'B') || (s[2] == 'B' && s2[2] == 'C') || (s[2] == 'B' && s2[2] == 'A') || (s[2] == 'C' && s2[2] == 'B'))
                {
                    cout << "1";
                }
                else cout << "0";
            }
            else cout << "00";
        }
        else cout << "000";
    }
    else cout << "0000";

    //if((s[2] == 'D' && s2[2] == 'F') || (s[2] == 'F' && s2[2] == 'D') || (s[2] == 'A' && s2[2] == 'B') || (s[2] == 'B' && s2[2] == 'C') || (s[2] == 'B' && s2[2] == 'A') || (s[2] == 'C' && s2[2] == 'B'))
    //{
        //cout << "1";
    //}
    //else cout << "0";
    return 0;
}
