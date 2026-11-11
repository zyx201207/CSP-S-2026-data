#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1==c2)
    {
        cout << 1;
        string ans1 = s1.substr(0,2);
        string ans2 = s2.substr(0,2);
        if(ans1==ans2)
        {
            cout << 1;
            if(s1[2]=='D' && s2[2]=='E' || s1[2]=='E' && s2[2]=='D')
            {
                cout << 11;
            }
            else if(s1[2]>='A' && s1[2]<='C' && s2[2]>='A' && s2[2]<='c')
            {
                cout << 1;
                if(s1[2]=='A' && s2[2]=='B' || s1[2]=='B' && s2[2]=='A' || s2[2]=='c' || s1[2]=='C' && s2[2]=='B')
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
                cout << 00;
            }
        }
        else
        {
            cout << 000;
        }
    }
    else
    {
        cout << 0000;
    }
    return 0;
}
