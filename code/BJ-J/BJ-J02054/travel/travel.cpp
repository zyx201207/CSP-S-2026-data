#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int num(string s)
{
    int n=s[0]*10+s[1];
    return n;
}
int side(string s)
{
    if(s[2]=='A'||s[2]=='B'||s[2]=='C')return 1;
    return 0;
}
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2)
    {
        cout<<"0000";
        return 0;
    }
    cout<<1;
    if(num(s1)!=num(s2))
    {
        cout<<"000";
        return 0;
    }
    cout<<1;
    if(side(s1)!=side(s2))
    {
        cout<<"00";
        return 0;
    }
    cout<<1;
    if(side(s1)==1&&(s1[2]=='A'&&s2[2]=='C'||s1[2]=='C'&&s2[2]=='A'))
    {
        cout<<0;
        return 0;
    }
    cout<<1;
    return 0;
}

