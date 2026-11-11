#include <bits/stdc++.h>
using namespace std;

string sc1, ss1, sc2, ss2;
char cs1, cs2;
int c1, s1, c2, s2;
int a1, a2, a3, a4;

int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> c1 >> ss1 >> c2 >> ss2;
    s1 = ss1[0]*10 + ss1[1]-'0';
    cs1 = ss1[2];
    s2 = ss2[0]*10 + ss2[1]-'0';
    cs2 = ss2[2];
    if(c1 == c2)
    {
        a1 = 1;
        if(s1 == s2)
        {
            a2 = 1;
            if((cs1 >= 'A' && cs1 <= 'C' && cs2 >= 'A' && cs2 <= 'C') || (cs1 >= 'D' && cs1 <= 'F' && cs2 >= 'D' && cs2 <= 'F'))
            {
                a3 = 1;
                if(abs(cs1 - cs2) <= 1)
                {
                    a4 = 1;
                }
            }
        }
    }
    else
    {
        cout << "0000";
        return 0;
    }
    cout << a1 << a2 << a3 << a4;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
