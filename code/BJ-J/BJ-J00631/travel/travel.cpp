#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    bool k1=0,k2=0,k3=0,k4=0;
    if(c1==c2)
    {
        k1=1;
    }
    cout<<k1;
    if(s1[0]==s2[0]&&s1[1]==s2[1]&&k1==1)
    {
        k2=1;
    }
    cout<<k2;
    if((s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F'))
    {
        k3=k2;
    }
    else if((s1[2]!='D'&&s1[2]!='F')&&(s2[2]!='D'&&s2[2]!='F'))
    {
        k3=k2;
    }
    cout<<k3;
    if(abs(int(s2[2]-s1[2]))==1&&k3==1)
    {
        k4=1;
    }
    cout<<k4;
    return 0;
}