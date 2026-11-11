#include <iostream>
#include <cstdio>
using namespace std;
bool qw(char a,char b)
{
    if((a=='A'||a=='B'||a=='C')&&(b=='A'||b=='B'||b=='C')) return 1;
    if((a=='D'||a=='E')&&(b=='D'||b=='E')) return 1;
    return 0;
}
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,c2;
    string s1,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)
    {
        cout<<"1";
    }
    else{
        cout<<"0000";
        return 0;
    }
    if(s1[0]+s1[1]==s2[0]+s2[1])
    {
        cout<<"1";
    }
    else{
        cout<<"000";
        return 0;
    }
    if(qw(s1[2],s2[2]))
    {
        cout<<"1";
    }
    else{
        cout<<"00";
        return 0;
    }
    if(s1[2]==s2[2]+1||s1[2]+1==s2[2])
    {
        cout<<"1";
    }
    else{
        cout<<"0";
    }
    return 0;
}
