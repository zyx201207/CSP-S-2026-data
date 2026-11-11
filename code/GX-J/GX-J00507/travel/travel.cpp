#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    long long cx,cx1;
    char zw,zw1;
    cin >> cx >> zw >> cx1 >> zw1;
    if(cx ==cx1)
    {
        cout << "0000";
        return 0;
    }
    if(cx == cx1)
        cout << 1;
    else
        cout << 0;
    if(zw/100 == zw1/100)
        cout <<1;
    else
        cout << 0;
    if(zw%100=='A'||zw%100=='B'||zw%100=='C' && zw1%100=='A'||zw1%100=='B'||zw1%100=='C')
        cout << 0;
    else
    {
        if(zw%100=='D'||zw%100=='F' && zw1%100=='D'||zw1%100=='F')
            cout << 0;
        else
            cout << 1;
    }
    if(zw%100-zw1%100==1 || zw1%100-zw%100==1)
        cout << 0;
    else
        cout << 1;
    return 0;
}
