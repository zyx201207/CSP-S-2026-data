#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    string c1,s1,c2,s2;
    bool a = 1;
    cin >> c1 >> s1 >> c2 >> s2;

    if(c1 != "01" && c1 != "16")
    {
        cout << a;
    }
    else
    {
        a = 0;
        cout << a;
    }

    if(s1[1] == s2[1])
    {
        if(s1[0] == s2[0])
        {
            a = 1;
            cout << a;
        }
    }
    else
    {
        a = 0;
        cout << a;
    }

    string a["A","B","C"], b["D","E"];
    for (int i = 1; i <= 3; i++)
    {
        if (s1[2] == a[i] && s2[2] == a[i+1])
        {
            a = 1;
            cout << a;
        }
    }
    return 0;
}
