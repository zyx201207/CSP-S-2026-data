#include <bits/stdc++.h>
using namespace std;
string c1,c2,c3,c4,s,s1;
char a1,a2;
int r1,r2;
int aaa;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>c2>>c3>>c4;
    int lenc2=c2.size()-1;
    int lenc4=c4.size()-1;
    for(int i=1;i<=lenc2;i++)
    {
        s[i]=c2[i];
    }
    for(int i=1;i<=lenc4;i++)
    {
        s1[i]=c4[i];
    }
    a1=c2[c2.size()];
    a2=c4[c4.size()];
    if(c1==c3)
        aaa=1;
    else{
        cout<<"0000";
        return 0;
    }
    for(int i=1;i<=max(lenc2,lenc4);i++)
    {
        if(s[1]==s1[1]&&s[2]==s1[2])
        {
            aaa=11;
        }
        else
        {
            cout<<"1000";
            return 0;
        }
    }
    if(a1==a2)
    {
        aaa=111;
    }
    else

        cout<<"1100";
        return 0;

    if(a1=='A')
        r1=1;
    if(a1=='B')
        r1=2;
    if(a1=='C')
        r1=3;
    if(a1=='D')
        r1=4;
    if(a1=='E')
        r1=5;
    if(a1=='f')
        r1=6;
    if(a2=='A')
       r2=1;
    if(a2=='B')
        r2=2;
    if(a2=='C')
        r2=3;
    if(a2=='D')
        r2=4;
    if(a2=='E')
        r2=5;
    if(a2=='F')
        r2=6;
    if(r1+1==r2&&r1-1==r2)
    {
        aaa=1111;
    }
    else
    {
        cout<<"1110";
        return 0;
    }
    cout<<aaa;
    return 0;
}
