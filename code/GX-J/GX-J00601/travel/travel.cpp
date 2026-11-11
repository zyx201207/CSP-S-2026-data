#include <iostream>
using namespace std;
string c1, s1, c2, s2;
bool f()
{
    if (((s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C') && (s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C')) || ((s1[2] == 'D' || s1[2] == 'F') && (s2[2] == 'D' || s2[2] == 'F')))
    {
        return 1;
    }
    return 0;
}
bool f2()
{
    if (s1[2] == 'A' && s2[2] == 'B')
    {
        return 1;
    }
    if (s1[2] == 'B' && s2[2] == 'A')
    {
        return 1;
    }
    if (s1[2] == 'B' && s2[2] == 'C')
    {
        return 1;
    }
    if (s1[2] == 'C' && s2[2] == 'B')
    {
        return 1;
    }
    if (s1[2] == 'D' && s2[2] == 'F')
    {
        return 1;
    }
    if (s1[2] == 'F' && s2[2] == 'D')
    {
        return 1;
    }
    return 0;
}
int main()
{
    freopen("travel.in", "r", stdin);
    freoepn("travel.out", "w", stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    if (c1 == c2)
    {
        cout << "1";
        if (s1[0] + s1[1] == s2[0] + s2[1])
        {
            cout << "1";
            if (f())
            {
                cout << "1";
                if (f2())
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
