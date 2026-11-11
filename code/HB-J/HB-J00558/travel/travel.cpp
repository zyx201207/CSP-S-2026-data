#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,c2,a1,a2;
    string s1,s2,b1,b2;
    cin >> c1 >> s1 >> c2 >> s2;
    a1 = s1[0] * 10 + s1[1];
    a2 = s2[0] * 10 + s2[1];
    b1 = s1[2];
    b2 = s2[2];
    if(c1 == c2 && c1 != 1 && c1 != 16)
        cout << "1";
    else
    {
        cout << "0000";
        return 0;
    }
    if(a1 == a2)
        cout << "1";
    else
    {
        cout << "000";
        return 0;
    }
    if(((b1 == "A" && (b2 == "B" || b2 == "C")) || (b1 == "B" && (b2 == "A" || b2 == "C")) || (b1 == "C" && (b2 == "A" || b2 == "B"))) || ((b1 == "D" && b2 == "F") || b1 == "F" && b2 == "D"))
        cout << "1";
    else
    {
        cout << "00";
        return 0;
    }
    if(((b1 == "A" && b2 == "B") || (b1 == "B" && b2 == "A") || (b1 == "B" && b2 == "C") || (b1 == "C" && b2 == "B") || (b1 == "D" && b2 == "F") || (b1 == "F" && b2 == "D")))
       cout << "1";
    else
        cout << "0";
    return 0;
}
