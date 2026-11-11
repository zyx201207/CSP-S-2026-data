#include <bits/stdc++.h>
using namespace std;

string s1,s2,s3,s4;

int id(char c)
{
    if(c=='A') return 1;
    if(c=='B') return 1;
    if(c=='C') return 1;
    if(c=='D') return 2;
    if(c=='E') return 2;
}

bool chk1(string s1,string s2,string s3,string s4)
{
    return s1==s3;
}

bool chk2(string s1,string s2,string s3,string s4)
{
    if(s1!=s3) return false;
    return (s2[0]==s4[0]&&s2[1]==s4[1]);
}

bool chk3(string s1,string s2,string s3,string s4)
{
    if(!chk2(s1,s2,s3,s4)) return false;
    return id(s2[2])==id(s4[2]);
}

bool chk4(string s1,string s2,string s3,string s4)
{
    if(!chk3(s1,s2,s3,s4)) return false;
    return abs(s2[2]-s4[2])==1;
}

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>s1>>s2>>s3>>s4;
    cout<<chk1(s1,s2,s3,s4);
    cout<<chk2(s1,s2,s3,s4);
    cout<<chk3(s1,s2,s3,s4);
    cout<<chk4(s1,s2,s3,s4);
    return 0;
}