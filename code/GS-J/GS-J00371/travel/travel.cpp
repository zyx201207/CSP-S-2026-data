#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    char c,s={0},c2,s2={0};//分别表示小 R 的车票上的车厢号、座位号,以及小 X 的车票上的车厢号、座位号。

    cin>>c>>s>>c2>>s2;
    if(c==c2)
    {
        cout<<"1"<<" ";


    }
    else
    {
        cout<<"0"<<" ";
    }
    if(c==c2)
    {
        if(s==s2)
        {
            cout<<"1"<<" ";
        }
        else
        {
            cout<<"0"<<" ";
        }
    }

    return 0;
}
