#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin >>a >>b >> c >> d;
    if(a[1] == c[1])
    {
        cout<<1;
    }
    else
    {
        cout<<0;
        cout<<0;
        cout<<0;
        cout<<0;
        return 0;
    }
    if(b[1] == d[1])
    {
        cout<<1;
    }
    else
    {
        cout<<0;
        cout<<0;
        cout<<0;
        return 0;
    }
    if(b[2] == 'A')
    {
        if(d[2] == 'B' || d[2] == 'C')
        {
            cout<<1;
        }
        else
        {
            cout<<0;
            cout<<0;
            return 0;
        }
    }
    else if(b[2] == 'B')
    {
        if(d[2] == 'A' || d[2] =='C')
        {
            cout<<1;
        }
        else
        {
            cout<<0;
            cout<<0;
            return 0;
        }

    }
    else if(b[2] == 'C')
    {
        if(d[2] == 'B' || d[2] =='A')
        {
            cout<<1;
        }
        else
        {
            cout<<0;
            cout<<0;
            return 0;
        }
    }
    else if(b[2] == 'D')
    {
        if(d[2] == 'F')
        {
            cout<<1;
        }
        else
        {
            cout<<0;
            cout<<0;
            return 0;
        }
    }
    else if(b[2] == 'F')
    {
        if(d[2] == 'D')
        {
            cout<<1;
        }
        else
        {
            cout<<0;
            cout<<0;
            return 0;
        }
    }
    if(b[2] - d[2] == 1 || d[2] - b[2] == 1)
    {
        cout<<1;
    }
    else
    {
        cout<<0;
    }
    return 0;
}
