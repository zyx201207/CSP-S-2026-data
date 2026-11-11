#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("travel.in.txt", "r", stdin);
    freopen("travel.out.txt", "w", stdout);
    string c1, c2, s1, s2, temp1, temp2;
    cin >> c1 >> s1 >> c2 >> s2;
    temp1 = s1[0];
    temp1 += s1[1];
    temp2 = s2[0];
    temp2 += s2[1];
    if(c1 == c2)
    {
        if(temp1 == temp2)
        {
            if((s1[2] <= 'C' && s2[2] <= 'C') || (s1[2] >= 'D' && s2[2] >= 'D'))
            {
                if((s1[2] - s2[2] == 1) || (s2[2] - s1[2] == 1))
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
