#include <bits/stdc++.h>

using namespace std;
int c_1, c_2;
string s_1, s_2, pref_1, pref_2;

int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> c_1 >> s_1 >> c_2 >> s_2;
    bool cargo = c_1 == c_2;
//    cout << cargo;
//    cout << s_1 << s_2;
//    if (cargo)
//    {
    int num_1 = 0;
    int num_2 = 0;
    string pref_1 = s_1;
    string pref_2 = s_2;
    char alp_1, alp_2;
    alp_1 = s_1[2];
    alp_2 = s_2[2];
    pref_1 = pref_1.erase(2);
    pref_2 = pref_2.erase(2);
//    cout << pref_2;
    for (int i = 0; i < 2; i++)
    {
        num_1 += (pref_1[i] - '0') * pow(10, (1-i));
        num_2 += (pref_2[i] - '0') * pow(10, (1-i));
    }
//    cout << num_1 << ' ' << num_2;
    cout << cargo;
    if (cargo)
    {
        if (num_1 == num_2)
        {
            cout << 1;
            if (alp_1 >= 'A' && alp_1 <= 'C' && alp_2 >= 'A' && alp_2 <= 'C')
            {
                cout << 1;
            } else if (alp_1 >= 'D' && alp_1 <= 'F' && alp_2 >= 'D' && alp_2 <= 'F')
            {
                cout << 1;
            } else {
                cout <<0 << 0;
                return 0;
            }
            if (abs(alp_1-alp_2) <= 1)
            {
//                return 1;
                cout << 1;
            } else if ((alp_1 == 'D' && alp_2 == 'F') ||(alp_1 == 'F' && alp_2 == 'D'))
            {
                cout << 1;
            }
            else
            {

                cout << 0;
                return 0;
            }
        } else
        {
            cout << 0 << 0 << 0;
            return 0;
        }



    } else cout << 0 << 0 << 0;
//    pref_1.
//    char[2] pref_1, pref_2;
//    for (int i = 0; i <= 1; i++)
//    {
//        pref_1[i] = s_1[i];
//        pref_2[i] = s_2[i];
//    }
//    cout << pref_1;
//    }


    return 0;
}
