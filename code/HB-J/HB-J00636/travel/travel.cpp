#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s1,s2,c1,c2;
    cin>>s1>>c1>>s2>>c2;
    if(s1==s2)
    {
        cout<<1;
    }
    else
    {
        cout<<"0000";
        return 0;
    }
    int a=(c1[0]-'0')*10+c1[1]-'0';
    int b=(c2[0]-'0')*10+c2[1]-'0';
    if(a==b)
    {
        cout<<1;
    }
    else
    {
        cout<<"000";
        return 0;
    }
    if((c1[2]=='E'||c1[2]=='F')&&(c2[2]=='E'||c2[2]=='F'))
    {
        cout<<1;
    }
    else if((c1[2]=='A'||c1[2]=='B'||c1[2]=='C')&&(c2[2]=='A'||c2[2]=='B'||c2[2]=='C'))
    {
        cout<<1;
    }
    else
    {
        cout<<"00";
        return 0;
    }
    if(abs(c1[2]-c2[2])==1)
    {
        cout<<1;
    }
    else
    {
        cout<<0;
    }
    return 0;
}
