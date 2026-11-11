#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string  x1,x2,y1,y2;
    int bj1=0,bj2=0,bj3=0;
    cin>>x1>>x2>>y1>>y2;
    if(x1==y1)
    {
        cout<<1;
        bj1=1;
    }
    else
    {
        cout<<0;
    }
    if(x2[0]==y2[0]&&x2[1]==y2[1]&&bj1==1)
    {
        cout<<1;
        bj2=1;
    }
    else
    {
        cout<<0;
    }
    if(x2[2]>='A'&&x2[2]<='C'&&y2[2]>='A'&&y2[2]<='C'&&bj2==1||
       x2[2]>='D'&&x2[2]<='F'&&y2[2]>='D'&&y2[2]<='F'&&bj2==1)
    {
        cout<<1;
        bj3=1;
    }
    else
    {
        cout<<0;
    }
    if((char)x2[2]+1==y2[2]&&bj3==1||(char)x2[2]-1==y2[2]&&bj3==1)
    {
        cout<<1;
    }
    else
    {
        cout<<0;
    }
    return 0;
}

