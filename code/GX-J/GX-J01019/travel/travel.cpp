#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,a1,b1;
    cin >> a >> a1 >>b >> b1;
    int c=(a1[0]-'0')*10+a1[1]-'0';
    int d=(b1[0]-'0')*10+b1[1]-'0';
    char q=a1[2];
    char w=b1[2];
    if(a==b)
        cout << 1;
    else
        cout << 0;
    if(a==b && c==d)
        cout << 1;
    else
        cout << 0;
    if(a==b && c==d && ((q<='C'&& w <='C')||(q>='D'&&w>='D')))
        cout << 1;
    else
        cout << 0;
    if(a==b && ((c==d && (q+1==w || q-1==w) && !((q=='C' && w=='D') || (q=='D' && w=='C'))) || (q==w && (c+1==d||c-1==d))))
        cout << 1;
    else
        cout << 0;
    return 0;
}
