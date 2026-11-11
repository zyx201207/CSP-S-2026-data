#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
int a,b,c,d,x,y;
int main()
{
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>s1>>s2>>s3>>s4;
    if(s1==s3)
    {
        a=1;
    }

    if(s2[0]==s4[0]&&s2[1]==s4[1]&&a==1)
    {
        b=1;
    }

    x=s2[2]-'A';
    y=s4[2]-'A';
    x++;
    y++;
    if((x<=3&&y<=3||x>3&&y>3)&&b==1)
    {
        c=1;
    }

    if(c==1&&abs(x-y)==1)
    {
        d=1;
    }
    cout<<a<<b<<c<<d<<"\n";
    return 0;
}