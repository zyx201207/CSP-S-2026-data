#include <bits/stdc++.h>
using namespace std;
void bh2(char n1,char n2)
{
    if(n1=='A')
    {
        if(n2=='B') cout<<"11";
        else if(n2=='C') cout<<"10";
        else cout<<"00";
    }
    else if(n1=='B')
    {
        if(n2=='A'||n2=='C') cout<<"11";
        else cout<<"00";
    }
    else if(n1=='C')
    {
        if(n2=='B') cout<<"11";
        else if(n2=='A') cout<<"10";
        else cout<<"00";
    }
    else if(n1=='D')
    {
        if(n2=='F') cout<<"11";
        else cout<<"00";
    }
    else if(n1=='F')
    {
        if(n2=='D') cout<<"11";
        else cout<<"00";
    }
}
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2) cout<<1;
    else
    {
        cout<<"0000";
        return 0;
    }
    char n1=s1[2],n2=s2[2];
    int a1=(s1[0]-'0'),a2=(s1[1]-'0'),a3=(s2[0]-'0'),a4=(s2[1]-'0');
    int p1=a1*10+a2,p2=a3*10+a4;
    if(p1==p2) cout<<1;
    else
    {
        cout<<"000";
        return 0;
    }
    bh2(n1,n2);
    return 0;
}
