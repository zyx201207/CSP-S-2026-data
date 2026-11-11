#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a1,a2,b1,b2;
    cin>>a1>>a2>>b1>>b2;
    if(a1[0]==b1[0] and a1[1]==b1[1])
    {
        cout<<1;
    }
    else
    {
        cout<<"0000";
        return 0;
    }
    if(a2[0]==b2[0] and a2[1]==b2[1])
    {
        cout<<1;
    }
    else
    {
        cout<<"000";
        return 0;
    }
    if((a2[2]>='A' and a2[2]<='C') and (b2[2]>='A' and b2[2]<='C'))
    {
        cout<<1;
        if(a2[2]-1==b2[2] or b2[2]-1==a2[2])
        {
            cout<<1;
            return 0;
        }
        else cout<<0;
        return 0;
    }
    else if((a2[2]>='D' and a2[2]<='F') and (b2[2]>='D' and b2[2]<='F'))
    {
        cout<<1;
        if(a2[2]-2==b2[2] or b2[2]-2==a2[2])
        {
            cout<<1;
            return 0;
        }
        else cout<<0;
        return 0;
    }
    else cout<<"00";
    return 0;
}
