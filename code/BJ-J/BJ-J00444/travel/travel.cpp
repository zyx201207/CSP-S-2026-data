#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in" , "r" , stdin);
    freopen("travel.out" , "w" , stdout);
    string c1 , s1 , c2 , s2;
    cin >> c1 >> s1 >> c2 >> s2;
    bool flag = true;
    if (c1 == c2) cout<< 1;
    else
    {
        cout<< 0;
        flag = false;
    }
    if (flag && s1[0] == s2[0] && s1[1] == s2[1]) cout<< 1;
    else
    {
        cout<< 0;
        flag = false;
    }
    if (flag && s1[2] - 'A' + 1 <= 3 && s2[2] - 'A' + 1 <= 3  || s1[2] - 'A' + 1 >= 4 && s2[2] - 'A' + 1 >= 4) cout<< 1;
    else
    {
        cout<< 0;
        flag = false;
    }
    if (flag && (s1[2] - 'A' == s2[2] - 'A' + 1 || s1[2] - 'A' + 1 == s2[2] - 'A')) cout<< 1;
    else cout<< 0;
    return 0;
}
