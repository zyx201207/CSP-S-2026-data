#include<bits/stdc++.h>
using namespace std;
int cx1,cx2;
string s1,s2;

bool check(char a,char b)
{
    bool t1,t2;
    if(a=='A'||a=='B'||a=='C')
    {
        t1=1;
    }
    if(b=='A'||b=='B'||b=='C')
    {
        t2=1;
    }
    return t1==t2;
}
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> cx1 >> s1 >> cx2 >> s2;
    if(cx1==cx2)cout << 1;
    else
    {
        cout << "0000";
        return 0;
    }
    if(s1[0]==s2[0] and s1[1]==s2[1])
    {
        cout << 1;
    }
    else
    {
        cout << "000";
        return 0;
    }
    if(check(s1[2],s2[2]))
    {
        cout << 1;
    }
    else
    {
        cout << "00";
        return 0;
    }
    if(s1[2]==s2[2]+1 or s1[2]==s2[2]-1)
    {

        cout << 1;
    }
    else
    {
        cout << "0";
    }
    return 0;
}