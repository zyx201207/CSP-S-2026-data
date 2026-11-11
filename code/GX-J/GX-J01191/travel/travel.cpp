#include<bits/stdc++.h>
using namespace std;
int main()
{
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
string s1,s2,s3,s4;
cin>>s1>>s2>>s3>>s4;
if(s1==s3)
{
    cout<<"1";
}
else
{
    cout<<"0000";
    return 0;
}
if(s2[1]==s4[1] && s2[2]==s4[2])
{
    cout<<"1";
}
else
{
    cout<<"000";
    return 0;
}
if(((s2[3]=='A' || s2[3]=='B' || s2[3]=='C') &&(s4[3]=='A' || s4[3]=='B' || s4[3]=='C')) ||
((s2[3]=='D' || s2[3]=='F')&&(s4[3]=='D' || s4[3]=='F')))
{
    cout<<"1";
}
else
{
    cout<<"00";
    return 0;
}
if(s2[3]==s4[3]+1 || s2[3]+1==s4[3])
{
    cout<<"1";
}
else
{
    cout<<"0";
}
return 0;
}
