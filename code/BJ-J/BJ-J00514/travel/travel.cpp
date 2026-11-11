
#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("travel.in" , "r" , stdin);
    freopen("travel.out" , "w" , stdout);

    string c1 , s1 , c2 , s2;
    cin >> c1 >> s1 >> c2 >> s2;

    bool f1 = true;
    for (int i = 0;i <= 1;i++)
    {
        if (c1[i] != c2[i])
        {
            f1 = false;
        }
    }
    if (f1)
    {
        cout << 1;
    }
    else
    {
        cout << "0000";
        return 0;
    }
    bool f2 = true;
    for (int i = 0;i <= 1;i++)
    {
        if (s1[i] != s2[i])
        {
            f2 = false;
        }
    }
    if (f2)
    {
        cout << 1;
    }
    else
    {
        cout << "000";
        return 0;
    }
    if (s1[2] == 'A' && s2[2] == 'B' || s1[2] == 'B' && s2[2] == 'A')
    {
        cout << "11";
    }
    else if (s1[2] == 'A' && s2[2] == 'C' || s1[2] == 'C' && s2[2] == 'A')
    {
        cout << "10";
    }
    else if (s1[2] == 'A' && s2[2] == 'D' || s1[2] == 'D' && s2[2] == 'A')
    {
        cout << "00";
    }
    else if (s1[2] == 'A' && s2[2] == 'F' || s1[2] == 'F' && s2[2] == 'A')
    {
        cout << "00";
    }
    else if (s1[2] == 'B' && s2[2] == 'C' || s1[2] == 'C' && s2[2] == 'B')
    {
        cout << "11";
    }
    else if (s1[2] == 'B' && s2[2] == 'D' || s1[2] == 'D' && s2[2] == 'B')
    {
        cout << "00";
    }
    else if (s1[2] == 'B' && s2[2] == 'F' || s1[2] == 'F' && s2[2] == 'B')
    {
        cout << "00";
    }
    else if (s1[2] == 'C' && s2[2] == 'D' || s1[2] == 'D' && s2[2] == 'C')
    {
        cout << "00";
    }
    else if (s1[2] == 'C' && s2[2] == 'F' || s1[2] == 'F' && s2[2] == 'C')
    {
        cout << "00";
    }
    else if (s1[2] == 'D' && s2[2] == 'F' || s1[2] == 'F' && s2[2] == 'D')
    {
        cout << "11";
    }
    return 0;
}
