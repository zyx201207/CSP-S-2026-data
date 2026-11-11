#include<bits/stdc++.h>
using namespace std;
int a1,a2,b1,b2;
char a3,b3;
bool bb1,bb2,bb3;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a1>>a2>>a3>>b1>>b2>>b3;
    bb1=0;bb2=0;bb3=0;
    if(a1==b1)
    {
        cout<<1;
        bb1=1;
    }
    else cout<<0;
    if(a2==b2 && bb1)
    {
        cout<<1;
        bb2=1;
    }
    else cout<<0;
    if(bb2)
    {
        if(a3<'D' && b3<'D')
        {
            cout<<1;
            bb3=1;
        }
        else if(a3>'C' && b3>'C')
        {
            cout<<1;
            bb3=1;
        }
        else cout<<0;
    }
    else cout<<0;
    if(bb3)
    {
        if(a3-b3==1 || a3-b3==-1) cout<<1;
        else cout<<0;
    }
    else cout<<0;
    return 0;
}
