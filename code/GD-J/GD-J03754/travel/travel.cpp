#include <bits/stdc++.h>

using namespace std;

string s_1, s_2;

int c_1, c_2;

int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);

    cin >> c_1 >> s_1 >> c_2 >> s_2;

    int sum1 = 0;
    int sum2 = 0;

    sum1 = (s_1[0] - '0') * 10 + (s_1[1] - '0');
    sum2 = (s_2[0] - '0') * 10 + (s_2[1] - '0');

    int id1 = 0;
    int id2 = 0;

    id1 = (s_1[2] - 'A') + 1;
    id2 = (s_2[2] - 'A') + 1;

    if (c_1 == c_2)
    {
        if (sum1 == sum2)
        {
            if ((id1 <= 3 && id2 <= 3) || (id1 >= 4 && id2 >= 4))
            {
                if (abs(id1 - id2) <= 1)
                    cout << "1111";
                else
                    cout << "1110";
            }
            else
                cout << "1100";
        }
        else
            cout << "1000";
    }
    else
        cout << "0000";

    return 0;
}