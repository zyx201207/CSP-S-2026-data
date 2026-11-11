#include <bits/stdc++.h>
using namespace std;

int main()
{

    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    string c1, c2, c3, c4;
    cin >> c1 >> c2 >> c3 >> c4;

    //same number1
    if (c1 == c3)
    {
        cout << 1;
    }
    else
    {
        cout << 0;
    }

    // same number2
    for (int i = 1; i <= 2; i++)
    {
        char s1 = c2[i];
        char s2 = c4[i];
        if (c1 == c3 && s1 == s2)
        {
            cout << 1;
            break;
        }
        else
        {
            cout << 0;
            break;
        }
    }

    // same number3
    if(c1 == c3 && c2[1] == c4[1] && 'A' <= c2[2]&& c2[2] <= 'C' && 'A' <= c4[2] && c4[2] <= 'C')
    {
        cout << 1;
    }
    else
    {
        cout << 0;
    }

    //same number4
    char s3 = c2[2];
    char s4 = c4[2];
    if (c1 == c3 && 'A' <= c2[2]&& c2[2] <= 'C' && 'A' <= c4[2] && c4[2] <= 'C' || 'D' <= c2[2]&& c2[2] <= 'F' && 'D' <= c4[2] && c4[2] <= 'F')
    {
        if (s3 + 1 == s4)
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
        cout << 0;
    }
    return 0;
}
