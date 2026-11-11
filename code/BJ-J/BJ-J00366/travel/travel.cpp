#include <bits/stdc++.h>
using namespace std;

int c1,c2;
string s1,s2;
bool isline(char a,char b)
{
    if(a=='A'&&b=='A')return true;
    if(a=='A'&&b=='B')return true;
    if(a=='A'&&b=='C')return true;
    if(a=='B'&&b=='A')return true;
    if(a=='B'&&b=='B')return true;
    if(a=='B'&&b=='C')return true;
    if(a=='C'&&b=='A')return true;
    if(a=='C'&&b=='B')return true;
    if(a=='C'&&b=='C')return true;
    if(a=='D'&&b=='D')return true;
    if(a=='D'&&b=='E')return true;
    if(a=='E'&&b=='D')return true;
    if(a=='E'&&b=='E')return true;
    return false;
}
bool near(char a,char b)
{
    if(a=='F'&&b=='D'||a=='D'&&b=='F')
    {
        return true;
    }
    if(a=='B'&&b=='C'||a=='C'&&b=='B')return true;
    if(a=='A'&&b=='B'||a=='B'&&b=='A')return true;
    return false;
}
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    cin>>c1>>s1>>c2>>s2;
    char a=s1[2];
    char b=s2[2];
    int a1=0,b1=0,c3=0;
    if(c1==c2)
    {
        a1=1;
        cout<<1;
    }
    else{
        cout<<0;
    }
    if(a1==1&&s1[0]==s2[0]&&s1[1]==s2[1])
    {
        b1=1;
        cout<<1;
    }
    else cout<<0;
    if(b1==1&&isline(a,b))
    {
        c3=1;
        cout<<1;
    }
    else cout<<0;
    if(c3==1&&near(a,b))
    {
        cout<<1;
    }
    else cout<<0;
    return 0;
}
