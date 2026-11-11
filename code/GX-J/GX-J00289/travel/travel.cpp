#include<bits/stdc++.h>
using namespace std;
main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a[10005],b[10005],c[10005],d[10005];
    cin >> a >> b >> c >> d;
    if(a[1] == c[1])
    {
        cout << "1";

        if(b[0] == d[0] && b[1] == d[1])
        {
        cout << "111";
        }
        else
        {
        cout << "000";
        }
    }
    else
    {
        cout << "0000";
    }


    return 0;
    }
