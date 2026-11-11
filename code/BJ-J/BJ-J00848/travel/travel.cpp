#include<bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
int f(char c)
{
    if(c=='A'||c=='B'||c=='C') return 1;
    return 0;
}
int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)
    {
        cout<<"1";
    }
    else
    {
        cout<<"0000";
        return 0;
    }
    int x=s1[0]*10+s1[1], y=s2[0]*10+s2[1];
    if(x==y)
    {
        cout<<"1";
    }
    else
    {
        cout<<"000";
        return 0;
    }
    if(f(s1[2])==f(s2[2]))
    {
        cout<<"1";
    }
    else
    {
        cout<<"00";
        return 0;
    }
    char a=s1[2], b=s2[2];
    if(a>b) swap(a, b);
    if((a=='A'&&b=='B')||(a=='B'&&b=='C')||(a=='D'&&b=='F'))
    {
        cout<<"1";
    }
    else
    {
        cout<<"0";
    }
    return 0;
}
