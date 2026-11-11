#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool func(char c)
{
    if(c=='A'||c=='B'||c=='C') return 0;
    else return 1;
}
int f(char c)
{
    if(c>='A'&&c<='C') return c-'A'+1;
    else if(c=='D') return 5;
    else return 6;
}
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2) cout<<1;
    else cout<<0;
    string p1=s1.substr(0,2),p2=s2.substr(0,2);
    if(p1==p2&&c1==c2) cout<<1;
    else cout<<0;
    if(func(s1[2])==func(s2[2])&&p1==p2&&c1==c2) cout<<1;
    else cout<<0;
    if(abs(f(s1[2])-f(s2[2]))==1&&p1==p2&&c1==c2) cout<<1;
    else cout<<0;
    return 0;
}
