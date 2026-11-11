#include <bits/stdc++.h>
using namespace std;
char a[15];
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    for(int i = 1;i <= 10;i++)
    {
        cin >>a[i];
    }


    if(a[1] == a[6] and a[2] == a[7])
    {
        cout << "1";
    }
    else
    {
        cout << "0000";
        return 0;
    }


    if(a[3] == a[8] and a[4] == a[9])
    {
        cout << "1";
    }
    else
    {
        cout << "0";
    }


    if(a[3] == a[8] and a[4] == a[9])
    {
        if(a[5] == 'A' and a[10] == 'B')
        {
            cout << "1";
        }
        if(a[5] == 'B' and a[10] == 'A')
        {
            cout << "1";
        }
        if(a[5] == 'B' and a[10] == 'C')
        {
            cout << "1";
        }
        if(a[5] == 'C' and a[10] == 'B')
        {
            cout << "1";
        }
        if(a[5] == 'D' and a[10] == 'F')
        {
            cout << "1";
        }
        if(a[5] == 'F' and a[10] == 'D')
        {
            cout << "1";
        }

        if(a[5] == 'A' and a[10] == 'C')
        {
            cout << "1";
        }
        if(a[5] == 'C' and a[10] == 'A')
        {
            cout << "1";

        }

    }
    else
    {
        cout << "00";
        return 0;
    }

    if(a[5] == 'A' and a[10] == 'B')
    {
        cout << "1";
    }
    if(a[5] == 'B' and a[10] == 'A')
    {
        cout << "1";
    }
    if(a[5] == 'B' and a[10] == 'C')
    {
        cout << "1";
    }
    if(a[5] == 'C' and a[10] == 'B')
    {
        cout << "1";
    }
    if(a[5] == 'D' and a[10] == 'F')
    {
        cout << "1";
    }
    if(a[5] == 'F' and a[10] == 'D')
    {
        cout << "1";
    }
    else
    {
        cout << "0";
    }
    return 0;
}
