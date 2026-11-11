#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a , b;
    string c , d;
    cin >> a >> c >> b >> d;
    if(a == b)
    {
        cout << 1;
    }
    else
    {
        cout << 0;
    }
    string c1 , d1;
    c1 = c.substr(0 , 1);
    d1 = d.substr(0 , 1);
    if(c1 == d1)
    {
        cout << 1;
    }
    else
    {
        cout << 0;
    }
    string c2 , d2;
    c2 = c.substr(1);
    d2 = d.substr(1);
    if(c2 >= "A" || c2 <= "C" && d2 >= "A" || d2 <= "C")
    {
        cout << 1;
        if(c2 == "A" && d2 == "B" || c2 == "B" && d2 == "A" || c2 == "B" && d2 == "C" || c2 == "C" && d2 == "B")
        {
            cout << 1;
        }
        else
        {
            cout << 0;
        }
    }
    else if(c2 >= "D" || c2 <= "F" && d2 >= "D" || d2 <= "F")
    {
        cout << 1;
        if(c2 == "D" && d2 == "F" || c2 == "F" && d2 == "D")
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
        cout << 0 << 0;
    }

    return 0;
}
