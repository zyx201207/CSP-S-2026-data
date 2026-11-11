#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string c1,s1,c2,s2;
    bool flag,k;
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1[0] == c2[0] && c1[1] == c2[1])
    {
        cout << 1;
    }
    else
    {
        cout << "0000";
        return 0;
    }
    if(s1[0] == s2[0] && s1[1] == s2[1])
    {
        cout << 1;
        flag = true;
    }
    else
    {
        cout << 0;
        flag = false;
    }
    if(flag &&((s1[2] > 'C' && s2[2] > 'c') || (s1[2] <= 'c' && s2[2] <= 'C')))
    {
        cout << 1;
        k = true;
    }
    else
    {
        cout << 0;
        k = false;
    }
    if(abs(s1[2] - s2[2]) ==  1 && k)
    {
        cout << 1;
    }
    else
    {
        cout << 0;
    }
    return 0;
}
