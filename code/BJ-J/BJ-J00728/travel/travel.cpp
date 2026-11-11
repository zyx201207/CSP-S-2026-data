#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin >> c1 >> s1 >> c2 >> s2;
    bool a[3];
    if(c1 == c2) a[0] = 1;
    else
    {
        cout << "0000";
        return 0;
    }
    if(s1[0] == s2[0] && s1[1] == s2[1]) a[1] = 1;
    else
    {
        cout << "1000" << endl;
        return 0;
    }
    if(s1[2] < 'D' && s2[2] < 'D' || s1[2] >= 'D' && s2[2] >= 'D') a[2] = 1;
    else
    {
        cout <<  "1100" << endl;
        return 0;
    }
    if(abs(s1[2] - s2[2]) == 1) cout << "1111";
    else cout << "1110";
    return 0;
}
