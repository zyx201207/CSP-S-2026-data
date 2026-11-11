#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    char a[15],b[15];
    for(int i=1;i<=5;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=5;i++)
    {
        cin>>b[i];
    }
    if(a[1]==b[1]&&a[2]==b[2])
    {
        cout<<1;
    }
    else
    {
        cout<<0<<0<<0<<0;
        return 0;
    }
    if(a[3]==b[3]&&a[4]==b[4])
    {
        cout<<1;
    }
    else
    {
        cout<<0<<0<<0;
        return 0;
    }
    if((a[5]<='C'&&b[5]<='C')||(a[5]>='D'&&b[5]<='D'))
    {
        cout<<1;
    }
    else
    {
        cout<<0<<0;
        return 0;
    }
    if(a[5]-b[5]==1||a[5]-b[5]==-1)
    {
        cout<<1;
    }
    else
    {
        cout<<0;
        return 0;
    }
}
