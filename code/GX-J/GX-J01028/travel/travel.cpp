#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    string c1,s1,c2,s2;
    int p = 0,cx = 0;
    cin >> c1 >> s1 >> c2 >> s2;
    //cx
    if(c1 == c2)
    {
        cout << "1";
        cx = 1;
    }
    else
    {
        cout << "0";
    }
    //pai
    if(cx == 1)
    {
        if(s1[0] ==  s2[0] && s1[1] == s2[1])
        {
            cout << "1";
            p = 1;
        }
        else
        {
            cout << "0";
        }
    }
    else
    {
        cout << "0";
    }
    //zuowei
    int a = s1[2],b = s2[2];
    if(p == 1)
    {
        if(65 < a <= 67 && b > 67 || 65 < b <= 67 && a > 67)
        {
            cout << "0";
        }
        else
        {
            cout << "1";
        }
    }
    else
    {
        cout << "0";
    }
    //xianglin
    if(p == 1)
    {
        if(a == 67 || a == 68 || b == 67 || b == 68)
        {
            cout << "0";
        }
        else if(a - 1 == b || a + 1 == b || b + 1 == a || b - 1 == a)
        {
            cout << "1";
        }
        else
        {
            cout << "0";
        }
    }
    else
    {
        cout << "0";
    }
    return 0;
}
