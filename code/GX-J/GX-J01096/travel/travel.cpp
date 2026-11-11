#include <bits/stdc++.h>
using namespace std;
string s1,s2,d1,d2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> d1 >> s1 >> d2 >> s2;
    if (d1[1] == d2[1] && d1[0] == d2[0])
    {
        cout << 1;
        if (s1[0]==s2[0] && s1[1]==s2[1])
        {
            cout << 1;
            if (s1[2] >= 'A' && s1[2] <= 'C' && s2[2] >= 'A' && s2[2] <= 'C')
            {
                cout << 1;
                if (s1[2]>s2[2])
                {
                    if (s1[2] - s2[1] == 1)
                    {

                        cout << 1;
                    }
                    else
                    {

                        cout << 0;
                    }
                }
                else if (s1[2]<s2[2])
                {
                    if (s2[2] - s1[2] == 1)
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

                    cout << 0;
                }
            }
            else if (s1[2] >= 'D' && s1[2] <= 'F' && s2[2] >= 'D' && s2[2] <= 'F')
            {
                cout << 1;
                if (s1[2]>s2[2])
                {
                    if (s1[2] - s2[1] == 1)
                    {

                        cout << 1;
                    }
                    else
                    {

                        cout << 0;
                    }
                }
                else if (s1[2]<s2[2])
                {
                    if (s2[2] - s1[1] == 1)
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

                    cout << 0;
                }
            }
            else
            {
                cout << 0 << 0;
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
