#include <bits/stdc++.h>

using namespace std;

int main()
{
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
string s1,c1,s2,c2;
int a=0,b=0,c=0,d=0;
cin >> s1>>c1>>s2>>c2;
if(s1==s2)
{
    a=1;
}
else
{
    a=0;
}
if(c1[0]==c2[0] && c1[1]==c2[1])
{
    b=1;
}
else
    b=0;
if(((c1[2]=='A' || c1[2]=='B'||c1[2]=='C') &&(c2[2]=='A' || c2[2]=='B'||c2[2]=='C')) || ((c1[2]=='D'||c1[2]=='F')&&(c2[2]=='D'||c2[2]=='F')))
{
    c=1;
}


else
{
    c=0;
}
if(c1[0]==c2[0] && c1[1]==c2[1] && (c1[2]=='A' && c2[2]=='B') || (c1[2]=='B' && c2[2]=='C') || (c1[2]=='D' && c2[2]=='F'))
{
    d=1;
}
else
{
    d=0;
}
cout << a << b << c << d;
    return 0;
}

