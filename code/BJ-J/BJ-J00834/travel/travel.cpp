#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    string c1, s1, c2, s2;
    cin >> c1 >> s1 >> c2 >> s2;
    int a = c1[1] - '0';
    if (c1[0] > '0') a += 10;
    int b = c2[1] - '0';
    if (c2[0] > '0') b += 10;
    if (a != b)
    {
        cout << "0000" << '\n';
    }
    else
    {
        cout << 1;
        int c = s1[1] - '0';
        if (s1[0] > '0') c += 10;
        int d = s2[1] - '0';
        if (s2[0] > '0') d += 10;
        if (c != d)
        {
            cout << "000" << '\n';
        }
        else
        {
            cout << 1;
            if (s1[2] == 'A' && s2[2] == 'B' || s1[2] == 'B' && s2[2] == 'A' || s1[2] == 'A' && s2[2] == 'C' || s1[2] == 'C' && s2[2] == 'A' || s1[2] == 'B' && s2[2] == 'C' || s1[2] == 'C' && s2[2] == 'B' || s1[2] == 'D' && s2[2] == 'F' || s1[2] == 'F' && s2[2] == 'D')
            {
                cout << 1;
                if (s1[2] == 'A' && s2[2] == 'B' || s1[2] == 'B' && s2[2] == 'A' || s1[2] == 'B' && s2[2] == 'C' || s1[2] == 'C' && s2[2] == 'B' || s1[2] == 'D' && s2[2] == 'F' || s1[2] == 'F' && s2[2] == 'D')
                {
                    cout << 1 << '\n';
                }
                else
                {
                    cout << 0 << '\n';
                }
            }
            else
            {
                cout << "00" << '\n';
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
