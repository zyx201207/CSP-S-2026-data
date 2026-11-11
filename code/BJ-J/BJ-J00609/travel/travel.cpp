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
        cout << "1";

        if(s1[0] == s2[0] && s1[1] == s2[1])
        {
            cout << "1";

            int num1 = 0;
            int num2 = 0;
            char c1 = s1[2];
            char c2 = s2[2];

            if(c1 == 'C' || c1 == 'B' || c1 == 'A')
            {
                num1 = 1;
            }
            if(c2 == 'C' || c2 == 'B' || c2 == 'A')
            {
                num2 = 1;
            }

            if(num1 == num2)
            {
                cout << "1";

                char a = s1[2];
                char b = s2[2];

                if(a > b)
                {
                    swap(a, b);
                }

                if((a == 'A' && b == 'B') || (a == 'B' && b == 'C') || (a == 'D' && b == 'F'))
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
