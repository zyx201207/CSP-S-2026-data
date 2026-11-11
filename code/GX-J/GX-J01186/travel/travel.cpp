#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s,s1,s2,s3;
    cin>>s;
    cin>>s1;
    cin>>s2;
    cin>>s3;
    if(s==s2)
    {
        cout<<1;
    }
    else
    {
        cout<<"0000";
        return 0;
    }
    if(s1[0]==s3[0] and s1[1]==s3[1])
        cout<<1;
    else
    {
        cout<<"000";
        return 0;
    }
    if(((s1[2]=='C' or s1[2]=='B' or s1[2]=='A') and  (s3[2]=='C' or s3[2]=='B' or s3[2]=='A')) or ((s1[2]=='D' or s1[2]=='E') and (s3[2]=='D' or s3[2]=='E')))
        cout<<1;
    else
    {
        cout<<"00";
        return 0;
    }
    if((s1[2]=='A' and s3[2]=='B') or (s1[2]=='B' and s3[2]=='A') or (s1[2]=='B' and s3[2]=='C') or
       (s1[2]=='C' and s3[2]=='B') or (s1[2]=='D' and s3[2]=='E') or (s1[2]=='E' and s3[2]=='D'))
        cout<<1;
    else
        cout<<0;
    return 0;
}
