#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);

    int c1, c2;
    string s1, s2;
    cin >> c1 >> s1 >> c2 >> s2;

    char s11, s12, s13, s21, s22, s23;
    s11 = s1[0];
    s12 = s1[1];
    s13 = s1[2];
    s21 = s2[0];
    s22 = s2[1];
    s23 = s2[2];

    int s1shi = 10 * (s11 - '0') + (s12 - '0');
    int s2shi = 10 * (s21 - '0') + (s22 - '0');

    //cout << endl << s13 << " " << s23 << " " << abs(int(s13 - s23)) <<
    //" " << ('D' <= 'C' && 'A' <= 'C') << endl;

    if (c1 == c2)
    {
        cout << 1;
        if (s1shi == s2shi) //tongyipai
        {
            cout << 1;
            if ('A' <= s13 && s13 <= 'C' && 'A' <= s23 && s23 <= 'C' ||
                 'D' <= s13 && s13 <= 'F' && 'D' <= s23 && s23 <= 'F')  //tongce
            {
                cout << 1;

                if (abs(s13 - s23) == 1)
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
