#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s1,s2,s3,s4;
    cin>>s1>>s2>>s3>>s4;
    if(s1==s3)
    {
        cout<<1;
    }
    else
    {
        cout<<"0000";
        return 0;
    }
    string ss1=s2.substr(0,2),ss2=s4.substr(0,2);
    if(ss1==ss2)
    {
        cout<<1;
    }
    else
    {
        cout<<"000";
        return 0;
    }
    int x1=s2[2]-'A',x2=s4[2]-'A';
    if((x1<3&&x2<3)||(x1>2&&x2>2))
    {
        cout<<1;
    }
    else
    {
        cout<<"00";
        return 0;
    }
    if((x1==x2+1||x2==x1+1)&&(!((x1==3&&x2==2)||(x1==2&&x2==3))))
    {
        cout<<1;
    }
    else
        cout<<0;
    return 0;
}
