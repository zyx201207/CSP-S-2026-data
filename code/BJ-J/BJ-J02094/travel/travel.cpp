#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool chk1(string s1,string s2)
{
    char a=s1[2],b=s2[2];
    if(a=='A'||a=='B'||a=='C')
    {
        if(b=='A'||b=='B'||b=='C')return 1;
        return 0;
    }
    if(b=='D'||b=='F')return 1;
    return 0;
}
bool chk2(string s1,string s2)
{
    char a=s1[2],b=s2[2];
    if(a=='A')
    {
        if(b=='B')return 1;
        return 0;
    }
    if(a=='B')
    {
        if(b=='A'||b=='C')return 1;
        return 0;
    }
    if(a=='C')
    {
        if(b=='B')return 1;
        return 0;
    }
    return 1;
}
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2)
    {
        cout<<"0000"<<endl;
        return 0;
    }
    if(s1[0]!=s2[0]||s1[1]!=s2[1])
    {
        cout<<"1000"<<endl;
        return 0;
    }
    if(!chk1(s1,s2))
    {
        cout<<"1100"<<endl;
        return 0;
    }
    if(!chk2(s1,s2))
    {
        cout<<"1110"<<endl;
        return 0;
    }
    cout<<"1111"<<endl;
    return 0;
}
