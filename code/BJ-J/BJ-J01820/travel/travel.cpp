#include<bits/stdc++.h>
using namespace std;
int c1, c2;
string s1, s2;
int p1, p2;
char st1, st2;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    p1 = int(s1[0] - '0') * 10 + int(s1[1] - '0');
    p2 = int(s2[0] - '0') * 10 + int(s2[1] - '0');
    st1 = s1[2];
    st2 = s2[2];
    if(c1 == c2)
    {
        cout << 1;
        if(p1 == p2)
        {
            cout << 1;
            if((int(st1 - 'A' < 3) && int(st2 - 'A' < 3)) || (int(st1 - 'A' >= 3) && int(st2 - 'A' >= 3))
            {
                cout << 1;
                if((int(st1 - 'A') - int(st2 - 'A') == 1) || (int(st2 - 'A') - int(st1 - 'A') == 1))
                {
                    cout << 1;
                }
                else
                    cout << 0;
            }
            else
                cout << 00;
        }
        else
            cout << 000;
    }
    else
    {
        cout <<0000;
    }
    return 0;
}
