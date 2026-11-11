#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    char s1,s2;
    int n1,n2,n3,n4;
    cin>>n1>>n2>>s1>>n3>>n4>>s2;
    if(n1==n3)
    {
        cout<<"1";
    }
    else
    {
        cout<<"0000";
        return 0;
    }
    if(n2==n4)
    {
        cout<<"1";
    }
    else
    {
        cout<<"000";
        return 0;
    }
    if(s1=='A'||s2=='A')
    {
        if(s1=='B'||s2=='B')cout<<"11";
        else if(s1=='C'||s2=='C')cout<<"10";
        else cout<<"00";
    }
    else if(s1=='C'||s2=='C')
    {
        if(s1=='B'||s2=='B')cout<<"11";
        else if(s1=='A'||s2=='A')cout<<"10";
        else cout<<"00";
    }
    else if(s1=='D'||s2=='D')
    {
        if(s1=='F'||s2=='F')cout<<"11";
        else cout<<"00";
    }
    return 0;
}
