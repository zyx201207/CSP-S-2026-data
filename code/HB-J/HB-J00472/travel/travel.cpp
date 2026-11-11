#include <bits/stdc++.h>
using namespace std;
int cnt;
int judge(string c1,string s1,string c2,string s2)
{
    int s=1;
    char a=s1[2];
    char b=s2[2];
    if (c1[0]==c2[0] && c1[1]==c2[1])
        s=1;
    else
        return 0000;
    if (s1[0]==s2[0] && s1[1]==s2[1])
        s=11;
    else
        return 1000;
    if ((a=='A' && b=='B') || (a=='A' && b=='C') || (a=='B' && b=='C') || (a=='D' && b=='F') || (b=='A' && a=='B') || (b=='A' && a=='C') || (b=='B' && a=='C') || (b=='D' && a=='F'))
        s=111;
    else
        return 1100;
    if (!((a=='A' && b=='C') || (b=='A' && a=='C')))
        s=1111;
    else
        return 1110;
    return s;
}
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    int s;
    cnt=judge(c1,s1,c2,s2);
    if (cnt==0)
        cout<<"0000";
    else
        cout<<cnt;

    return 0;
}
