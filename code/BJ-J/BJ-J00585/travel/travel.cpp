#include <bits/stdc++.h>
using namespace std;

int main ()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    char a[20] = {};
    char b[20] = {};


    string rt,rs,xt,xs;
    cin >> rt >> rs >> xt >> xs;

    bool flag = 1;

    for (int i = 1;i <= rs.size();i++)
    {
        a[i] = rs[i-1];
    }
    for (int i = 1;i <= xs.size();i++)
    {
        b[i] = xs[i-1];
    }

    if (rt == xt)
    {
        cout << 1;
    }
    else
    {
        cout << 0;
        flag = 0;
    }

    //Q1

    if (rt != xt)
    {
        cout << 0;
    }
    else
    {

        if (a[1] == b[1] && a[2] == b[2])
        {
            cout << 1;
        }
        else
        {
            cout << 0;
            flag = 0;
        }
    }

    //Q2

    if (flag = 0)
    {
        cout << 0;
    }
    else
    {
        if ((('A' <= a[3] && a[3] <= 'C') && ('A' <= b[3] && b[3] <= 'C')) || (('D' == a[3] || a[3] == 'E') && ('D' == b[3] || b[3] == 'E')))
        {
            cout << 1;
        }
        else
        {
            cout << 0;
            flag = 0;
        }
    }

    //Q3

    if (rs == "01C" && xs == "01A")
    {
        flag = 0;
    }

    if (rs == "01A" && xs == "01C")
    {
        flag = 0;
    }

    if (flag = 0)
    {
        cout << 1;
    }
    else
    {
        cout << 0;
    }


    //Q4

    return 0;
}


//(a[3] >= 'A' && a[3] <= 'C') && (b[3] >= 'A' && b[3] <= 'C') || (a[3] >= 'D' && a[3] <= 'F') && (b[3] >= 'D' && b[3] <= 'F')


/*

if ((('A' <= a[3] && a[3] <= 'C') && ('A' <= b[3] && b[3] <= 'C')) || (('D' == a[3] || a[3] == 'E') && ('D' == b[3] || b[3] == 'E')))
{
    cout << 1;
}
else
{
    cout << 0;
}

*/

/*
if (rt != xt || !(a[1] - '0' == b[1] - '0' && a[2] - '0' == b[2] - '0') == 0)
    {
        cout  << 0;
    }
    else
    {
        if ((('A' <= a[3] && a[3] <= 'C') && ('A' <= b[3] && b[3] <= 'C')) || (('D' == a[3] || a[3] == 'E') && ('D' == b[3] || b[3] == 'E')))
        {
            cout << 1;
        }
        else
        {
            cout << 0;
        }
    }
*/
