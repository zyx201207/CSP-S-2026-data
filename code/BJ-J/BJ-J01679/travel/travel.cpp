#include <bits/stdc++.h>
using namespace std;

string s1,s2,s3,s4;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> s1 >> s2 >> s3 >> s4;
    int x1 = s1[0] - '0',x2 = s1[1] - '0',y1 = s3[0] - '0',y2 = s3[1] - '0';
    if(x1 == y1 && x2 == y2)
    {
        cout << 1;
        if(s2[0] == s4[0] && s2[1] == s4[1])
        {
            cout << 1;
            if(s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C')
            {
                if(s4[2] == 'A' || s4[2] == 'B' || s4[2] == 'C')
                {
                    cout << 1;
                    if(s2[2] == 'A' && s4[2] == 'C') cout << 0;
                    else if (s2[2] == 'C' && s4[2] == 'A') cout << 0;
                    else cout << 1;

                }
                else cout << "00" << endl;
            }
            else
            {
                if(s2[2] == 'D' || s4[2] == 'F') cout << 11;
                else if(s2[2] == 'F' || s4[2] == 'D') cout << 11;
                else cout << "00" << endl;
            }
        }
        else cout << "000" << endl;
    }
    else cout << "0000" << endl;
    return 0;
}
