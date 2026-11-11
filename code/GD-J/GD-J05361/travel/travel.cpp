#include <bits/stdc++.h>
using namespace std;
int main()
{
    string c,s,cc,ss;
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> c >> s >> cc >> ss;
    if (c == cc)
    {
        cout << "1";
        if (s[0] == ss[0] && s[1] == ss[1])
        {
            cout << "1";
            if (((ss[2]<='F' && ss[2] >= 'D') && (s[2]<='F' && s[2]>='D')) || ((ss[2]<='C' && ss[2]>='A') && (s[2]<='C' && s[2]>='A')))
            {
                cout << "1";
                if ((ss[2] == 'C' && s[2] == 'D') || (s[2] == 'C' && ss[2] == 'D'))
                {
                    cout << "0";
                }
                else if (ss[2]+1 == s[2] || s[2]+1 == ss[2])
                {
                    cout << "1";
                }
                else
                {
                    cout << "0";
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
