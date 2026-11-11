#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,c2,c3,c4,s1,s2,x1;
    cin >> c1 >> c2 >> s1 >> s2 >> c3;
    if(c1==s1&&c2==s1)
    {
        cout << "1111";
    }
    if(s1==c3&&s1==c1)
    {
        cout << "1110";
    }
    if(s1==c3&&s1==c4)
    {
        cout << "1100";
    }
    if(s1==s2&&s1==c1)
    {
        cout << "1000";
    }
    if(s1==c1&&x1==c1)
    {
        cout << "0000";
    }
    return 0;
}
