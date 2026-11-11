#include<bits/stdc++.h>
using namespace std;
int Rx,Ry,Xx,Xy,Rsize,Xsize;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(s1[0]=='0')
    {
        Rx=s1[1]-'0';
    }
    else
    {
        Rx=(s1[0]-'0')*10+(s1[1]-'0');
    }
    if(s2[0]=='0')
    {
        Xx=s2[1]-'0';
    }
    else
    {
        Xx=(s2[0]-'0')*10+(s2[1]-'0');
    }
    if(s1[2]=='A')
    Ry=1;
    else if(s1[2]=='B')
    Ry=2;
    else if(s1[2]=='C')
    Ry=3;
    else if(s1[2]=='D')
    Ry=4;
    else
    Ry=5;//
    if(s2[2]=='A')
    Xy=1;
    else if(s2[2]=='B')
    Xy=2;
    else if(s2[2]=='C')
    Xy=3;
    else if(s2[2]=='D')
    Xy=4;
    else
    Xy=5;
    if(Ry>=1&&Ry<=3)
    Rsize=0;
    else
    Rsize=1;
    if(Xy>=1&&Xy<=3)
    Xsize=0;
    else
    Xsize=1;//
    int count;
    if(c1==c2)
    {
        count=1;
        cout<<1;
    }
    else
    {
        count=0;
        cout<<0;
    }
    if(count==1)
    {
    if(Rx==Xx)
    cout<<1;
    else
    cout<<0;//
    if((Rx==Xx)&&(Rsize==Xsize))
    cout<<1;
    else
    cout<<0;//
    if((Rsize==Xsize)&&(Rx+1==Xx||Rx-1==Xx||Ry+1==Xy||Ry-1==Xy))
    cout<<1;
    else
    cout<<0;//
    }
    else
    cout<<0<<0<<0;
    return 0;
}
