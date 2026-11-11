#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s1, c1, s2, c2;
    cin >> s1 >> c1 >> s2 >> c2;
    freopen("travel.in", "w", stdin);
    freopen("travel.out", "s", stdout);
    if(s1 == s2)
    {
        if(c1[0] == c2[0] && c2[1] == c1[1])
        {
            if(abs(c1[2] - c2[2]) == 1 )
            {
                if(c2[2] == 'C' && c1[2] == 'D' || c2[2] == 'D' && c1[2] == 'C')
                {
                    cout << 1100;
                    return 0;
                }
                cout << 1111;
            }
            else if(c1[2] <= 'C' && c2[2] <= 'C'){
                cout << 1110;
            }
            else{
                cout << 1100;
            }
        }
        else{
            cout << 1000 << endl;
        }
    }
    else cout << "0000" << endl;
    return 0;
}