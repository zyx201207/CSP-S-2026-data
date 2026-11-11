#include <bits/stdc++.h>
using namespace std;
string a1,a2,b1,b2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a1>>a2;
    cin>>b1>>b2;
    if(a1==b1)
    {
        cout<<1;
    }
    else{
        for(int i=1;i<=4;i++)
        {
            cout<<0;
        }
        return 0;
    }
    if(a2.substr(0,2)==b2.substr(0,2))
    {
        //cout<<a2.substr(0,2)<<"\n";
        cout<<1;
    }
    else{
        for(int i=1;i<=3;i++)
        {
            cout<<0;
        }
        return 0;
    }
    if((a2[2]<='C'&&b2[2]<='C')||(a2[2]>='D'&&b2[2]>='D'))
    {
        cout<<1;
    }
    else{
        for(int i=1;i<=2;i++)
        {
            cout<<0;
        }
        return 0;
    }
    if(a2[2]+1==b2[2]||a2[2]-1==b2[2])
    {
        cout<<1;
    }
    else{
        cout<<0;
        return 0;
    }
    return 0;
}
