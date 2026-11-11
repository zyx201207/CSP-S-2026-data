#include<bits/stdc++.h>
using namespace std;
int main ()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int x,y;
    string s1,s2;
    cin>>x>>s1>>y>>s2;
    int x1=0,x2=0;
    if(x==y)
    {
        cout<<1;
        x1=1;
    }
    else
    {
        cout<<'0';
    }
    char z1=s1[2],z2=s2[2];
    if(s1[1]==s2[1]&&x1==1)
    {
        cout<<1;
        x2=1;
    }
    else
    {
        cout<<0;
    }
    int x3=0;
    int x4=0;
    if(z1>='A'&&z1<='C'&&z2>='A'&&z2<='C'&&x1==1&&x2==1)
    {
        cout<<1;
        x3=1;
    }
    else
    {
        if(z1>='D'&&z1<='F'&&z2>='D'&&z2<='F'&&x1==1&&x2==1)
        {
            cout<<1;
            x3=1;
        }
        else
        {
            cout<<0;
        }
    }
    if(z1+1==z2||z1-1==z2||z2+1==z1||z2-1==z1)
    {
        x4=1;
    }
    if(x1==1&&x2==1&&x3==1&&x4==1)
    {
        cout<<1;
    }
    else
    {
        cout<<0;
    }


    return 0;
}
