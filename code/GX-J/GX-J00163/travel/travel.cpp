#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    ios::sync_with_stdio(false);

    string c1, s1, c2, s2;
    cin >> c1 >> s1 >> c2 >> s2;
    int n1, n2;
    char ch1, ch2;
    n1 = (s1[0] - '0') * 10 + (s1[1] - '0');
    n2 = (s2[0] - '0') * 10 + (s2[1] - '0');
    ch1 = s1[2];
    ch2 = s2[2];

    //1
    cout << (c1 == c2) ? '1' : '0';

    //2
    cout << (c1 == c2 && n1 == n2) ? '1' : '0';

    //3
    if(c1 == c2 && n1 == n2)
    {
        if((('A' <= ch1 && ch1 <= 'C') && ('A' <= ch2 && ch2 <= 'C')) || (('D' <= ch1 && ch1 <= 'F') && ('D' <= ch2 && ch2 <= 'F')))
        {
            cout << '1';
        }
        else
        {
            cout << '0';
        }
    }
    else
    {
        cout << '0';
    }

    //4
    if(c1 == c2 && n1 == n2)
    {
        if((('A' <= ch1 && ch1 <= 'C') && ('A' <= ch2 && ch2 <= 'C')) || (('D' <= ch1 && ch1 <= 'F') && ('D' <= ch2 && ch2 <= 'F')))
        {
            if(abs(ch1 - ch2) == 1 || ('D' <= ch1 && ch1 <= 'F') && ('D' <= ch2 && ch2 <= 'F'))
            {
                cout << '1';
            }
            else
            {
                cout << '0';
            }
        }
        else
        {
            cout << '0';
        }
    }
    else
    {
        cout << '0';
    }

    return 0;
}
