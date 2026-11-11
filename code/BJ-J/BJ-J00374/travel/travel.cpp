#include <bits/stdc++.h>
using namespace std;
string c1;
string s1;
string c2;
string s2;
bool same(string s)
{
    if (s[2]=='A'||s[2]=='B'||s[2]=='C')
    {
        return 1;
    }
    return 0;
}
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if (c1==c2)
    {
        cout<<1;
        if (s1[0]==s2[0]&&s1[1]==s2[1])
        {
            cout<<1;
            if (same(s1)==same(s2))
            {
                cout<<1;
                if (abs(s1[2]-s2[2])==1)
                {
                    cout<<1;
                    return 0;
                }
                cout<<0;
                return 0;
            }
            cout<<"00";
            return 0;
        }
        cout<<"000";
        return 0;
    }
    cout<<"0000";
    return 0;
}
