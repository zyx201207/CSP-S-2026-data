#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    string c1, s1, c2, s2;
    cin >> c1 >> s1 >> c2 >> s2;
    if (c1 == c2) // 同一节车厢
    {
        cout << 1;
        if (s1[0] == s2[0] && s1[1] == s2[1]) // 同一排
        {
            cout << 1;
            bool a = (s1[2] <= 'C'), b = (s2[2] <= 'C');
            if (!(a ^ b)) // 同一侧
            {
                cout << 1;
                if ((s1[2] + 1 == s2[2]) || (s1[2] == s2[2] + 1))
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