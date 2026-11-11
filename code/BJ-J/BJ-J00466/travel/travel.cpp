#include<bits/stdc++.h>
using namespace std;
int a,b;
string c1,s1,c2,s2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> c1 >> s1 >> c2 >>s2;
    if(c1 == c2)
    {
        cout << 1;
        if(s1.substr(0,2) == s2.substr(0,2))
        {
            cout << 1;
            a = s1[2] - 64;
            b = s2[2] - 64;
            if((a > 3 && b < 4) || (a < 4 && b > 3))
            {
                cout << 0 << 0;
            }
            else
            {
                cout << 1;
                if(abs(a - b) == 1)
                {
                    cout << 1;
                }
                else
                {
                    cout << 0;
                }
            }

        }
        else
        {
            cout << 0 << 0 << 0;
        }
    }
    else
    {
        cout << 0 << 0 << 0 << 0;
    }
    return 0;
}