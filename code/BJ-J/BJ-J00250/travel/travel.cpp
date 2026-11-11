#include <bits/stdc++.h>
using namespace std;
int cas[127];
int check(char a, char b)
{
    if (cas[a] != cas[b])
    {
        return 0;
    }
    if ((a == 'A' && b == 'C') || (a == 'C' && b == 'A'))
    {
        return 1;
    }
    return 2;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    string c1, s1, c2, s2;
    cin >> c1 >> s1 >> c2 >> s2;
    string digit1 = s1.substr(0, 2), digit2 = s2.substr(0, 2);
    cas['A'] = cas['B'] = cas['C'] = 1, cas['D'] = cas['F'] = 2;
    if (c1 != c2)
    {
        cout << "0000" << endl;
    }
    else
    {
        if (digit1 != digit2)
        {
            cout << "1000" << endl;
        }
        else
        {
            int f = check(s1[2], s2[2]);
            if (!f)
            {
                cout << "1100" << endl;
            }
            else if (f == 1)
            {
                cout << "1110" << endl;
            }
            else
            {
                cout << "1111" << endl;
            }
        }
    }
    return 0;
}