#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,x,y;
    cin >> a >> b >> x >> y;
    if (a[0] == x[0])
    {
        if (a[1] == x[1])
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
    if (b[0] == y[0])
    {
        if (b[1] == y[1])
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
    if (b[2] == "A" && y[2] == "B")
    {
        cout << "1";
    }
    else if (b[2] == "A" && y[2] == "C")
    {
        cout << "1";
    }
    else if (b[2] == "B" && y[2] == "A")
    {
        cout << "1";
    }
    else if (b[2] == "B" && y[2] == "C")
    {
        cout << "1";
    }
    else if (b[2] == "C" && y[2] == "A")
    {
        cout << "1";
    }
    else if (b[2] == "C" && y[2] == "B")
    {
        cout << "1";
    }
    else if (b[2] == "D" && y[2] == "F")
    {
        cout << "1";
    }
    else if (b[2] == "F" && y[2] == "D")
    {
        cout << "1";
    }
    else
    {
        cout << "0";
    }
    if (b[2] == "A" && y[2] == "B")
    {
        cout << "1";
    }
    else
    {
        cout << "0";
    }
    if (b[2] == "B" && y[2] == "A")
    {
        cout << "1";
    }
    else
    {
        cout << "0";
    }
    if (b[2] == "B" && y[2] == "C")
    {
        cout << "1";
    }
    else
    {
        cout << "0";
    }
    if (b[2] == "C" && y[2] == "B")
    {
        cout << "1";
    }
    else
    {
        cout << "0";
    }
    if (b[2] == "D" && y[2] == "F")
    {
        cout << "1";
    }
    else
    {
        cout << "0";
    }
    if (b[2] == "F" && y[2] == "D")
    {
        cout << "1";
    }
    else
    {
        cout << "0";
    }
    return 0;
}
