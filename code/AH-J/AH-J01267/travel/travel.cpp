#include<bits/stdc++.h>
using namespace std;
string c1,c2;
string s1,s2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>c2>>s1>>s2;
    if(c1!=s1)
    {
        cout<<"0000";
        return 0;
    }
    cout<<1;
    if(c2[0]!=s2[0]||c2[1]!=s2[1])
    {
        cout<<"000";
        return 0;
    }
    cout<<1;
    char a,b;
    a=c2[2];
    b=s2[2];
    if((a=='A'||a=='B'||a=='C')&&(b=='D'||b=='F'))
    {
        cout<<"00";
        return 0;
    }
    if((a=='D'||a=='F')&&(b=='A'||b=='B'||b=='C'))
    {
        cout<<"00";
        return 0;
    }
    cout<<1;
    if(a==b+1||b==a+1)
    {
        cout<<1;
    }
    else
    {
        cout<<0;
    }
    return 0;
}
