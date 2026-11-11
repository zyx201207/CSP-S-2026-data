#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)
    {
        cout<<1;
    }
    else
    {
       cout<<"0000";
       return 0;
    }
    int x1=s1[0]-'0'+s1[1]-'0',x2=s2[0]-'0'+s2[1]-'0';
    char y1=s1[2],y2=s2[2];
    if(x1==x2)
    {
        cout<<1;
    }
    else
    {
        cout<<"000";
        return 0;
    }
    if(y1>='A'&&y1<='C'&&y2>='A'&&y2<='C')
    {
        cout<<1;
    }
    else if(y1>='D'&&y1<='F'&&y2>='D'&&y2<='F')
    {
        cout<<"11";
        return 0;
    }
    else
    {
        cout<<"00";
        return 0;
    }
    if(abs(y1-y2)==1)
    {
        cout<<1;
    }
    else
    {
        cout<<0;
    }
    return 0;
}
