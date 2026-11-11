#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);

    char c11, c12, s11, s12, s13, c21, c22, s21, s22, s23;
    cin >> c11 >> c12 >> s11 >> s12 >> s13 >> c21 >> c22 >> s21 >> s22 >> s23;

    int a = s13 - 'A' + 1;
    int b = s23 - 'A' + 1;

    if (c11 == c21 && c12 == c22)
    {
        cout << 1;
        if (s11 == s21 && s12 == s22)
        {
            cout << 1;
            if (a <= 3 && b <= 3 || a > 3 && b > 3)
            {
                cout << 1;
                if (a == 1 && b == 3 || a == 3 && b == 1) cout << 0 << endl;
                else cout << 1 << endl;
            }
            else cout << "00" << endl;
        }
        else cout << "000" << endl;
    }
    else cout << "0000" << endl;

    return 0;
}
