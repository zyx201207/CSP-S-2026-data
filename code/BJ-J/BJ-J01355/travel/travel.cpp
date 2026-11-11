#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string c1,s1,c2,s2;
    cin >> c1 >> s1 >> c2 >> s2;
    bool flag = true;
    for(int i = 0;i < s1.size();i++)
    {
        if(c1[i] != c2[i])
        {
            flag = false;
        }
    }
    if(flag == false)
    {
        cout << "0000";
        return 0;
    }
    else
    {
        cout << 1;
    }
    bool flag1 = false,flag2 = false;
    if(s1[0] == s2[0] && s1[1] == s2[1]) flag1 = true;
    if(flag1 == false)
    {
        cout << "000";
        return 0;
    }
    else
    {
        cout << 1;
    }
    int k1 = s1[2] - 'A' + 1,k2 = s2[2] - 'A' + 1;
    if(k1 <= 3 && k2 <= 3) flag2 = true;
    if(k1 >= 4 && k2 >= 4) flag2 = true;
    if(flag2 == true) cout << 1;
    else cout << 0;
    if(flag1 == false || flag2 == false)
    {
        cout << 0;
        return 0;
    }
    if(k1 >= 4 && k2 >= 4)
    {
        cout << 1;
        return 0;
    }
    if(k1 == 1 && k2 == 3)
    {
        cout << 0;
        return 0;
    }
    if(k1 == 3 && k2 == 1)
    {
        cout << 0;
        return 0;
    }
    cout << 1;
    return 0;
}